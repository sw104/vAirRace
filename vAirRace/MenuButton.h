#ifndef MENUBUTTON_H
#define MENUBUTTON_H

class MenuButton: public wxWindow
{
	bool presseddown;
	wxString text;
	//wxColour normalcolour;
	//wxColour pressedcolour;
	static const int width=125;
	static const int height=35;
	int eventid;

public:
	MenuButton(wxPanel* parent, int eventid, wxString text);

	void PaintEvent(wxPaintEvent& event);
	void PaintNow();

	void Render(wxDC& dc);

	void MouseClick(wxMouseEvent& event);
	void MouseReleased(wxMouseEvent& event);
	void MouseLeftWindow(wxMouseEvent& event);

	DECLARE_EVENT_TABLE()
};

#endif