//Main Window class declaration.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "vAirRace.h"
#include "Simulator.h"

class MainWindow : public wxFrame
{
public:
	MainWindow(wxString Screen);
	~MainWindow();

private:
	Simulator* sim;
	wxMenuBar* MenuBar;
	void OnConnect(wxCommandEvent& event);
	void OnDisconnect(wxCommandEvent& event);

	DECLARE_EVENT_TABLE()
};

enum
{
	MENU_CONNECT = wxID_HIGHEST +1,
	MENU_DISCONNECT
};

#endif