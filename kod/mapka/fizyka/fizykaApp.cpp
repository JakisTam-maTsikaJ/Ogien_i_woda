/***************************************************************
 * Name:      fizykaApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-01-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "fizykaApp.h"

//(*AppHeaders
#include "fizykaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(fizykaApp);

bool fizykaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	fizykaFrame* Frame = new fizykaFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
