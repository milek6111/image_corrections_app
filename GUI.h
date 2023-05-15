///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/scrolbar.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
private:

protected:
	wxPanel* Main_Panel;
	wxPanel* Histogram_Panel;
	wxButton* Histogram_Button;
	wxButton* Load_File_Button;
	wxButton* SaveFileButton;
	wxCheckBox* Red_Checkbox;
	wxCheckBox* Green_Checkbox;
	wxCheckBox* Blue_Checkbox;
	wxSlider* Brightness_Slider;
	wxSlider* Contrast_Slider;
	wxSlider* Gamma_Slider;
	wxStaticText* m_staticText2;
	wxStaticText* m_staticText3;
	wxStaticText* m_staticText4;
	wxButton* Apply_Color_Button;
	wxButton* Reset_Button;
	wxCheckBox* Dark_Checkbox;
	wxCheckBox* Medium_CheckBox;
	wxCheckBox* Bright_Checkbox;
	wxButton* Apply_Size_Button;
	wxScrollBar* Horizontal_Scrollbar;
	wxPanel* Miniature_Panel;
	wxScrollBar* Vertical_Scrollbar;

	//// Virtual event handlers, override them in your derived class
	virtual void Histogram_ButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void Load_File_ButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void SaveFileButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void Red_CheckboxOnCheckBox(wxCommandEvent& event) { event.Skip(); }
	virtual void Green_CheckboxOnCheckBox(wxCommandEvent& event) { event.Skip(); }
	virtual void Blue_CheckboxOnCheckBox(wxCommandEvent& event) { event.Skip(); }
	virtual void Brightness_SliderOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void Contrast_SliderOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void Gamma_SliderOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void Apply_Color_ButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void Reset_ButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void Dark_CheckboxOnCheckBox(wxCommandEvent& event) { event.Skip(); }
	virtual void Medium_CheckBoxOnCheckBox(wxCommandEvent& event) { event.Skip(); }
	virtual void Bright_CheckboxOnCheckBox(wxCommandEvent& event) { event.Skip(); }
	virtual void Apply_Size_ButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void Horizontal_ScrollbarOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void Vertical_ScrollbarOnScroll(wxScrollEvent& event) { event.Skip(); }


public:

	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Korekcja Gamma"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(799, 600), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame1();

};
