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
    void OnReset(wxCommandEvent& event);
    DECLARE_EVENT_TABLE()
};

enum
{
    SIMMENU_CONNECT = wxID_HIGHEST +1,
    SIMMENU_DISCONNECT,
    SIMMENU_RESET,
    RACEMENU_LOADTRK,
    RACEMENU_START,
    RACEMENU_END,
    SETMENU_GENERAL,
    HELPMENU_ABOUT,
    HELPMENU_WEBSITE
};

#endif