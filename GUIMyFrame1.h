#pragma once
#include "GUI.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx\dcclient.h>
#include <fstream>
#include <wx/log.h>
#include "FreeImage.h"

class GUIMyFrame1 : public MyFrame1 {
public:
	GUIMyFrame1(wxWindow* parent);
	void Load_File_ButtonOnButtonClick(wxCommandEvent& event) override;
	void Horizontal_ScrollbarOnScroll(wxScrollEvent& event) override;
	void Vertical_ScrollbarOnScroll(wxScrollEvent& event) override;
	void SaveFileButtonOnButtonClick(wxCommandEvent& event) override;
	virtual void Brightness_SliderOnScroll(wxScrollEvent& event) override; 
	virtual void Contrast_SliderOnScroll(wxScrollEvent& event) override; 
	virtual void Gamma_SliderOnScroll(wxScrollEvent& event) override;
	virtual void Red_CheckboxOnCheckBox(wxCommandEvent& event) override;
	virtual void Green_CheckboxOnCheckBox(wxCommandEvent& event) override;
	virtual void Blue_CheckboxOnCheckBox(wxCommandEvent& event) override;
	virtual void Dark_CheckboxOnCheckBox(wxCommandEvent& event) override;
	virtual void Medium_CheckBoxOnCheckBox(wxCommandEvent& event) override;
	virtual void Bright_CheckboxOnCheckBox(wxCommandEvent& event) override;
private:
	void disableButtons();
	void enableButtons();
	void displayThumbnail(int xRectPos, int yRectPos); //This method rescale miniature panel and display rescaled miniature photo
	void prepareScaledThumbnail();
	void afterScroll();
	void displayMainImage();
	void prepareMainFrame();
	void changeRGBCheckboxesState(bool state); //enable or disable rgb checkboxes depending on passed state
	void changeBrightnessCheckboxesState(bool state); //enable or disable brightness checkboxes depending on passed state
	void checkRGBCheckboxCounter(); //check if any of RGB checboxes is checked, if RGBCheckboxcounter is equal 0 then brightness checkboxes are enabled
	void checkBrightnessCheckboxCounter(); //check if any of Brightness checboxes is checked, if brightnessChecbkoxcounter is equal 0 then RGB checkboxes are enabled
	void setBrightnessLimits(FIBITMAP* bitmap); //find maximum and minimum value of brightness of image and calculate rages which are use in brightness checkboxes
	void adjustColorsBrightnessRange(FIBITMAP* bitmap, std::function<bool(double, double, double)> f, double firstLimit, double secondLimit); //iterate over pixels and apply changes when passed function f is true
	wxImage orgImage; //orginal image in full resolution, it should never be edited
	wxImage processingFullSizeImage; //image in full resolution, currentOnScreenImage is based on that image, it is only updated when user click apply button
	FIBITMAP* FreeImage_processingFullSizeImage; //image in full resolution, currentOnScreenImage is based on that image, it is only updated when user click apply button
	FIBITMAP* FreeImage_currentOnScreenImage; //part of image which is displayed on main screen and we perform all operation on it
	wxImage currentOnScreenImage; //part of image which is displayed on main screen and we perform all operation on it
	wxImage photoThumbnail; //photo tumbnail all image which is displayed on down-right corner of program
	wxSize selectedRectSize; //this is shown on miniature and select which part of image is displayed on main screen
	wxSize miniatureSizeToRectSize; //it is used to create rect on miniarue with proper size
	double xProportion; //width of miniature divided by rect width
	double yProportion; //height of miniature divided by rect height 
	wxPoint redRectPosition; //stores position of upper left corner of red rect 
	
	double brightness = 0;
	double contrast = 0;
	double gamma = 1.0;
	double brightnessLimits[2] = {85,170};
	int checkboxCounterBrightness = 0; //count how many brightness checkboxes are checked
	int checkboxCounterRGB = 0; //count how many RGB checkboxes are checked
	int currentOnScreenXPos = 0; //is is used for copying proper part of image from orignal image to currentOnScreenImage
	int currentOnScreenYPos = 0; //is is used for copying proper part of image from orignal image to currentOnScreenImage
	FIBITMAP* wxImageToFIBITMAP(wxImage* image); //convert wxImage to FIBITMAP
	wxImage* FIBITMAPTowxImage(FIBITMAP* bitmap); //convert FIBITMAP to wxImage
	void AdjustColors(double brightness, double contrast, double gamma); //change brightness, contrast and gamma of currentOnScreenImage
	void AdjustColorsForBitmap(FIBITMAP* bitmap, double brightness, double contrast, double gamma, bool applyRed, bool applyGreen, bool applyBlue, bool applyDark, bool applyMedium, bool applyBright, double brightnessLevels[2]); //method which adjust gamma,brightness and contrast to passed FIBITMAP relying on passed parameters
};

