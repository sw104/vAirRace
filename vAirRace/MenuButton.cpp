//Main code implemenatation.
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif
#include "MenuButton.h"

BEGIN_EVENT_TABLE(MenuButton, wxPanel)
	EVT_LEFT_DOWN(MenuButton::MouseClick)
	EVT_LEFT_UP(MenuButton::MouseReleased)
	EVT_LEAVE_WINDOW(MenuButton::MouseLeftWindow)
	EVT_PAINT(MenuButton::PaintEvent)
END_EVENT_TABLE()

MenuButton::MenuButton(wxPanel* parent, int eventid, wxString text): wxWindow(parent, wxID_ANY)
{
	SetMinSize(wxSize(width, height));
	this->text=text;
	this->eventid=eventid;
	presseddown=false;
}

void MenuButton::PaintEvent(wxPaintEvent& WXUNUSED(event))
{
	wxPaintDC dc(this);
	Render(dc);
}

void MenuButton::PaintNow()
{
	wxClientDC dc(this);
	Render(dc);
}

void MenuButton::Render(wxDC& dc)
{
	if (presseddown)
	{
		wxBrush darkcyan;
		darkcyan.SetColour(0,130,185);
		dc.SetBrush(darkcyan);
	}
	else
	{
		wxBrush lightcyan;
		lightcyan.SetColour(0,162,232);
		dc.SetBrush(lightcyan);
	}
	wxRect buttonshape(0, 0, width, height);
	dc.DrawRectangle(buttonshape);
	dc.DrawLabel(text, buttonshape, wxALIGN_CENTER);
}

void MenuButton::MouseClick(wxMouseEvent& WXUNUSED(event))
{
	presseddown=true;
	//wxEvent*(eventid);
	//SetEventType(wxEVT_BUTTON_);
	//ProcessEvent();
	ProcessEvent(wxCommandEvent(wxEVT_BUTTON, eventid));
	PaintNow();
}

void MenuButton::MouseReleased(wxMouseEvent& WXUNUSED(event))
{
	presseddown=false;
	PaintNow();
}

void MenuButton::MouseLeftWindow(wxMouseEvent& WXUNUSED(event))
{
	if (presseddown)
	{
		presseddown=false;
		PaintNow();
	}
}