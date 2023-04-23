/***************************************************************
 * Name:      mapkaMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-01-18
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MAPKAMAIN_H
#define MAPKAMAIN_H
#include "fizykaMain.h"
//(*Headers(mapkaFrame)
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/timer.h>
//*)

class mapkaFrame: public fizykaFrame
{
    public:

        mapkaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~mapkaFrame();

        void koniec_gry();

        bool czy_wygrana, czy_przegrana;

    private:

        void Create(wxWindow*, wxWindowID, const wxChar*, wxPoint, wxSize, long style, const wxString&) {}


        //(*Handlers(mapkaFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnTimer1Trigger1(wxTimerEvent& event);
        //*)

        //(*Identifiers(mapkaFrame)
        static const long ID_STATICBITMAP1;
        static const long ID_STATICBITMAP5;
        static const long ID_STATICBITMAP6;
        static const long ID_STATICBITMAP7;
        static const long ID_STATICBITMAP8;
        static const long ID_STATICBITMAP9;
        static const long ID_STATICBITMAP3;
        static const long ID_STATICBITMAP4;
        static const long ID_STATICBITMAP2;
        static const long ID_STATICBITMAP10;
        static const long ID_STATICBITMAP11;
        static const long ID_STATICBITMAP12;
        static const long ID_STATICBITMAP13;
        static const long ID_STATICBITMAP14;
        static const long ID_STATICBITMAP15;
        static const long ID_STATICBITMAP16;
        static const long ID_STATICBITMAP17;
        static const long ID_STATICBITMAP18;
        static const long ID_STATICBITMAP19;
        static const long ID_STATICBITMAP20;
        static const long ID_STATICBITMAP21;
        static const long ID_STATICBITMAP22;
        static const long ID_STATICBITMAP23;
        static const long ID_STATICBITMAP24;
        static const long ID_STATICBITMAP25;
        static const long ID_STATICBITMAP28;
        static const long ID_STATICBITMAP29;
        static const long ID_STATICBITMAP30;
        static const long ID_STATICBITMAP31;
        static const long ID_STATICBITMAP33;
        static const long ID_STATICBITMAP34;
        static const long ID_STATICBITMAP35;
        static const long ID_STATICBITMAP36;
        static const long ID_STATICBITMAP32;
        static const long ID_STATICBITMAP37;
        static const long ID_STATICBITMAP26;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(mapkaFrame)
        wxStaticBitmap* StaticBitmap10;
        wxStaticBitmap* StaticBitmap11;
        wxStaticBitmap* StaticBitmap12;
        wxStaticBitmap* StaticBitmap13;
        wxStaticBitmap* StaticBitmap14;
        wxStaticBitmap* StaticBitmap15;
        wxStaticBitmap* StaticBitmap16;
        wxStaticBitmap* StaticBitmap17;
        wxStaticBitmap* StaticBitmap18;
        wxStaticBitmap* StaticBitmap19;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBitmap* StaticBitmap20;
        wxStaticBitmap* StaticBitmap21;
        wxStaticBitmap* StaticBitmap22;
        wxStaticBitmap* StaticBitmap23;
        wxStaticBitmap* StaticBitmap24;
        wxStaticBitmap* StaticBitmap26;
        wxStaticBitmap* StaticBitmap27;
        wxStaticBitmap* StaticBitmap28;
        wxStaticBitmap* StaticBitmap29;
        wxStaticBitmap* StaticBitmap2;
        wxStaticBitmap* StaticBitmap30;
        wxStaticBitmap* StaticBitmap31;
        wxStaticBitmap* StaticBitmap32;
        wxStaticBitmap* StaticBitmap33;
        wxStaticBitmap* StaticBitmap3;
        wxStaticBitmap* StaticBitmap4;
        wxStaticBitmap* StaticBitmap5;
        wxStaticBitmap* StaticBitmap6;
        wxStaticBitmap* StaticBitmap7;
        wxStaticBitmap* StaticBitmap8;
        wxStaticBitmap* StaticBitmap9;
        wxStaticBitmap* kwas;
        wxStaticBitmap* lawa1;
        wxStaticBitmap* lawa;
        wxStaticBitmap* woda;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MAPKAMAIN_H
