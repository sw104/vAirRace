//Main Window class implementation.
#include "MainWindow.h"

MainWindow::MainWindow(wxString Screen): wxFrame((wxFrame*) NULL, -1, wxT("vAirRace Version ") + VersionNumber, wxDefaultPosition, wxSize(600,425))
{
	sim = new Simulator();
	CreateStatusBar(1);
	MenuBar = new wxMenuBar();
	wxMenu *ConnectionMenu = new wxMenu();
	ConnectionMenu->Append(MENU_CONNECT, "&Connect", "Connect to simulator");
	ConnectionMenu->Append(MENU_DISCONNECT, "&Disconnect", "Disconnect from simulator");
	MenuBar->Append(ConnectionMenu, "&Connection");
	SetMenuBar(MenuBar);
}

MainWindow::~MainWindow()
{
	delete sim;
}

BEGIN_EVENT_TABLE(MainWindow, wxFrame)
	EVT_MENU(MENU_CONNECT, MainWindow::OnConnect)
	EVT_MENU(MENU_DISCONNECT, MainWindow::OnDisconnect)
END_EVENT_TABLE()

void MainWindow::OnConnect(wxCommandEvent& event)
{
	if (sim->Connect())
		SetStatusText("Connected to simulator");
	else
		SetStatusText("Failed to connect to simulator");
}

void MainWindow::OnDisconnect(wxCommandEvent& event)
{
	sim->Disconnect();
	SetStatusText("Disconnected from simulator");
}