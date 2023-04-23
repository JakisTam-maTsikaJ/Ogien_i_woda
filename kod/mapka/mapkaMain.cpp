/***************************************************************
 * Name:      mapkaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-01-18
 * Copyright:  ()
 * License:
 **************************************************************/

#include "mapkaMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(mapkaFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)
#include <wx/config.h>

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

//(*IdInit(mapkaFrame)
const long mapkaFrame::ID_STATICBITMAP1 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP5 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP6 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP7 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP8 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP9 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP3 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP4 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP2 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP10 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP11 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP12 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP13 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP14 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP15 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP16 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP17 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP18 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP19 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP20 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP21 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP22 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP23 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP24 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP25 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP28 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP29 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP30 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP31 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP33 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP34 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP35 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP36 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP32 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP37 = wxNewId();
const long mapkaFrame::ID_STATICBITMAP26 = wxNewId();
const long mapkaFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mapkaFrame,wxFrame)
    //(*EventTable(mapkaFrame)
    //*)
END_EVENT_TABLE()

mapkaFrame::mapkaFrame(wxWindow* parent,wxWindowID id):fizykaFrame(parent, id)
{

    //(*Initialize(mapkaFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(899,747));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxPoint(0,696), wxSize(904,64), 0, _T("ID_STATICBITMAP1"));
    StaticBitmap1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap5 = new wxStaticBitmap(this, ID_STATICBITMAP5, wxNullBitmap, wxPoint(0,-8), wxSize(24,720), 0, _T("ID_STATICBITMAP5"));
    StaticBitmap5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap6 = new wxStaticBitmap(this, ID_STATICBITMAP6, wxNullBitmap, wxPoint(24,0), wxSize(880,24), 0, _T("ID_STATICBITMAP6"));
    StaticBitmap6->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap7 = new wxStaticBitmap(this, ID_STATICBITMAP7, wxNullBitmap, wxPoint(864,24), wxSize(64,672), 0, _T("ID_STATICBITMAP7"));
    StaticBitmap7->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap8 = new wxStaticBitmap(this, ID_STATICBITMAP8, wxNullBitmap, wxPoint(24,24), wxDefaultSize, 0, _T("ID_STATICBITMAP8"));
    StaticBitmap8->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap9 = new wxStaticBitmap(this, ID_STATICBITMAP9, wxNullBitmap, wxPoint(16,24), wxSize(848,672), 0, _T("ID_STATICBITMAP9"));
    StaticBitmap9->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    StaticBitmap3 = new wxStaticBitmap(this, ID_STATICBITMAP3, wxNullBitmap, wxPoint(520,368), wxSize(56,56), 0, _T("ID_STATICBITMAP3"));
    StaticBitmap4 = new wxStaticBitmap(this, ID_STATICBITMAP4, wxNullBitmap, wxPoint(16,576), wxSize(120,32), 0, _T("ID_STATICBITMAP4"));
    StaticBitmap4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap2 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxNullBitmap, wxPoint(648,448), wxSize(56,56), 0, _T("ID_STATICBITMAP2"));
    lawa = new wxStaticBitmap(this, ID_STATICBITMAP10, wxNullBitmap, wxPoint(264,696), wxSize(90,40), 0, _T("ID_STATICBITMAP10"));
    lawa->SetBackgroundColour(wxColour(255,0,0));
    woda = new wxStaticBitmap(this, ID_STATICBITMAP11, wxNullBitmap, wxPoint(464,696), wxSize(90,40), 0, _T("ID_STATICBITMAP11"));
    woda->SetBackgroundColour(wxColour(0,255,255));
    StaticBitmap10 = new wxStaticBitmap(this, ID_STATICBITMAP12, wxNullBitmap, wxPoint(784,600), wxSize(88,32), 0, _T("ID_STATICBITMAP12"));
    StaticBitmap10->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap11 = new wxStaticBitmap(this, ID_STATICBITMAP13, wxNullBitmap, wxPoint(600,544), wxSize(112,32), 0, _T("ID_STATICBITMAP13"));
    StaticBitmap11->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap12 = new wxStaticBitmap(this, ID_STATICBITMAP14, wxNullBitmap, wxPoint(592,496), wxSize(48,80), 0, _T("ID_STATICBITMAP14"));
    StaticBitmap12->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap13 = new wxStaticBitmap(this, ID_STATICBITMAP15, wxNullBitmap, wxPoint(472,472), wxSize(128,48), 0, _T("ID_STATICBITMAP15"));
    StaticBitmap13->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap14 = new wxStaticBitmap(this, ID_STATICBITMAP16, wxNullBitmap, wxPoint(16,440), wxSize(480,56), 0, _T("ID_STATICBITMAP16"));
    StaticBitmap14->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    kwas = new wxStaticBitmap(this, ID_STATICBITMAP17, wxNullBitmap, wxPoint(320,440), wxSize(74,40), 0, _T("ID_STATICBITMAP17"));
    kwas->SetBackgroundColour(wxColour(0,255,128));
    StaticBitmap16 = new wxStaticBitmap(this, ID_STATICBITMAP18, wxNullBitmap, wxPoint(688,280), wxSize(88,32), 0, _T("ID_STATICBITMAP18"));
    StaticBitmap16->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap17 = new wxStaticBitmap(this, ID_STATICBITMAP19, wxNullBitmap, wxPoint(192,256), wxSize(80,40), 0, _T("ID_STATICBITMAP19"));
    StaticBitmap17->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap18 = new wxStaticBitmap(this, ID_STATICBITMAP20, wxNullBitmap, wxPoint(224,184), wxSize(688,56), 0, _T("ID_STATICBITMAP20"));
    StaticBitmap18->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap19 = new wxStaticBitmap(this, ID_STATICBITMAP21, wxNullBitmap, wxPoint(344,184), wxSize(32,24), 0, _T("ID_STATICBITMAP21"));
    StaticBitmap19->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap20 = new wxStaticBitmap(this, ID_STATICBITMAP22, wxNullBitmap, wxPoint(352,176), wxSize(16,16), 0, _T("ID_STATICBITMAP22"));
    StaticBitmap20->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    lawa1 = new wxStaticBitmap(this, ID_STATICBITMAP23, wxNullBitmap, wxPoint(456,184), wxSize(90,40), 0, _T("ID_STATICBITMAP23"));
    lawa1->SetBackgroundColour(wxColour(255,0,0));
    StaticBitmap22 = new wxStaticBitmap(this, ID_STATICBITMAP24, wxNullBitmap, wxPoint(600,112), wxSize(32,88), 0, _T("ID_STATICBITMAP24"));
    StaticBitmap22->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap23 = new wxStaticBitmap(this, ID_STATICBITMAP25, wxNullBitmap, wxPoint(608,120), wxSize(16,72), 0, _T("ID_STATICBITMAP25"));
    StaticBitmap23->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap26 = new wxStaticBitmap(this, ID_STATICBITMAP28, wxNullBitmap, wxPoint(640,24), wxSize(232,48), 0, _T("ID_STATICBITMAP28"));
    StaticBitmap26->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap27 = new wxStaticBitmap(this, ID_STATICBITMAP29, wxNullBitmap, wxPoint(0,144), wxSize(104,32), 0, _T("ID_STATICBITMAP29"));
    StaticBitmap27->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap28 = new wxStaticBitmap(this, ID_STATICBITMAP30, wxNullBitmap, wxPoint(8,144), wxSize(40,48), 0, _T("ID_STATICBITMAP30"));
    StaticBitmap28->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap29 = new wxStaticBitmap(this, ID_STATICBITMAP31, wxNullBitmap, wxPoint(24,40), wxSize(64,112), 0, _T("ID_STATICBITMAP31"));
    StaticBitmap29->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap21 = new wxStaticBitmap(this, ID_STATICBITMAP33, wxNullBitmap, wxPoint(120,296), wxSize(96,32), 0, _T("ID_STATICBITMAP33"));
    StaticBitmap21->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap31 = new wxStaticBitmap(this, ID_STATICBITMAP34, wxNullBitmap, wxPoint(0,432), wxSize(48,24), 0, _T("ID_STATICBITMAP34"));
    StaticBitmap31->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap32 = new wxStaticBitmap(this, ID_STATICBITMAP35, wxNullBitmap, wxPoint(688,344), wxSize(88,32), 0, _T("ID_STATICBITMAP35"));
    StaticBitmap32->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap33 = new wxStaticBitmap(this, ID_STATICBITMAP36, wxNullBitmap, wxPoint(24,352), wxSize(24,32), 0, _T("ID_STATICBITMAP36"));
    StaticBitmap33->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap15 = new wxStaticBitmap(this, ID_STATICBITMAP32, wxNullBitmap, wxPoint(728,176), wxDefaultSize, 0, _T("ID_STATICBITMAP32"));
    StaticBitmap15->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap30 = new wxStaticBitmap(this, ID_STATICBITMAP37, wxNullBitmap, wxPoint(144,624), wxSize(32,18), 0, _T("ID_STATICBITMAP37"));
    StaticBitmap30->Hide();
    StaticBitmap30->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticBitmap24 = new wxStaticBitmap(this, ID_STATICBITMAP26, wxNullBitmap, wxPoint(32,512), wxSize(56,56), 0, _T("ID_STATICBITMAP26"));
    StaticBitmap24->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOTEXT));
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(1, false);

    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&mapkaFrame::OnTimer1Trigger1);
    //*)

    oczysc();

    n_graczy = 2;
    gracze = new wxStaticBitmap*[n_graczy] {
        StaticBitmap2, StaticBitmap3
    };

    n_przeszkod = 24;
    przeszkody = new wxStaticBitmap*[n_przeszkod] {
        StaticBitmap1, StaticBitmap4, StaticBitmap5, StaticBitmap6, StaticBitmap7,
        StaticBitmap10, StaticBitmap11, StaticBitmap12, StaticBitmap13, StaticBitmap14,
        StaticBitmap16, StaticBitmap17, StaticBitmap18, StaticBitmap19,
        StaticBitmap20, StaticBitmap23, StaticBitmap27, StaticBitmap21,
        StaticBitmap31, StaticBitmap32, StaticBitmap33, StaticBitmap22, StaticBitmap30, StaticBitmap15
    };
    czy_wygrana = false;
    czy_przegrana = false;
     SetIcon(wxICON(aaaa));
}

