///-----------------------------------------------------------------
///
/// @file      Bancada8086Frm.h
/// @author    Fabio
/// Created:   21/10/2015 23:49:27
/// @section   DESCRIPTION
///            Bancada8086Frm class declaration
///
///------------------------------------------------------------------

#ifndef __Bancada8086FRM_H__
#define __Bancada8086FRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/panel.h>
////Header Include End

#include <wx/timer.h>
#define TIMER_ID 100

////Dialog Style Start
#undef Bancada8086Frm_STYLE
#define Bancada8086Frm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Bancada8086Frm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();

	public:
		Bancada8086Frm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT(PROGNAME), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Bancada8086Frm_STYLE);
		virtual ~Bancada8086Frm();
		void WxBitmapButton1Click(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxButton3Click(wxCommandEvent& event);
		void WxButton4Click(wxCommandEvent& event);
		void WxButton5Click(wxCommandEvent& event);
      void OnTimer(wxTimerEvent& event);  
		
	private:

      wxTimer m_timer;
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		////GUI Control Declaration End
		wxTextCtrl *WxEdit6;
		wxTextCtrl *WxEdit5;
		wxTextCtrl *WxEdit4;
		wxTextCtrl *WxEdit3;
		wxTextCtrl *WxEdit2;
		wxTextCtrl *WxEdit1;
		wxStaticBitmap *WxStaticBitmap8;
		wxStaticBitmap *WxStaticBitmap7;
		wxStaticBitmap *WxStaticBitmap6;
		wxStaticBitmap *WxStaticBitmap5;
		wxStaticBitmap *WxStaticBitmap4;
		wxStaticBitmap *WxStaticBitmap3;
		wxStaticBitmap *WxStaticBitmap2;
		wxStaticBitmap *WxStaticBitmap1;
		wxButton *WxButton5;
		wxButton *WxButton4;
		wxButton *WxButton3;
		wxButton *WxButton2;
		wxButton *WxButton1;
		wxStaticText *WxStaticText23;
		wxStaticText *WxStaticText22;
		wxStaticText *WxStaticText21;
		wxStaticText *WxStaticText20;
		wxStaticText *WxStaticText19;
		wxStaticText *WxStaticText18;
		wxStaticText *WxStaticText17;
		wxStaticText *WxStaticText16;
		wxStaticText *WxStaticText15;
		wxStaticText *WxStaticText14;
		wxStaticText *WxStaticText13;
		wxStaticText *WxStaticText12;
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText9;
		wxStaticText *WxStaticText8;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxBitmapButton *WxBitmapButton8;
		wxBitmapButton *WxBitmapButton7;
		wxBitmapButton *WxBitmapButton6;
		wxBitmapButton *WxBitmapButton5;
		wxBitmapButton *WxBitmapButton4;
		wxBitmapButton *WxBitmapButton3;
		wxBitmapButton *WxBitmapButton2;
		wxBitmapButton *WxBitmapButton1;
		wxPanel *WxPanel1;
		////GUI Control Declaration End

	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			////GUI Enum Control ID End
			////GUI Enum Control ID Start
			ID_WXEDIT6 = 1036,
			ID_WXEDIT5 = 1035,
			ID_WXEDIT4 = 1030,
			ID_WXEDIT3 = 1029,
			ID_WXEDIT2 = 1018,
			ID_WXEDIT1 = 1015,
			ID_WXSTATICBITMAP8 = 1028,
			ID_WXSTATICBITMAP7 = 1027,
			ID_WXSTATICBITMAP6 = 1026,
			ID_WXSTATICBITMAP5 = 1025,
			ID_WXSTATICBITMAP4 = 1024,
			ID_WXSTATICBITMAP3 = 1023,
			ID_WXSTATICBITMAP2 = 1022,
			ID_WXSTATICBITMAP1 = 1021,
			ID_WXBUTTON5 = 1095,
			ID_WXBUTTON4 = 1092,
			ID_WXBUTTON3 = 1091,
			ID_WXBUTTON2 = 1090,
			ID_WXBUTTON1 = 1019,
			ID_WXSTATICTEXT23 = 1094,
			ID_WXSTATICTEXT22 = 1093,
			ID_WXSTATICTEXT21 = 1089,
			ID_WXSTATICTEXT20 = 1088,
			ID_WXSTATICTEXT19 = 1087,
			ID_WXSTATICTEXT18 = 1086,
			ID_WXSTATICTEXT17 = 1085,
			ID_WXSTATICTEXT16 = 1084,
			ID_WXSTATICTEXT15 = 1083,
			ID_WXSTATICTEXT14 = 1082,
			ID_WXSTATICTEXT13 = 1053,
			ID_WXSTATICTEXT12 = 1052,
			ID_WXSTATICTEXT11 = 1051,
			ID_WXSTATICTEXT10 = 1050,
			ID_WXSTATICTEXT9 = 1043,
			ID_WXSTATICTEXT8 = 1042,
			ID_WXSTATICTEXT7 = 1040,
			ID_WXSTATICTEXT6 = 1039,
			ID_WXSTATICTEXT5 = 1038,
			ID_WXSTATICTEXT4 = 1037,
			ID_WXSTATICTEXT3 = 1034,
			ID_WXSTATICTEXT2 = 1017,
			ID_WXSTATICTEXT1 = 1016,
			ID_WXBITMAPBUTTON8 = 1014,
			ID_WXBITMAPBUTTON7 = 1013,
			ID_WXBITMAPBUTTON6 = 1012,
			ID_WXBITMAPBUTTON5 = 1011,
			ID_WXBITMAPBUTTON4 = 1010,
			ID_WXBITMAPBUTTON3 = 1009,
			ID_WXBITMAPBUTTON2 = 1008,
			ID_WXBITMAPBUTTON1 = 1006,
			ID_WXPANEL1 = 1005,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
    	void charToBin(char bin[10], unsigned char val);
      void SetTextBoxPortaC0H(unsigned char val);
      void SetTextBoxChaves(unsigned char val);
    	void SetTextBoxLeds(unsigned char val);
    	void ReadBus();
    	void UpdateLeds(unsigned char val);
    	unsigned char ReadIObyte(long lPORT_NUM);
    	unsigned int ReadIOword(long lPORT_NUM);
    	void WriteIObyte(long lPORT_NUM, unsigned char uValue);
    	void WriteInterrupt(long interrupt, unsigned char uValue);
    	void WriteIOword(long lPORT_NUM, unsigned int iValue);
      int CreateFiles();
      int ReadIniFile();
      void FileNotFound(char sFile[]);
    	void FileIniNotFound();
};

#endif
