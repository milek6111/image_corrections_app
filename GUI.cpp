///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(1500,800), wxSize(1500,800));

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer(wxVERTICAL);

	Main_Panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	Main_Panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
	bSizer19->Add(Main_Panel, 1, wxEXPAND | wxALL, 5);


	bSizer2->Add(bSizer19, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer(wxVERTICAL);

	Histogram_Panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 100), wxTAB_TRAVERSAL);
	Histogram_Panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	bSizer21->Add(Histogram_Panel, 1, wxEXPAND | wxALL, 5);


	bSizer20->Add(bSizer21, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer(wxHORIZONTAL);

	Histogram_Button = new wxButton(this, wxID_ANY, wxT("Histogram"), wxDefaultPosition, wxDefaultSize, 0);
	Histogram_Button->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));

	bSizer22->Add(Histogram_Button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);


	bSizer20->Add(bSizer22, 0, wxEXPAND, 5);


	bSizer2->Add(bSizer20, 0, wxEXPAND, 5);


	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxVERTICAL);

	Load_File_Button = new wxButton(this, wxID_ANY, wxT("Wczytaj plik"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(Load_File_Button, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL, 5);

	SaveFileButton = new wxButton(this, wxID_ANY, wxT("Zapisz plik"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(SaveFileButton, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer4->Add(bSizer5, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxHORIZONTAL);

	Red_Checkbox = new wxCheckBox(this, wxID_ANY, wxT("RED"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer7->Add(Red_Checkbox, 1, wxALL, 5);

	Green_Checkbox = new wxCheckBox(this, wxID_ANY, wxT("GREEN"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer7->Add(Green_Checkbox, 1, wxALL, 5);

	Blue_Checkbox = new wxCheckBox(this, wxID_ANY, wxT("BLUE"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer7->Add(Blue_Checkbox, 1, wxALL, 5);


	bSizer4->Add(bSizer7, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer(wxVERTICAL);

	Brightness_Slider = new wxSlider(this, wxID_ANY, 0, -100, 100, wxDefaultPosition, wxSize(250, 20), wxSL_HORIZONTAL);
	bSizer23->Add(Brightness_Slider, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	Contrast_Slider = new wxSlider(this, wxID_ANY, 0, -100, 100, wxDefaultPosition, wxSize(250, 20), wxSL_HORIZONTAL);
	bSizer23->Add(Contrast_Slider, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	Gamma_Slider = new wxSlider(this, wxID_ANY, 0, -100, 100, wxDefaultPosition, wxSize(250, 20), wxSL_HORIZONTAL);
	bSizer23->Add(Gamma_Slider, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer8->Add(bSizer23, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer(wxVERTICAL);

	m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Jasnoœæ"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText2->Wrap(-1);
	bSizer24->Add(m_staticText2, 1, wxALL, 5);

	m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("Kontrast"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText3->Wrap(-1);
	bSizer24->Add(m_staticText3, 1, wxALL, 5);

	m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("Gamma"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4->Wrap(-1);
	bSizer24->Add(m_staticText4, 1, wxALL, 5);


	bSizer8->Add(bSizer24, 0, wxEXPAND, 5);


	bSizer4->Add(bSizer8, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxHORIZONTAL);

	Apply_Color_Button = new wxButton(this, wxID_ANY, wxT("ZatwierdŸ"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(Apply_Color_Button, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	Reset_Button = new wxButton(this, wxID_ANY, wxT("Resetuj "), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(Reset_Button, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	bSizer4->Add(bSizer9, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxHORIZONTAL);

	Dark_Checkbox = new wxCheckBox(this, wxID_ANY, wxT(" Ciemne kolory"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(Dark_Checkbox, 0, wxALL, 5);

	Medium_CheckBox = new wxCheckBox(this, wxID_ANY, wxT("Œrednie kolory"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(Medium_CheckBox, 0, wxALL, 5);

	Bright_Checkbox = new wxCheckBox(this, wxID_ANY, wxT("Jasne kolory"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(Bright_Checkbox, 0, wxALL, 5);


	bSizer4->Add(bSizer10, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer(wxVERTICAL);

	Apply_Size_Button = new wxButton(this, wxID_ANY, wxT("ZatwierdŸ"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer11->Add(Apply_Size_Button, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer4->Add(bSizer11, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer(wxVERTICAL);

	Horizontal_Scrollbar = new wxScrollBar(this, wxID_ANY, wxDefaultPosition, wxSize(350, 20), wxSB_HORIZONTAL);
	Horizontal_Scrollbar->SetThumbSize(1);
	Horizontal_Scrollbar->SetRange(100);
	bSizer13->Add(Horizontal_Scrollbar, 1, wxALL, 5);


	bSizer12->Add(bSizer13, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer(wxVERTICAL);

	Miniature_Panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(250, 250), wxTAB_TRAVERSAL);
	Miniature_Panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
	Miniature_Panel->SetMaxSize(wxSize(-1, 300));

	bSizer16->Add(Miniature_Panel, 1, wxEXPAND | wxALL, 5);


	bSizer15->Add(bSizer16, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer(wxHORIZONTAL);

	Vertical_Scrollbar = new wxScrollBar(this, wxID_ANY, wxDefaultPosition, wxSize(20,Miniature_Panel->GetSize().y), wxSB_VERTICAL);
	Vertical_Scrollbar->SetThumbSize(1);
	Vertical_Scrollbar->SetRange(100);
	bSizer18->Add(Vertical_Scrollbar, 1, wxALL, 5);


	bSizer15->Add(bSizer18, 0, wxEXPAND, 5);


	bSizer12->Add(bSizer15, 1, wxEXPAND, 5);


	bSizer4->Add(bSizer12, 1, wxEXPAND, 5);


	bSizer1->Add(bSizer4, 0, wxEXPAND, 5);

	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	Histogram_Button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Histogram_ButtonOnButtonClick), NULL, this);
	Load_File_Button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Load_File_ButtonOnButtonClick), NULL, this);
	SaveFileButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::SaveFileButtonOnButtonClick), NULL, this);
	Red_Checkbox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Red_CheckboxOnCheckBox), NULL, this);
	Green_Checkbox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Green_CheckboxOnCheckBox), NULL, this);
	Blue_Checkbox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Blue_CheckboxOnCheckBox), NULL, this);
	Brightness_Slider->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Contrast_Slider->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Gamma_Slider->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Apply_Color_Button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Apply_Color_ButtonOnButtonClick), NULL, this);
	Reset_Button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Reset_ButtonOnButtonClick), NULL, this);
	Dark_Checkbox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Dark_CheckboxOnCheckBox), NULL, this);
	Medium_CheckBox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Medium_CheckBoxOnCheckBox), NULL, this);
	Bright_Checkbox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Bright_CheckboxOnCheckBox), NULL, this);
	Apply_Size_Button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Apply_Size_ButtonOnButtonClick), NULL, this);
	Horizontal_Scrollbar->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	Histogram_Button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Histogram_ButtonOnButtonClick), NULL, this);
	Load_File_Button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Load_File_ButtonOnButtonClick), NULL, this);
	SaveFileButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::SaveFileButtonOnButtonClick), NULL, this);
	Red_Checkbox->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Red_CheckboxOnCheckBox), NULL, this);
	Green_Checkbox->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Green_CheckboxOnCheckBox), NULL, this);
	Blue_Checkbox->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Blue_CheckboxOnCheckBox), NULL, this);
	Brightness_Slider->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Brightness_Slider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Brightness_SliderOnScroll), NULL, this);
	Contrast_Slider->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Contrast_Slider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Contrast_SliderOnScroll), NULL, this);
	Gamma_Slider->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Gamma_Slider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Gamma_SliderOnScroll), NULL, this);
	Apply_Color_Button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Apply_Color_ButtonOnButtonClick), NULL, this);
	Reset_Button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Reset_ButtonOnButtonClick), NULL, this);
	Dark_Checkbox->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Dark_CheckboxOnCheckBox), NULL, this);
	Medium_CheckBox->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Medium_CheckBoxOnCheckBox), NULL, this);
	Bright_Checkbox->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame1::Bright_CheckboxOnCheckBox), NULL, this);
	Apply_Size_Button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Apply_Size_ButtonOnButtonClick), NULL, this);
	Horizontal_Scrollbar->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Horizontal_Scrollbar->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Horizontal_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);
	Vertical_Scrollbar->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Vertical_ScrollbarOnScroll), NULL, this);

}