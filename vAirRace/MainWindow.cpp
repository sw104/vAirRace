//Main code implemenatation.
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif
#include "MenuButton.h"
#include "MainWindow.h"


IMPLEMENT_APP(MainApp)

bool MainApp::OnInit()
{
	MainFrame* MainWindow = new MainFrame(wxT("Home"));
	MainWindow->Show(true);
	return true;
}

MainFrame::MainFrame(wxString Screen): wxFrame((wxFrame*) NULL, -1, wxT("vAirRace Version ") + VersionNumber, wxDefaultPosition, wxSize(600,425))
{
	wxInitAllImageHandlers();
	wxPanel *MainMenuPanel = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(130,425)); 
	wxBoxSizer* MainMenuSizer = new wxBoxSizer(wxVERTICAL);
	MainMenuSizer->AddSpacer(30);
	ButtonHome=new MenuButton(MainMenuPanel, BUTTON_HOME, wxT("Home"));
	MainMenuSizer->Add(ButtonHome, 0, wxALL, 2);
	ButtonRace=new MenuButton(MainMenuPanel, BUTTON_RACE, wxT("Race"));
	MainMenuSizer->Add(ButtonRace, 0, wxALL, 2);
	ButtonHelp=new MenuButton(MainMenuPanel, BUTTON_HELP, wxT("Help"));
	MainMenuSizer->Add(ButtonHelp, 0, wxALL, 2);
	this->SetSizer(MainMenuSizer);
	wxPanel *ContentPanel = new wxPanel(this, wxID_ANY, wxPoint(140,0), wxSize(465,425));
}

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_HOME, MainFrame::HomeWindow)
END_EVENT_TABLE()

void MainFrame::HomeWindow(wxCommandEvent& WXUNUSED(event))
{
	wxPanel *HomeContentPanel = new wxPanel(this, wxID_ANY);
	wxStaticText *HomeTitle=new wxStaticText(this, wxID_ANY, "Home", wxPoint(200,5));
}