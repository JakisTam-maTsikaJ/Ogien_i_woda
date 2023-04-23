/***************************************************************
 * Name:      MenuMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-02-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "MenuMain.h"
#include <wx/msgdlg.h>



//(*InternalHeaders(MenuFrame)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

//(*IdInit(MenuFrame)
const long MenuFrame::ID_BITMAPBUTTON2 = wxNewId();
const long MenuFrame::ID_BITMAPBUTTON1 = wxNewId();
const long MenuFrame::ID_STATICBITMAP1 = wxNewId();
const long MenuFrame::idMenuAbout = wxNewId();
const long MenuFrame::ID_STATUSBAR1 = wxNewId();
const long MenuFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MenuFrame,wxFrame)
    //(*EventTable(MenuFrame)
    //*)
END_EVENT_TABLE()

MenuFrame::MenuFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MenuFrame)
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Ogień i woda"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(720,446));
    BitmapButton2 = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("Quit.png"))), wxPoint(664,8), wxSize(50,50), wxBU_AUTODRAW|wxTRANSPARENT_WINDOW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("start.png"))), wxPoint(280,208), wxSize(180,47), wxBU_AUTODRAW|wxTRANSPARENT_WINDOW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("tlo.png")).Rescale(wxSize(720,448).GetWidth(),wxSize(720,448).GetHeight())), wxPoint(0,0), wxSize(720,448), 0, _T("ID_STATICBITMAP1"));
    MenuBar1 = new wxMenuBar();
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("\tF1"), _("Ukazuje twórców gry"), wxITEM_NORMAL);
    MenuItem2->SetBitmap(wxBitmap(wxImage(_T("tworcy.png"))));
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Informacje"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(1, false);

    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MenuFrame::Przycisk_quit);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MenuFrame::Przycisk_Start);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MenuFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&MenuFrame::OnTimer1Trigger);
    //*)
    SetIcon(wxICON(aaaa));

}

MenuFrame::~MenuFrame()
{
    //(*Destroy(MenuFrame)
    //*)
}

void MenuFrame::OnQuit(wxCommandEvent& event)
{
    Close();//
}

void MenuFrame::OnAbout(wxCommandEvent& event)
{
     wxMessageBox(wxString::FromUTF8("Twórcy:\n-Adam Jakubczak\n-Jakub Janusz\n-Kacper Gałan\n-Szymon Gazdowicz"), "");
}

void MenuFrame::Przycisk_Start(wxCommandEvent& event)
{
    if(mapka != NULL && (mapka->czy_wygrana || mapka->czy_przegrana))
    {
        delete mapka;
    }

    mapka = new mapkaFrame(0);
    mapka->Show();
    mapka->SetFocus();
    Timer1.Start();
}

void MenuFrame::Przycisk_quit(wxCommandEvent& event)
{
      if (mapka != NULL)
        mapka -> Close();

      Close();
}




void MenuFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    if(mapka != NULL && (mapka->czy_wygrana || mapka->czy_przegrana)){
        Timer1.Stop();
        if(mapka->czy_wygrana)
            wxMessageBox(wxString::FromUTF8("Wygrałeś"), "");
        else
            wxMessageBox(wxString::FromUTF8("Przegrałeś"), "");

        mapka -> Hide();

        Timer1.Stop();
    }
}
