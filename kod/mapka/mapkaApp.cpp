/***************************************************************
 * Name:      mapkaApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-01-18
 * Copyright:  ()
 * License:
 **************************************************************/

#include "mapkaApp.h"

//(*AppHeaders
#include "mapkaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(mapkaApp);

bool mapkaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	mapkaFrame* Frame = new mapkaFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
