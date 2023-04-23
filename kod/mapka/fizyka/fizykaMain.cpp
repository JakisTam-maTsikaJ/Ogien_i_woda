/***************************************************************
 * Name:      fizykaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-01-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "fizykaMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(fizykaFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

//(*IdInit(fizykaFrame)
const long fizykaFrame::ID_JASZCZUR = wxNewId();
const long fizykaFrame::ID_SMOK = wxNewId();
const long fizykaFrame::ID_STATICBITMAP2 = wxNewId();
const long fizykaFrame::ID_STATICBITMAP3 = wxNewId();
const long fizykaFrame::ID_IMAGEPANEL1 = wxNewId();
//*)

const long fizykaFrame::ID_TIMER = wxNewId();

#include <wx/wx.h>

BEGIN_EVENT_TABLE(fizykaFrame,wxFrame)
    //(*EventTable(fizykaFrame)
    //*)
END_EVENT_TABLE()

fizykaFrame::fizykaFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(fizykaFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(768,517));
    Jaszczur = new wxStaticBitmap(this, ID_JASZCZUR, wxNullBitmap, wxPoint(192,368), wxSize(128,112), 0, _T("ID_JASZCZUR"));
    Smok = new wxStaticBitmap(this, ID_SMOK, wxNullBitmap, wxPoint(560,264), wxSize(80,72), 0, _T("ID_SMOK"));
    StaticBitmap2 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxNullBitmap, wxPoint(0,488), wxSize(800,112), 0, _T("ID_STATICBITMAP2"));
    StaticBitmap2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap3 = new wxStaticBitmap(this, ID_STATICBITMAP3, wxNullBitmap, wxPoint(416,296), wxSize(88,56), 0, _T("ID_STATICBITMAP3"));
    StaticBitmap3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap1 = new wxStaticBitmap(this, ID_IMAGEPANEL1, wxNullBitmap, wxPoint(560,392), wxSize(72,60), 0, _T("ID_IMAGEPANEL1"));
    StaticBitmap1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));

    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&fizykaFrame::OnClose);
    //*)

    Timer.SetOwner(this, ID_TIMER);
    Timer.Start(15, false);
    Connect(ID_TIMER,wxEVT_TIMER,(wxObjectEventFunction)&fizykaFrame::OnTimerTrigger);

    // https://wiki.wxwidgets.org/Catching_key_events_globally
    // żeby łapac eventy klikania trzeba zrobić pane
    mainPane= new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
    mainPane->Bind(wxEVT_KEY_DOWN, &fizykaFrame::OnKeyboardKeyDown, this); // i zbindować
    mainPane->Bind(wxEVT_KEY_UP, &fizykaFrame::OnKeyboardKeyUp, this); // i zbindować

    n_graczy = 2;
    gracze = new wxStaticBitmap*[n_graczy] {
        Jaszczur, Smok
    };

    n_przeszkod = 3;
    przeszkody = new wxStaticBitmap*[n_przeszkod] {
        StaticBitmap1, StaticBitmap2, StaticBitmap3
    };
       SetIcon(wxICON(aaaa));
}

void fizykaFrame::oczysc() {

    for (int g = 0; g < n_graczy; g++)
        gracze[g] -> Destroy();

    n_graczy = 0;

    for (int p = 0; p < n_przeszkod; p++)
        przeszkody[p] -> Destroy();

    n_przeszkod = 0;
}

void fizykaFrame::OnClose(wxCloseEvent& event){ Close();}
fizykaFrame::~fizykaFrame() {
    //(*Destroy(fizykaFrame)
    //*)
}

void fizykaFrame::OnTimerTrigger(wxTimerEvent& event) {

    int z_jaka_kolizja;
    int szybkosc = 10;
    int sila_skoku = 10;
    bool czy_kol_pion = false;
    for (int g = 0; g < n_graczy; g++) {

        kierunki[g].klatka = (kierunki[g].klatka + 1) % + 8;

        // Poruszanie
        if (kierunki[g].lewo || kierunki[g].prawo) {

            int zwrot = 1;
            if (kierunki[g].lewo) {

                zwrot = -1;

                switch (kierunki[g].klatka) {

                    case 0: gracze[g] -> SetBitmap(animacje[g].LewoLewa); break;
                    case 1: gracze[g] -> SetBitmap(animacje[g].LewoPrawa); break;
                }
            } else switch (kierunki[g].klatka) {

                case 0: gracze[g] -> SetBitmap(animacje[g].PrawoLewa); break;
                case 1: gracze[g] -> SetBitmap(animacje[g].PrawoPrawa); break;
            }


            int przesuniecie_x = zwrot * szybkosc;

            bool kolizja = false;
            for (int p = 0; p < n_przeszkod && !kolizja; p++) {

                kolizja =
                    kolizja_poziom(gracze[g], przeszkody[p], przesuniecie_x) &&
                    kolizja_pion(gracze[g], przeszkody[p], 0);

                if(kolizja == true && przeszkody[p]->IsShown() == false){
                    kolizja = false;
                }

                if(kolizja == true)
                    z_jaka_kolizja = p;
            }

            if(kolizja && (
                kierunki[g].lewo && gracze[g] -> GetPosition().x + gracze[g] -> GetSize().x > 0 ||
                kierunki[g].prawo && gracze[g] -> GetPosition().x + gracze[g] -> GetSize().x < GetClientSize().x
            )) {


                    if(przesuniecie_x > 0)//////////////////////////////////////////////////////////
                    {
                        gracze[g]->Move( przeszkody[z_jaka_kolizja]->GetPosition().x - gracze[g]->GetSize().x, gracze[g] -> GetPosition().y + 0);///////////
                    }
                    if(przesuniecie_x < 0)
                    {
                        gracze[g]->Move( przeszkody[z_jaka_kolizja]->GetPosition().x + przeszkody[z_jaka_kolizja]->GetSize().x, gracze[g] -> GetPosition().y + 0);
                    }///////////////////////////////////////////////////////////////////////////
            }


            if (!kolizja && (
                kierunki[g].lewo && gracze[g] -> GetPosition().x > 0 ||
                kierunki[g].prawo && gracze[g] -> GetPosition().x + gracze[g] -> GetSize().x < GetClientSize().x
            )) {

                gracze[g] -> Move(
                    gracze[g] -> GetPosition().x + przesuniecie_x,
                    gracze[g] -> GetPosition().y + 0
                );
            }
        } else switch (kierunki[g].klatka) {

            case 0: gracze[g] -> SetBitmap(animacje[g].PrawoStoi); break;
            case 1: gracze[g] -> SetBitmap(animacje[g].PrawoMruga); break;
        }

        // Skakanie i spadanie
        if (kierunki[g].skok > 0) {

            kierunki[g].skok--;

            int przesuniecie_y = -szybkosc;
            bool kolizja = false;
            for (int p = 0; p < n_przeszkod && !kolizja; p++) {

                kolizja =
                    kolizja_poziom(gracze[g], przeszkody[p], 0) &&
                    kolizja_pion(gracze[g], przeszkody[p], przesuniecie_y); /////////////////////////////////////////////////////////////////////


                if(kolizja == true && przeszkody[p]->IsShown() == false){
                    kolizja = false;
                }

                    if(kolizja == true)
                        z_jaka_kolizja = p;
            }

            if (!kolizja) {

                gracze[g] -> Move( gracze[g] -> GetPosition().x + 0,     gracze[g] -> GetPosition().y + przesuniecie_y );

            } else {

                kierunki[g].skok = 0;

            }

        } else {

            int przesuniecie_y = szybkosc;
            bool kolizja = false;
            for (int p = 0; p < n_przeszkod && !kolizja; p++) {

                kolizja =
                    kolizja_poziom(gracze[g], przeszkody[p], 0) &&
                    kolizja_pion(gracze[g], przeszkody[p], przesuniecie_y);

                if(kolizja)
                    z_jaka_kolizja = p;

            }


            if (!kolizja && gracze[g] -> GetPosition().y + gracze[g] -> GetSize().y < GetClientSize().y) {

                gracze[g] -> Move(
                    gracze[g] -> GetPosition().x + 0,
                    gracze[g] -> GetPosition().y + przesuniecie_y
                );

            } else if (kierunki[g].gora)
                kierunki[g].skok = sila_skoku;

            if(kolizja && gracze[g] -> GetPosition().y + gracze[g] -> GetSize().y < GetClientSize().y)
            {
                gracze[g] -> Move(
                    gracze[g] -> GetPosition().x + 0,
                    przeszkody[z_jaka_kolizja]->GetPosition().y - gracze[g]->GetSize().y
                );

            }

        }

    }

}

/// gdy ktoś naciska na przycisk
void fizykaFrame::OnKeyboardKeyDown(wxKeyEvent& event) {

    switch((int)event.GetKeyCode()) {

        // GRACZ 1
        case 87:
            kierunki[0].gora = true;
            break; // W
        case 65:
            kierunki[0].lewo = true;
            break; // A
        case 68:
            kierunki[0].prawo = true;
            break; // D

        // Gracz 2 (strzałki)
        case 315:
            kierunki[1].gora = true;
            break; // góra
        case 314:
            kierunki[1].lewo = true;
            break; // lewo
        case 316:
            kierunki[1].prawo = true;
            break; // prawo
    }

    event.Skip();
}


/// gdy ktoś odklika przycisk
void fizykaFrame::OnKeyboardKeyUp(wxKeyEvent& event) {

    switch((int)event.GetKeyCode()) {

        // GRACZ 1
        case 87:
            kierunki[0].gora = false;
            break; // W
        case 65:
            kierunki[0].lewo = false;
            break; // A
        case 68:
            kierunki[0].prawo = false;
            break; // D

        // Gracz 2 (strzałki)
        case 315:
            kierunki[1].gora = false;
            break; // góra
        case 314:
            kierunki[1].lewo= false;
            break; // lewo
        case 316:
            kierunki[1].prawo = false;
            break; // prawo
    }

    event.Skip();
}


bool fizykaFrame::kolizja_poziom(wxStaticBitmap* gracz, wxStaticBitmap* przeszkoda, double przesuniecie_x) {


    // uderzenie jest wtedy gdy odcinki mają wspólne przedziały pionowo i poziomo
    // początki odcinków
    double
        Ax = gracz -> GetPosition().x + przesuniecie_x,
        Px = przeszkoda -> GetPosition().x;

    //  końce odcinków
    double
        Bx = Ax + gracz -> GetSize().x,
        Rx = Px + przeszkoda -> GetSize().x;

    return (

        // 1. początek jest w odcinku:
        //          A--------B
        //      P---------R
        (Ax > Px && Ax < Rx) ||

        // 2. koniec jest w odcinku:
        //  A--------B
        //      P---------R
        (Bx > Px && Bx < Rx) ||

        // 3. przeszkoda jest mniejsza:
        //     A--------B
        //       P-----R
        (Px >= Ax && Rx <= Bx)
    );
}

bool fizykaFrame::kolizja_pion(wxStaticBitmap* gracz, wxStaticBitmap* przeszkoda, double przesuniecie_y) {

    // uderzenie jest wtedy gdy odcinki mają wspólne przedziały pionowo i poziomo
    // początki odcinków
    double
        Ay = gracz -> GetPosition().y + przesuniecie_y,
        Py = przeszkoda -> GetPosition().y;

    //  końce odcinków
    double
        By = Ay + gracz -> GetSize().y,
        Ry = Py + przeszkoda -> GetSize().y;

    return (

        // 1. początek jest w odcinku:
        //          A--------B
        //      P---------R
        (Ay > Py && Ay < Ry) ||

        // 2. koniec jest w odcinku:
        //  A--------B
        //      P---------R
        (By > Py && By < Ry) ||

        // 3. przeszkoda jest mniejsza:
        //     A--------B
        //       P-----R
        (Py >= Ay && Ry <= By)
    );
}

