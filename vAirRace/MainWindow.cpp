//Main Window class implementation.
#include "MainWindow.h"

MainWindow::MainWindow(wxString Screen): wxFrame((wxFrame*) NULL, -1, "vAirRace Version " + VersionNumber, wxDefaultPosition, wxSize(600,425))
{
    sim = new Simulator();
    log = new Log(true, true);
    log->write("Application started", "Application Status");
    CreateStatusBar(1);
    //Set up menu items.
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
    log->write("Application terminated", "Application Status");
    delete sim;
    delete log;
}

BEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(SIMMENU_CONNECT, MainWindow::OnConnect)
    EVT_MENU(SIMMENU_DISCONNECT, MainWindow::OnDisconnect)
    EVT_MENU(SIMMENU_RESET, MainWindow::OnReset)
END_EVENT_TABLE()

void MainWindow::OnConnect(wxCommandEvent& event)
{
    sim->Disconnect();
    int errorCode = sim->Connect();
    if (errorCode == 0)
    {
        SetStatusText("Simulator: Connected");
        log->write("Connected", "Simulator Status");
    }
    else
    {
        SetStatusText("Simulator: Connection failed - error code " + std::to_string(errorCode));
        log->write("Failed to connect - error code " + std::to_string(errorCode), "Simulator Error");
    }
}

void MainWindow::OnDisconnect(wxCommandEvent& event)
{
    //TODO: Clear resource states.
    sim->Disconnect();
    SetStatusText("Simulator: Disconnected");
    log->write("Disconnected", "Simulator Status");
}

void MainWindow::OnReset(wxCommandEvent& event)
{
    if (sim->ConnectionStatus())
    {
        int errorCode = sim->Reset();
        if (errorCode == 0)
        {
            //TODO: Reset resource states.
            SetStatusText("Simulator: Connected - Reset successful");
            log->write("Connection reset", "Simulator Status");
        }
        else
        {
            //TODO: Clear resource states.
            SetStatusText("Simulator: Connection failed - error code " + std::to_string(errorCode));
            log->write("Failed to connect - error code " + std::to_string(errorCode), "Simulator Error");
        }
    }
    else
    {
        SetStatusText("Simulator: Disconnected - Can't reset non-existant connection");
        log->write("Can't reset non-existant connection", "Simulator Error");
    }
}