mapkaFrame::~mapkaFrame()
{
    //(*Destroy(mapkaFrame)
    //*)
}





void mapkaFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void mapkaFrame::OnTimer1Trigger1(wxTimerEvent& event)
{
//////////////////////////////////////////////////////////////////////////////////////////////////////
    if(kolizja_pion(gracze[0], lawa, +5) && kolizja_poziom(gracze[0], lawa)){
        czy_przegrana = true;
    }

    if(kolizja_pion(gracze[1], woda, +5) && kolizja_poziom(gracze[1], woda)){
        czy_przegrana = true;
    }

    if(kolizja_pion(gracze[0], kwas, +5) && kolizja_poziom(gracze[0], kwas)){
        czy_przegrana = true;
    }

    if(kolizja_pion(gracze[1], kwas, +5) && kolizja_poziom(gracze[1], kwas)){
        czy_przegrana = true;
    }

    if(kolizja_pion(gracze[0], lawa1, +5) && kolizja_poziom(gracze[0], lawa1)){
        czy_przegrana = true;
    }
/////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////


    if(kolizja_pion(gracze[0], StaticBitmap20) && kolizja_poziom(gracze[0], StaticBitmap20)
       || kolizja_pion(gracze[1], StaticBitmap20) && kolizja_poziom(gracze[1], StaticBitmap20)){

        if(kolizja_pion(gracze[0], StaticBitmap20) && kolizja_poziom(gracze[0], StaticBitmap20)){
            StaticBitmap23->Hide();
            StaticBitmap22->Hide();

            if(kierunki[0].prawo){
                gracze[0]->Move(StaticBitmap20->GetPosition().x + StaticBitmap20->GetSize().x, gracze[0]->GetPosition().y);
                kierunki[0].prawo = false;
            }
            if(kierunki[0].lewo){
                gracze[0]->Move(StaticBitmap20->GetPosition().x - gracze[0]->GetSize().x, gracze[0]->GetPosition().y);
                kierunki[0].lewo = false;
            }
        }

        if(kolizja_pion(gracze[1], StaticBitmap20) && kolizja_poziom(gracze[1], StaticBitmap20)){
            StaticBitmap23->Hide();
            StaticBitmap22->Hide();


            if(kierunki[1].prawo){
                gracze[1]->Move(StaticBitmap20->GetPosition().x + StaticBitmap20->GetSize().x, gracze[1]->GetPosition().y);
                kierunki[1].prawo = false;
            }
            if(kierunki[1].lewo){
                gracze[1]->Move(StaticBitmap20->GetPosition().x - gracze[1]->GetSize().x, gracze[1]->GetPosition().y);
                kierunki[1].lewo = false;
            }
        }
    }

    else{
        StaticBitmap23->Show();
        StaticBitmap22->Show();
    }




    if( (kolizja_pion(gracze[0], StaticBitmap22) && kolizja_poziom(gracze[0], StaticBitmap22))
                && StaticBitmap22->GetPosition().x+(StaticBitmap22->GetSize().x)/2 >= (gracze[0]->GetPosition().x+(gracze[0]->GetSize().x)/2 )) {
        if(StaticBitmap22->IsShown())
            gracze[0]->Move(StaticBitmap22->GetPosition().x - gracze[0]->GetSize().x, gracze[0]->GetPosition().y);
    }
    if( (kolizja_pion(gracze[0], StaticBitmap22) && kolizja_poziom(gracze[0], StaticBitmap22)
                || kolizja_pion(gracze[0], StaticBitmap23) && kolizja_poziom(gracze[0], StaticBitmap23) )
                && StaticBitmap22->GetPosition().x+(StaticBitmap22->GetSize().x)/2 < (gracze[0]->GetPosition().x+(gracze[0]->GetSize().x)/2 )) {
        if(StaticBitmap22->IsShown())
            gracze[0]->Move(StaticBitmap22->GetPosition().x + StaticBitmap22->GetSize().x+1, gracze[0]->GetPosition().y);
    }


    if( (kolizja_pion(gracze[1], StaticBitmap22) && kolizja_poziom(gracze[1], StaticBitmap22)
                || kolizja_pion(gracze[1], StaticBitmap23) && kolizja_poziom(gracze[1], StaticBitmap23) )
                && StaticBitmap22->GetPosition().x+(StaticBitmap22->GetSize().x)/2 >= (gracze[1]->GetPosition().x+(gracze[1]->GetSize().x)/2 )) {
        if(StaticBitmap22->IsShown())
            gracze[1]->Move(StaticBitmap22->GetPosition().x - gracze[1]->GetSize().x, gracze[1]->GetPosition().y);
    }
    if( (kolizja_pion(gracze[1], StaticBitmap22) && kolizja_poziom(gracze[1], StaticBitmap22)
                || kolizja_pion(gracze[1], StaticBitmap23) && kolizja_poziom(gracze[1], StaticBitmap23) )
                && StaticBitmap22->GetPosition().x+(StaticBitmap22->GetSize().x)/2 < (gracze[1]->GetPosition().x+(gracze[1]->GetSize().x)/2 )) {
        if(StaticBitmap22->IsShown())
            gracze[1]->Move(StaticBitmap22->GetPosition().x + StaticBitmap22->GetSize().x+1, gracze[1]->GetPosition().y);
    }
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

    if(kolizja_pion(gracze[0], StaticBitmap15) && kolizja_poziom(gracze[0], StaticBitmap15)
       || kolizja_pion(gracze[1], StaticBitmap15) && kolizja_poziom(gracze[1], StaticBitmap15)){

        if(kolizja_pion(gracze[0], StaticBitmap15) && kolizja_poziom(gracze[0], StaticBitmap15)){
            StaticBitmap30->Show();

            if(kierunki[0].prawo){
                gracze[0]->Move(StaticBitmap15->GetPosition().x + StaticBitmap15->GetSize().x, gracze[0]->GetPosition().y);
                kierunki[0].prawo = false;
            }
            if(kierunki[0].lewo){
                gracze[0]->Move(StaticBitmap15->GetPosition().x - gracze[0]->GetSize().x, gracze[0]->GetPosition().y);
                kierunki[0].lewo = false;
            }
        }

        if(kolizja_pion(gracze[1], StaticBitmap15) && kolizja_poziom(gracze[1], StaticBitmap15)){
            StaticBitmap30->Show();


            if(kierunki[1].prawo){
                gracze[1]->Move(StaticBitmap15->GetPosition().x + StaticBitmap15->GetSize().x, gracze[1]->GetPosition().y);
                kierunki[1].prawo = false;
            }
            if(kierunki[1].lewo){
                gracze[1]->Move(StaticBitmap15->GetPosition().x - gracze[1]->GetSize().x, gracze[1]->GetPosition().y);
                kierunki[1].lewo = false;
            }
        }
    }

    else{
        StaticBitmap30->Hide();
    }


    if(kolizja_pion(gracze[0], StaticBitmap24) && kolizja_poziom(gracze[0], StaticBitmap24)
       ||kolizja_pion(gracze[1], StaticBitmap24) && kolizja_poziom(gracze[1], StaticBitmap24)){

                Timer1.Stop();


                czy_wygrana = true;

       }

}


