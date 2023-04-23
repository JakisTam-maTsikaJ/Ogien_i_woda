/***************************************************************
 * Name:      MenuMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-02-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MENUMAIN_H
#define MENUMAIN_H

//(*Headers(MenuFrame)
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statbmp.h>
#include <wx/statusbr.h>
#include <wx/timer.h>
//*)

#include "mapkaMain.h"

class MenuFrame: public wxFrame
{
    public:

        MenuFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MenuFrame();

        mapkaFrame* mapka = NULL;

    private:

        //(*Handlers(MenuFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Przycisk_Start(wxCommandEvent& event);
        void Przycisk_quit(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        //*)

        //(*Identifiers(MenuFrame)
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON1;
        static const long ID_STATICBITMAP1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(MenuFrame)
        wxBitmapButton* BitmapButton1;
        wxBitmapButton* BitmapButton2;
        wxStaticBitmap* StaticBitmap1;
        wxStatusBar* StatusBar1;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MENUMAIN_H
