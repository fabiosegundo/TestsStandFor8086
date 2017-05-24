//---------------------------------------------------------------------------
//
// Name:        Bancada8086App.h
// Author:      Fabio
// Created:     21/10/2015 23:49:26
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __Bancada8086FRMApp_h__
#define __Bancada8086FRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

#include <errno.h>
#include <wx/snglinst.h>

#define PROGNAME "Tests Stand for 8086"
#define EMU8086EXEFILE L"emu8086.exe"

class Bancada8086FrmApp : public wxApp
{
   private:
      wxSingleInstanceChecker* m_checker;      
	public:
		bool OnInit();
		int OnExit();
};

#endif
