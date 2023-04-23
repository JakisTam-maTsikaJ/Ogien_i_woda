/***************************************************************
 * Name:      MenuApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-02-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "MenuApp.h"

//(*AppHeaders
#include "MenuMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MenuApp);

bool MenuApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MenuFrame* Frame = new MenuFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
