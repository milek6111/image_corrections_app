#include "GUIMyFrame1.h"


GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent) {
	//controls will be enabled when we load image
	disableButtons();
}

void GUIMyFrame1::Load_File_ButtonOnButtonClick(wxCommandEvent& event) {
	wxFileDialog openFileDialog(this, "Choose a file", "", "", "Image files (*.png;*.jpg)|*.png;*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxPNGHandler);
	wxImage image;
	FREE_IMAGE_FORMAT fif;
	{
		wxLogNull logNo;
		if (!image.LoadFile(openFileDialog.GetPath())) {
			wxMessageBox(_("Sprobuj ponownie zaladowac obrazek"));
			return;
		}
		processingFullSizeImage = image.Copy();
		fif = FreeImage_GetFileType(openFileDialog.GetPath());
		if (fif == FIF_UNKNOWN) {
			fif = FreeImage_GetFIFFromFilename(openFileDialog.GetPath());
		}
		if ((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif)) {
			FreeImage_processingFullSizeImage = FreeImage_Load(fif, openFileDialog.GetPath());
			FreeImage_FlipVertical(FreeImage_processingFullSizeImage);
			FreeImage_orgImage = FreeImage_Clone(FreeImage_processingFullSizeImage);
		}
		else
		{
			wxMessageBox(_("Sprobuj ponownie zaladowac obrazek"));
			return;
		}
	}
	if (image.GetSize().x < Main_Panel->GetSize().x || image.GetSize().y < Main_Panel->GetSize().y) {
		wxMessageBox(_("Obrazek w zbyt małej rozdzielczosci, sprobuj ponownie"));
		return;
	}
	setBrightnessLimits(FreeImage_processingFullSizeImage);
	prepareScaledThumbnail();
	afterScroll();
	displayMainImage();
	enableButtons();
}

void GUIMyFrame1::SaveFileButtonOnButtonClick(wxCommandEvent& event) {
	wxFileDialog saveFileDialog(this, "Choose a file", "", "", "Image Files (*.png;*.jpg)|*.pnh;*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL) return;
	AdjustColorsForBitmap(FreeImage_processingFullSizeImage, brightness, contrast, gamma, Red_Checkbox->IsChecked(), Green_Checkbox->IsChecked(), Blue_Checkbox->IsChecked()
		, Dark_Checkbox->IsChecked(), Medium_CheckBox->IsChecked(), Bright_Checkbox->IsChecked(), brightnessLimits);
	wxImage saveImage = *FIBITMAPTowxImage(FreeImage_processingFullSizeImage);
	saveImage.AddHandler(new wxJPEGHandler);
	saveImage.AddHandler(new wxPNGHandler);
	saveImage.SaveFile(saveFileDialog.GetPath());
}

void GUIMyFrame1::Horizontal_ScrollbarOnScroll(wxScrollEvent& event) {
	afterScroll();
	displayMainImage();
}

void GUIMyFrame1::Vertical_ScrollbarOnScroll(wxScrollEvent& event) {
	afterScroll();
	displayMainImage();
}

void GUIMyFrame1::Brightness_SliderOnScroll(wxScrollEvent& event) {
	brightness = (double)Brightness_Slider->GetValue();
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
	drawHistogram(FreeImage_currentOnScreenImage);
}

void GUIMyFrame1::Contrast_SliderOnScroll(wxScrollEvent& event) {
	contrast = (double)Contrast_Slider->GetValue();
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
}

void GUIMyFrame1::Gamma_SliderOnScroll(wxScrollEvent& event) {
	gamma = 1.0 + (double)Gamma_Slider->GetValue() / 101.0;
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
}

void GUIMyFrame1::disableButtons() {
	Histogram_Button->Disable();
	SaveFileButton->Disable();
	Red_Checkbox->Disable();
	Green_Checkbox->Disable();
	Blue_Checkbox->Disable();
	Brightness_Slider->Disable();
	Contrast_Slider->Disable();
	Gamma_Slider->Disable();
	Apply_Color_Button->Disable();
	Dark_Checkbox->Disable();
	Medium_CheckBox->Disable();
	Bright_Checkbox->Disable();
	Horizontal_Scrollbar->Disable();
	Vertical_Scrollbar->Disable();
	Reset_Button->Disable();
}

void GUIMyFrame1::enableButtons() {
	Histogram_Button->Enable();
	SaveFileButton->Enable();
	Red_Checkbox->Enable();
	Green_Checkbox->Enable();
	Blue_Checkbox->Enable();
	Brightness_Slider->Enable();
	Contrast_Slider->Enable();
	Gamma_Slider->Enable();
	Apply_Color_Button->Enable();
	Dark_Checkbox->Enable();
	Medium_CheckBox->Enable();
	Bright_Checkbox->Enable();
	Horizontal_Scrollbar->Enable();
	Vertical_Scrollbar->Enable();
	Reset_Button->Enable();
}

void GUIMyFrame1::displayThumbnail(int xRectPos, int yRectPos) {
	if (!photoThumbnail.IsOk())
		return;
	wxBitmap bitmap(photoThumbnail);
	wxClientDC dc(Miniature_Panel);
	dc.DrawBitmap(bitmap, 0, 0, true);

	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.SetPen(wxPen(wxColour(255,0,0),5));
	dc.DrawRectangle(xRectPos,yRectPos, selectedRectSize.x, selectedRectSize.y);

}

void GUIMyFrame1::prepareScaledThumbnail() {
	int width = FreeImage_GetWidth(FreeImage_orgImage);
	int height = FreeImage_GetHeight(FreeImage_orgImage);
	double propotion = static_cast<double>(width) / height;
	int panelWidth = Miniature_Panel->GetSize().x;
	wxSize miniatureSize = wxSize(panelWidth, panelWidth/propotion);
	selectedRectSize = wxSize(static_cast<double>(Main_Panel->GetSize().x) / width * miniatureSize.x, static_cast<double>(Main_Panel->GetSize().y) / height* miniatureSize.y);
	Miniature_Panel->SetSize(miniatureSize);
	photoThumbnail = processingFullSizeImage.Scale(miniatureSize.x, miniatureSize.y);
	
	//it is used for proper scrolling
	xProportion = static_cast<double>(miniatureSize.x) / selectedRectSize.x;
	yProportion = static_cast<double>(miniatureSize.y) / selectedRectSize.y;

	//adjusting scrollbars to new panel size
	Horizontal_Scrollbar->SetSize(wxSize(miniatureSize.x, 20));
	Vertical_Scrollbar->SetSize(wxSize(20, miniatureSize.y));
}

void GUIMyFrame1::afterScroll() {
	int xPos = static_cast<double>(Horizontal_Scrollbar->GetThumbPosition()) / Horizontal_Scrollbar->GetRange() * Miniature_Panel->GetSize().x * (1 - 1.0 / xProportion);
	int yPos = static_cast<double>(Vertical_Scrollbar->GetThumbPosition()) / Vertical_Scrollbar->GetRange() * Miniature_Panel->GetSize().y * (1 - 1.0 / yProportion);
	displayThumbnail(xPos, yPos);
	currentOnScreenXPos = static_cast<double>(xPos) / Miniature_Panel->GetSize().x * processingFullSizeImage.GetWidth();
	currentOnScreenYPos = - static_cast<double>(yPos) / Miniature_Panel->GetSize().y * processingFullSizeImage.GetHeight() + processingFullSizeImage.GetHeight();
	AdjustColors(brightness, contrast, gamma);
}

void GUIMyFrame1::displayMainImage() {
	if (!currentOnScreenImage.IsOk())
		return;
	wxBitmap bitmap(currentOnScreenImage);
	wxClientDC dc(Main_Panel);
	dc.DrawBitmap(bitmap, 0, 0, true);
}

FIBITMAP* GUIMyFrame1::wxImageToFIBITMAP(wxImage* image) {
	FIBITMAP* bitmap = FreeImage_Allocate(image->GetWidth(), image->GetHeight(), 24);
	RGBQUAD color;
	for (int y = 0; y < image->GetHeight(); y++) {
		for (int x = 0; x < image->GetWidth(); x++) {
		    color.rgbRed = image->GetRed(x, y);
			color.rgbGreen = image->GetGreen(x, y);
			color.rgbBlue = image->GetBlue(x, y);
			FreeImage_SetPixelColor(bitmap, x, y, &color);
		}
	}
	return bitmap;
}

wxImage* GUIMyFrame1::FIBITMAPTowxImage(FIBITMAP* bitmap) {
	wxImage* image = new wxImage(FreeImage_GetWidth(bitmap), FreeImage_GetHeight(bitmap));
	RGBQUAD color;
	for (int y = 0; y < FreeImage_GetHeight(bitmap); y++) {
		for (int x = 0; x < FreeImage_GetWidth(bitmap); x++) {
			FreeImage_GetPixelColor(bitmap, x, y, &color);
			image->SetRGB(x, y, color.rgbRed, color.rgbGreen, color.rgbBlue);
		}
	}
	return image;
}

void GUIMyFrame1::adjustColorsBrightnessRange(FIBITMAP* bitmap, std::function<bool(double, double, double)> f, double firstLimit, double secondLimit) {
	FIBITMAP* toEdit = FreeImage_Clone(bitmap);
	FreeImage_AdjustColors(toEdit, brightness, contrast, gamma);
	RGBQUAD color;
	RGBQUAD orgColor;
	for (int y = 0; y < FreeImage_GetHeight(toEdit); y++) {
		for (int x = 0; x < FreeImage_GetWidth(toEdit); x++) {
			FreeImage_GetPixelColor(bitmap, x, y, &orgColor);
			if (f(0.299 * orgColor.rgbRed + 0.587 * orgColor.rgbGreen + 0.114 * orgColor.rgbBlue,firstLimit,secondLimit)) {
				FreeImage_GetPixelColor(toEdit, x, y, &color);
				FreeImage_SetPixelColor(bitmap, x, y, &color);
			}
		}
	}
}

void GUIMyFrame1::AdjustColorsForBitmap(FIBITMAP* bitmap, double brightness, double contrast, double gamma, bool applyRed, bool applyGreen, bool applyBlue, bool applyDark, bool applyMedium, bool applyBright, double brightnessLevels[2]) {
	if (applyDark || applyMedium || applyBright) {
		if (applyDark && applyMedium && applyBright) {
			FreeImage_AdjustColors(bitmap, brightness, contrast, gamma);
		}
		else if (applyDark && applyBright) {
			adjustColorsBrightnessRange(bitmap, [&](double brightness, double x, double y) {
				if (brightness <= x || brightness >= y)
					return true;
				return false;
				}, brightnessLevels[0], brightnessLevels[1]);
		}
		else {
			double from = 0.0, to = 255.0;
			if (applyDark && applyMedium) { to = brightnessLevels[1]; }
			else if (applyMedium && applyBright) { from = brightnessLevels[0]; }
			else if (applyDark) { to = brightnessLevels[0]; }
			else if (applyMedium) { from = brightnessLevels[0]; to = brightnessLevels[1]; }
			else { from = brightnessLevels[1]; }

			adjustColorsBrightnessRange(bitmap, [&](double brightness, double x, double y) {
				if (brightness >= x && brightness <= y)
					return true;
				return false;
				}, from, to);
		}
	}
	else {
		//to optimize this operation we check how many checkbox is selected, thanks to that we perform maximum one iteration over pixels adjusting factors
		if ( (applyRed && applyGreen && applyBlue) || !(applyRed || applyGreen || applyBlue)) {
			FreeImage_AdjustColors(bitmap, brightness, contrast, gamma);
		}
		else if ((applyRed && applyGreen) || (applyRed && applyBlue) || (applyGreen && applyBlue)) {
			FREE_IMAGE_COLOR_CHANNEL colorChannel;
			if (!applyRed) {
				colorChannel = FICC_RED;
			}
			else if (!applyGreen) {
				colorChannel = FICC_GREEN;
			}
			else {
				colorChannel = FICC_BLUE;
			}
			FIBITMAP* toSave = FreeImage_GetChannel(bitmap, colorChannel);
			FreeImage_AdjustColors(bitmap, brightness, contrast, gamma);
			FreeImage_SetChannel(bitmap, toSave, colorChannel);
		}
		else {
			FREE_IMAGE_COLOR_CHANNEL colorChannel;
			if (applyRed) {
				colorChannel = FICC_RED;
			}
			else if (applyGreen) {
				colorChannel = FICC_GREEN;
			}
			else {
				colorChannel = FICC_BLUE;
			}
			FIBITMAP* toEdit = FreeImage_GetChannel(bitmap, colorChannel);
			FreeImage_AdjustColors(toEdit, brightness, contrast, gamma);
			FreeImage_SetChannel(bitmap, toEdit, colorChannel);
		}
	}
}

void GUIMyFrame1::AdjustColors(double brightness, double contrast, double gamma) {
	FreeImage_currentOnScreenImage = FreeImage_Copy(FreeImage_processingFullSizeImage, currentOnScreenXPos,currentOnScreenYPos, currentOnScreenXPos + Main_Panel->GetSize().x,currentOnScreenYPos-Main_Panel->GetSize().y);
	AdjustColorsForBitmap(FreeImage_currentOnScreenImage, brightness, contrast, gamma,Red_Checkbox->IsChecked(), Green_Checkbox->IsChecked(), Blue_Checkbox->IsChecked()
		,Dark_Checkbox->IsChecked(),Medium_CheckBox->IsChecked(),Bright_Checkbox->IsChecked(),brightnessLimits);
	currentOnScreenImage = *FIBITMAPTowxImage(FreeImage_currentOnScreenImage);
	drawHistogram(FreeImage_currentOnScreenImage);
}

void GUIMyFrame1::Red_CheckboxOnCheckBox(wxCommandEvent& event) {
	if (Red_Checkbox->IsChecked())
		checkboxCounterRGB++;
	else
		checkboxCounterRGB--;
	checkRGBCheckboxCounter();
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
}

void GUIMyFrame1::Green_CheckboxOnCheckBox(wxCommandEvent& event) {
	if (Green_Checkbox->IsChecked())
		checkboxCounterRGB++;
	else
		checkboxCounterRGB--;
	checkRGBCheckboxCounter();
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
}

void GUIMyFrame1::Blue_CheckboxOnCheckBox(wxCommandEvent& event){
	if (Blue_Checkbox->IsChecked())
		checkboxCounterRGB++;
	else
		checkboxCounterRGB--;
	checkRGBCheckboxCounter();
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
}

void GUIMyFrame1::Dark_CheckboxOnCheckBox(wxCommandEvent& event) {
	if (Dark_Checkbox->IsChecked())
		checkboxCounterBrightness++;
	else
		checkboxCounterBrightness--;
	checkBrightnessCheckboxCounter();
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
}

void GUIMyFrame1::Medium_CheckBoxOnCheckBox(wxCommandEvent& event){
	if (Medium_CheckBox->IsChecked())
		checkboxCounterBrightness++;
	else
		checkboxCounterBrightness--;
	checkBrightnessCheckboxCounter();
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
}

void GUIMyFrame1::Bright_CheckboxOnCheckBox(wxCommandEvent& event){
	if (Bright_Checkbox->IsChecked())
		checkboxCounterBrightness++;
	else
		checkboxCounterBrightness--;
	checkBrightnessCheckboxCounter();
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
}

void GUIMyFrame1::checkRGBCheckboxCounter() {
	if (checkboxCounterRGB == 0) {
		changeBrightnessCheckboxesState(true);
	}
	else {
		changeBrightnessCheckboxesState(false);
	}
}

void GUIMyFrame1::checkBrightnessCheckboxCounter() {
	if (checkboxCounterBrightness == 0) {
		changeRGBCheckboxesState(true);
	}
	else {
		changeRGBCheckboxesState(false);
	}
}

void GUIMyFrame1::changeRGBCheckboxesState(bool state) {
	if (state) {
		Red_Checkbox->Enable();
		Green_Checkbox->Enable();
		Blue_Checkbox->Enable();
	}
	else {
		Red_Checkbox->Disable();
		Green_Checkbox->Disable();
		Blue_Checkbox->Disable();
	}
}

void GUIMyFrame1::changeBrightnessCheckboxesState(bool state) {
	if (state) {
		Dark_Checkbox->Enable();
		Medium_CheckBox->Enable();
		Bright_Checkbox->Enable();
	}
	else {
		Dark_Checkbox->Disable();
		Medium_CheckBox->Disable();
		Bright_Checkbox->Disable();
	}
}

void GUIMyFrame1::setBrightnessLimits(FIBITMAP* bitmap) {
	double maxBrightness = 0.0;
	double minBrightness = 255.0;
	RGBQUAD color;
	for (int y = 0; y < FreeImage_GetHeight(bitmap); y++) {
		for (int x = 0; x < FreeImage_GetWidth(bitmap); x++) {
			FreeImage_GetPixelColor(bitmap, x, y, &color);
			double b = 0.299 * color.rgbRed + 0.587 * color.rgbGreen + 0.114 * color.rgbBlue;
			if (b > maxBrightness)
				maxBrightness = b;
			if (b < minBrightness)
				minBrightness = b;
		}
	}
	brightnessLimits[0] = (maxBrightness-minBrightness) / 3 + minBrightness ;
	brightnessLimits[1] = 2 * (maxBrightness-minBrightness) / 3 + minBrightness;
}

void GUIMyFrame1::Histogram_ButtonOnButtonClick(wxCommandEvent& event) {
	FIBITMAP* toGetHistogram = FreeImage_Clone(FreeImage_processingFullSizeImage);
	AdjustColorsForBitmap(toGetHistogram, brightness, contrast, gamma, Red_Checkbox->IsChecked(), Green_Checkbox->IsChecked(), Blue_Checkbox->IsChecked()
		, Dark_Checkbox->IsChecked(), Medium_CheckBox->IsChecked(), Bright_Checkbox->IsChecked(), brightnessLimits);
	drawHistogram(toGetHistogram);
}

void GUIMyFrame1::drawHistogram(FIBITMAP *bitmap) {
	FreeImage_GetHistogram(bitmap, data, FICC_RGB);

	double x = Histogram_Panel->GetSize().x;
	double y = Histogram_Panel->GetSize().y;
	double dx = x / 256;
	int max = *std::max_element(data, data + 255);

	wxClientDC dc(Histogram_Panel);
	dc.SetBackground(wxColor(255,255,255));
	dc.Clear();

	for (unsigned int i = 0; i < 256; i++) {
		dc.SetBrush(*wxBLACK_BRUSH);
		dc.DrawRectangle(wxRect(i * dx, y - ((double)data[i] / max) * y, 4, ((double)data[i] / max) * y));
	}
}

void GUIMyFrame1::Apply_Color_ButtonOnButtonClick(wxCommandEvent& event) {
	AdjustColorsForBitmap(FreeImage_processingFullSizeImage, brightness, contrast, gamma, Red_Checkbox->IsChecked(), Green_Checkbox->IsChecked(), Blue_Checkbox->IsChecked()
		, Dark_Checkbox->IsChecked(), Medium_CheckBox->IsChecked(), Bright_Checkbox->IsChecked(), brightnessLimits);
	processingFullSizeImage = *FIBITMAPTowxImage(FreeImage_processingFullSizeImage);
	resetButtonsAndSliders();
	setBrightnessLimits(FreeImage_processingFullSizeImage);
	prepareScaledThumbnail();
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
	afterScroll();
}
void GUIMyFrame1::Reset_ButtonOnButtonClick(wxCommandEvent& event){
	FreeImage_processingFullSizeImage = FreeImage_Clone(FreeImage_orgImage);
	processingFullSizeImage = *FIBITMAPTowxImage(FreeImage_processingFullSizeImage);
	resetButtonsAndSliders();
	prepareScaledThumbnail();
	setBrightnessLimits(FreeImage_orgImage);
	AdjustColors(brightness, contrast, gamma);
	displayMainImage();
	afterScroll();
}

void GUIMyFrame1::resetButtonsAndSliders() {
	Red_Checkbox->SetValue(false);
	Green_Checkbox->SetValue(false);
	Blue_Checkbox->SetValue(false);
	Brightness_Slider->SetValue(0);
	Contrast_Slider->SetValue(0);
	Gamma_Slider->SetValue(0);
	brightness = 0;
	contrast = 0;
	gamma = 1.0;
	Dark_Checkbox->SetValue(false);
	Medium_CheckBox->SetValue(false);
	Bright_Checkbox->SetValue(false);
	checkboxCounterBrightness = 0;
	checkboxCounterRGB = 0;
	checkBrightnessCheckboxCounter();
	checkRGBCheckboxCounter();
}