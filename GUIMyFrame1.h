#pragma once
#include "GUI.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx\dcclient.h>

class GUIMyFrame1 : public MyFrame1 {
public:
	GUIMyFrame1(wxWindow* parent);
	void Load_File_ButtonOnButtonClick(wxCommandEvent& event) override;
	void Horizontal_ScrollbarOnScroll(wxScrollEvent& event) override;
	void Vertical_ScrollbarOnScroll(wxScrollEvent& event) override;
private:
	void disableButtons();
	void enableButtons();
	void displayThumbnail(int xRectPos, int yRectPos);
	void prepareScaledThumbnail();
	void afterScroll();
	void displayMainImage();
	void prepareMainFrame();
	wxImage orgImage; //orginal image in full resolution, it should never be edited
	wxImage processingFullSizeImage; //image in full resolution, currentOnScreenImage is based on that image, it is only updated when user click apply button
	wxImage currentOnScreenImage; //part of image which is displayed on main screen and we perform all operation on it
	wxImage photoThumbnail; //photo tumbnail all image which is displayed on down-right corner of program
	wxSize selectedRectSize; //this is shown on miniature and select which part of image is displayed on main screen
	int miniatureSizeToRectSize = 5; //it is used to create rect on miniarue with proper size
};