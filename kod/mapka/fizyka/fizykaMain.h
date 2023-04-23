/***************************************************************
 * Name:      fizykaMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-01-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef FIZYKAMAIN_H
#define FIZYKAMAIN_H

//(*Headers(fizykaFrame)
#include <wx/frame.h>
#include <wx/statbmp.h>
//*)

#include <wx/wx.h>

class Kierunek{
    public:
        bool lewo, prawo, gora, dol;
        int skok;
        int klatka;
        Kierunek() {

            lewo = prawo = gora = dol = false;
            skok = 0;
            klatka = 0;
        }
};

class Animacja {
    public:
        wxBitmap LewoLewa;
        wxBitmap LewoPrawa;
        wxBitmap LewoStoi;
        wxBitmap LewoMruga;
        wxBitmap PrawoLewa;
        wxBitmap PrawoPrawa;
        wxBitmap PrawoStoi;
        wxBitmap PrawoMruga;
        Animacja(std::string sciezka) {

                LewoLewa = wxBitmap(wxImage(sciezka + "/lewoLewa.png"));
                LewoPrawa = wxBitmap(wxImage(sciezka + "/lewoPrawa.png"));
                LewoStoi = wxBitmap(wxImage(sciezka + "/lewoStoi.png"));
                LewoMruga = wxBitmap(wxImage(sciezka + "/lewoMruga.png"));

                PrawoLewa = wxBitmap(wxImage(sciezka + "/prawoLewa.png"));
                PrawoPrawa = wxBitmap(wxImage(sciezka + "/prawoPrawa.png"));
                PrawoStoi = wxBitmap(wxImage(sciezka + "/prawoStoi.png"));
                PrawoMruga = wxBitmap(wxImage(sciezka + "/prawoMruga.png"));
        }
};

class fizykaFrame: public wxFrame
{
    public:

        fizykaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~fizykaFrame();

    protected:

        Kierunek kierunki[2] = { Kierunek(), Kierunek() };
        Animacja animacje[2] = { Animacja("img/woda"), Animacja("img/ogien") };

        int n_graczy;
        wxStaticBitmap** gracze;

        int n_przeszkod;
        wxStaticBitmap** przeszkody;

        bool kolizja_poziom(wxStaticBitmap*, wxStaticBitmap*, double przesuniecie_x = 0);
        bool kolizja_pion(wxStaticBitmap*, wxStaticBitmap*, double przesuniecie_y = 0);

        void oczysc();

        wxPanel* mainPane;
        void OnKeyboardKeyUp(wxKeyEvent&);
        void OnKeyboardKeyDown(wxKeyEvent&);

        wxTimer Timer;
        void OnTimerTrigger(wxTimerEvent& event);

    private:



        //(*Handlers(fizykaFrame)
        void OnClose(wxCloseEvent& event);
        void OnStaticBitmap3Paint(wxPaintEvent& event);
        //*)

        static const long ID_TIMER;
        //(*Identifiers(fizykaFrame)
        static const long ID_JASZCZUR;
        static const long ID_SMOK;
        static const long ID_STATICBITMAP2;
        static const long ID_STATICBITMAP3;
        static const long ID_IMAGEPANEL1;
        //*)

        //(*Declarations(fizykaFrame)
        wxStaticBitmap* Jaszczur;
        wxStaticBitmap* Smok;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBitmap* StaticBitmap2;
        wxStaticBitmap* StaticBitmap3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // FIZYKAMAIN_H
