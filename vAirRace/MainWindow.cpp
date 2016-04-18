//Main Window class implementation.
#include "MainWindow.h"

MainWindow::MainWindow(wxString Screen): wxFrame((wxFrame*) NULL, -1, wxT("vAirRace Version ") + VersionNumber, wxDefaultPosition, wxSize(600,425))
{
    sim = new Simulator();
    log = new Log();
    CreateStatusBar(1);
    MenuBar = new wxMenuBar();
    wxMenu *SimulatorMenu = new wxMenu();
    SimulatorMenu->Append(SIMMENU_CONNECT, "&Connect", "Connect to simulator");
    SimulatorMenu->Append(SIMMENU_DISCONNECT, "&Disconnect", "Disconnect from simulator");
    SimulatorMenu->Append(SIMMENU_RESET, "&Reset", "Reset connection to simulator");
    MenuBar->Append(SimulatorMenu, "&Simulator");
    wxMenu *RaceMenu = new wxMenu();
    RaceMenu->Append(RACEMENU_LOADTRK, "&Load New Track", "Load a new race track");
    RaceMenu->Append(RACEMENU_START, "&Start", "Start timed track run");
    RaceMenu->Append(RACEMENU_END, "&End", "Terminate timed track run");
    MenuBar->Append(RaceMenu, "&Race");
    wxMenu *SettingsMenu = new wxMenu();
    SettingsMenu->Append(SETMENU_GENERAL, "&General", "General settings");
    MenuBar->Append(SettingsMenu, "&Settings");
    wxMenu *HelpMenu = new wxMenu();
    HelpMenu->Append(HELPMENU_ABOUT, "&About", "About the program");
    HelpMenu->Append(HELPMENU_WEBSITE, "&Website", "Visit out website");
    SetMenuBar(MenuBar);
}

MainWindow::~MainWindow()
{
    delete sim;
}

BEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(SIMMENU_CONNECT, MainWindow::OnConnect)
    EVT_MENU(SIMMENU_DISCONNECT, MainWindow::OnDisconnect)
    EVT_MENU(SIMMENU_RESET, MainWindow::OnReset)
END_EVENT_TABLE()

void MainWindow::OnConnect(wxCommandEvent& event)
{
    int errorCode;
    sim->Disconnect();
    errorCode = sim->Connect();
    if (errorCode == 0)
        SetStatusText("Connected to simulator");
    else
    {
        std::string message = "Failed to connect to simulator with error code " + std::to_string(errorCode);
        SetStatusText(message);
        log->write(message);
    }
}

void MainWindow::OnDisconnect(wxCommandEvent& event)
{
    //TODO: Clear resource states.
    sim->Disconnect();
    SetStatusText("Disconnected from simulator");
}

void MainWindow::OnReset(wxCommandEvent& event)
{
    //TODO: Reset resource states.
    sim->Reset();
}