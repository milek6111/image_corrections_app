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

private:
	void disableButtons();
	void enableButtons();
	void displayThumbnail(int xRectPos, int yRectPos);
	void prepareScaledThumbnail();
	void afterScroll();
	void displayMainImage();
	void prepareMainFrame();
	void Brightness(int value);
	void Contrast(int value);
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
	int currentOnScreenXPos = 0; //is is used for copying proper part of image from orignal image to currentOnScreenImage
	int currentOnScreenYPos = 0; //is is used for copying proper part of image from orignal image to currentOnScreenImage
	FIBITMAP* wxImageToFIBITMAP(wxImage* image); //convert wxImage to FIBITMAP
	wxImage* FIBITMAPTowxImage(FIBITMAP* bitmap); //convert FIBITMAP to wxImage
	void AdjustColors(double brightness, double contrast, double gamma); //change brightness, contrast and gamma of currentOnScreenImage
	FIBITMAP* currentFIImage; //current part of displayed image in FIBITMAP format


};

