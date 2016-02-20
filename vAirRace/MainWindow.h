#ifndef MAINWINDOW_H
#define MAINWINDOW_H

const wxString VersionNumber="V0.1";

class MainApp: public wxApp
{
public:
	virtual bool OnInit();
};

class MainFrame: public wxFrame
{
public:
	MainFrame(wxString Screen);
	MenuButton *ButtonHome;
	MenuButton *ButtonRace;
	MenuButton *ButtonHelp;

	void HomeWindow(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()
};

enum
{
	BUTTON_HOME = wxID_HIGHEST +1,
	BUTTON_RACE,
	BUTTON_HELP
};

#endif