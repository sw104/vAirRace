//vAirRace Application Class implementation.
#include "vAirRace.h"

IMPLEMENT_APP(vAirRace)

bool vAirRace::OnInit()
{
	MainWindow* window = new MainWindow(wxT("Home"));
	window->Show(true);
	SetTopWindow(window);
	return true;
}
