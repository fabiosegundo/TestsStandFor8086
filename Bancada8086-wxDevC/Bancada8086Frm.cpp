///-----------------------------------------------------------------
///
/// @file      Bancada8086Frm.cpp
/// Author:    Fabio Rafael Segundo <fabio.segundo@gmail.com>
/// Created:   21/10/2015 23:49:27
/// @section   DESCRIPTION
///            Bancada8086Frm class implementation
///
///------------------------------------------------------------------

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "Bancada8086App.h"
#include "Bancada8086Frm.h"
#include "Images/Bancada8086Frm_frmNewForm_XPM.xpm"
#include "Images/Bancada8086Frm_WxStaticBitmap2_XPM.xpm"
#include "Images/Bancada8086Frm_WxStaticBitmap1_XPM.xpm"
#include "Images/Bancada8086Frm_WxBitmapButton2_XPM.xpm"
#include "Images/Bancada8086Frm_WxBitmapButton1_XPM.xpm"
////Header Include End

//----------------------------------------------------------------------------
// Bancada8086Frm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Bancada8086Frm,wxFrame)
	////Manual Code Start
	////Manual Code End	
	EVT_CLOSE(Bancada8086Frm::OnClose)
	EVT_BUTTON(ID_WXBITMAPBUTTON8,Bancada8086Frm::WxBitmapButton1Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON7,Bancada8086Frm::WxBitmapButton1Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON6,Bancada8086Frm::WxBitmapButton1Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON5,Bancada8086Frm::WxBitmapButton1Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON4,Bancada8086Frm::WxBitmapButton1Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON3,Bancada8086Frm::WxBitmapButton1Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON2,Bancada8086Frm::WxBitmapButton1Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON1,Bancada8086Frm::WxBitmapButton1Click)
	EVT_BUTTON(ID_WXBUTTON1,Bancada8086Frm::WxButton1Click)
	EVT_BUTTON(ID_WXBUTTON2,Bancada8086Frm::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON3,Bancada8086Frm::WxButton3Click)
	EVT_BUTTON(ID_WXBUTTON4,Bancada8086Frm::WxButton4Click)	
	EVT_BUTTON(ID_WXBUTTON5,Bancada8086Frm::WxButton5Click)	
   EVT_TIMER(TIMER_ID, Bancada8086Frm::OnTimer) 
END_EVENT_TABLE()
////Event Table End

extern char sINI_FILE[256]; //       = ".\\emu8086.ini";
extern char sIO_FILE[256];  //        = ".\\emu8086.io";
extern char sINT_FILE[256]; //       = ".\\emu8086.hw";

const int nrTentativas   = 351;
long SWITCH_PORT		    = 0x20;
long LED_PORT			    = 0x22;
unsigned char INT_OFF    = 0x0;
unsigned char INT_ON     = 0xFF;
//char sINI_FILE[60]       = ".\\emu8086.ini";
//char sIO_FILE[60]        = ".\\emu8086.io";
//char sINT_FILE[60]       = ".\\emu8086.hw";
int chaves[8]            = {0,0,0,0,0,0,0,0};
wxBitmap WxBitmapButton2_BITMAP (Bancada8086Frm_WxBitmapButton2_XPM);
wxBitmap WxBitmapButton1_BITMAP (Bancada8086Frm_WxBitmapButton1_XPM);
wxBitmap WxStaticBitmap2_BITMAP (Bancada8086Frm_WxStaticBitmap2_XPM);
wxBitmap WxStaticBitmap1_BITMAP (Bancada8086Frm_WxStaticBitmap1_XPM);

Bancada8086Frm::Bancada8086Frm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style), m_timer(this, TIMER_ID)
{
   if (!ReadIniFile()) return;
   if (!CreateFiles()) return;

	for (int i=0;i<8;i++)
      chaves[i] = 0;

	CreateGUIControls();

	WxEdit1->SetValue("00000000b");
	WxEdit1->Enable(false);
	WxEdit2->SetValue("00000000b");
	WxEdit2->Enable(false);
	WxEdit3->SetValue("00h");
	WxEdit3->Enable(false);
	WxEdit4->SetValue("00h");
	WxEdit4->Enable(false);
	WxEdit5->SetValue("00000000b");
	WxEdit5->Enable(false);
	WxEdit6->SetValue("00h");
	WxEdit6->Enable(false);
	//WxEdit7->SetValue(sIO_FILE);
	//WxEdit7->Enable(false);

   WriteIObyte(LED_PORT, 0);
	UpdateLeds(0);
	
   // Inicia o evento TIMER_ID que faz a leitura periódica do bus de dados(emu8086.io)
	m_timer.Start(TIMER_ID);
}

Bancada8086Frm::~Bancada8086Frm()
{
}

void Bancada8086Frm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(-4, 0), wxSize(507, 398));

	wxBitmap WxBitmapButton1_BITMAP (Bancada8086Frm_WxBitmapButton1_XPM);
	WxBitmapButton1 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON1, WxBitmapButton1_BITMAP, wxPoint(180, 33), wxSize(94, 43), wxTRANSPARENT_WINDOW | wxNO_BORDER | wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton1"));

	wxBitmap WxBitmapButton2_BITMAP (Bancada8086Frm_WxBitmapButton1_XPM);
	WxBitmapButton2 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON2, WxBitmapButton2_BITMAP, wxPoint(180, 76), wxSize(94, 43), wxTRANSPARENT_WINDOW | wxNO_BORDER | wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton2"));

	wxBitmap WxBitmapButton3_BITMAP (Bancada8086Frm_WxBitmapButton1_XPM);
	WxBitmapButton3 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON3, WxBitmapButton3_BITMAP, wxPoint(180, 119), wxSize(94, 43), wxTRANSPARENT_WINDOW | wxNO_BORDER | wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton3"));

	wxBitmap WxBitmapButton4_BITMAP (Bancada8086Frm_WxBitmapButton1_XPM);
	WxBitmapButton4 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON4, WxBitmapButton4_BITMAP, wxPoint(180, 162), wxSize(94, 43), wxTRANSPARENT_WINDOW | wxNO_BORDER | wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton4"));

	wxBitmap WxBitmapButton5_BITMAP (Bancada8086Frm_WxBitmapButton1_XPM);
	WxBitmapButton5 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON5, WxBitmapButton5_BITMAP, wxPoint(180, 205), wxSize(94, 43), wxTRANSPARENT_WINDOW | wxNO_BORDER | wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton5"));

	wxBitmap WxBitmapButton6_BITMAP (Bancada8086Frm_WxBitmapButton1_XPM);
	WxBitmapButton6 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON6, WxBitmapButton6_BITMAP, wxPoint(180, 249), wxSize(94, 43), wxTRANSPARENT_WINDOW | wxNO_BORDER | wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton6"));

	wxBitmap WxBitmapButton7_BITMAP (Bancada8086Frm_WxBitmapButton1_XPM);
	WxBitmapButton7 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON7, WxBitmapButton7_BITMAP, wxPoint(180, 292), wxSize(94, 43), wxTRANSPARENT_WINDOW | wxNO_BORDER | wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton7"));

	wxBitmap WxBitmapButton8_BITMAP (Bancada8086Frm_WxBitmapButton1_XPM);
	WxBitmapButton8 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON8, WxBitmapButton8_BITMAP, wxPoint(180, 335), wxSize(94, 43), wxTRANSPARENT_WINDOW | wxNO_BORDER | wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton8"));

	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _("00000000"), wxPoint(323, 40), wxSize(108, 19), 0, wxDefaultValidator, _("WxEdit1"));
	WxEdit1->Enable(false);

	WxStaticText1 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT1, _("Switches (port 20h low)"), wxPoint(323, 21), wxDefaultSize, 0, _("WxStaticText1"));

	WxStaticText2 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT2, _("LEDs (port 22h low)"), wxPoint(323, 78), wxDefaultSize, 0, _("WxStaticText2"));

	WxEdit2 = new wxTextCtrl(WxPanel1, ID_WXEDIT2, _("00000000"), wxPoint(323, 96), wxSize(108, 19), 0, wxDefaultValidator, _("WxEdit2"));

	WxButton1 = new wxButton(WxPanel1, ID_WXBUTTON1, _("&Close"), wxPoint(408, 352), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));
	WxButton1->SetHelpText(_("Close the tests stand."));

	wxBitmap WxStaticBitmap1_BITMAP(Bancada8086Frm_WxStaticBitmap1_XPM);
	WxStaticBitmap1 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP1, WxStaticBitmap1_BITMAP, wxPoint(54, 33), wxSize(43, 43));

	wxBitmap WxStaticBitmap2_BITMAP(Bancada8086Frm_WxStaticBitmap1_XPM);
	WxStaticBitmap2 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP2, WxStaticBitmap2_BITMAP, wxPoint(54, 76), wxSize(43, 43));

	wxBitmap WxStaticBitmap3_BITMAP(Bancada8086Frm_WxStaticBitmap1_XPM);
	WxStaticBitmap3 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP3, WxStaticBitmap3_BITMAP, wxPoint(54, 119), wxSize(43, 43));

	wxBitmap WxStaticBitmap4_BITMAP(Bancada8086Frm_WxStaticBitmap1_XPM);
	WxStaticBitmap4 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP4, WxStaticBitmap4_BITMAP, wxPoint(54, 162), wxSize(43, 43));

	wxBitmap WxStaticBitmap5_BITMAP(Bancada8086Frm_WxStaticBitmap1_XPM);
	WxStaticBitmap5 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP5, WxStaticBitmap5_BITMAP, wxPoint(54, 205), wxSize(43, 43));

	wxBitmap WxStaticBitmap6_BITMAP(Bancada8086Frm_WxStaticBitmap1_XPM);
	WxStaticBitmap6 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP6, WxStaticBitmap6_BITMAP, wxPoint(54, 248), wxSize(43, 43));

	wxBitmap WxStaticBitmap7_BITMAP(Bancada8086Frm_WxStaticBitmap1_XPM);
	WxStaticBitmap7 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP7, WxStaticBitmap7_BITMAP, wxPoint(54, 291), wxSize(43, 43));

	wxBitmap WxStaticBitmap8_BITMAP(Bancada8086Frm_WxStaticBitmap1_XPM);
	WxStaticBitmap8 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP8, WxStaticBitmap8_BITMAP, wxPoint(54, 334), wxSize(43, 43));

	WxEdit3 = new wxTextCtrl(WxPanel1, ID_WXEDIT3, _("00h"), wxPoint(448, 40), wxSize(32, 19), 0, wxDefaultValidator, _("WxEdit3"));
	WxEdit3->Enable(false);

	WxEdit4 = new wxTextCtrl(WxPanel1, ID_WXEDIT4, _("00h"), wxPoint(448, 96), wxSize(32, 19), 0, wxDefaultValidator, _("WxEdit4"));
	WxEdit4->Enable(false);

	WxStaticText3 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT3, _("(port 22h high)"), wxPoint(322, 135), wxDefaultSize, 0, _("WxStaticText3"));

	WxEdit5 = new wxTextCtrl(WxPanel1, ID_WXEDIT5, _("00000000"), wxPoint(322, 154), wxSize(112, 19), 0, wxDefaultValidator, _("WxEdit5"));

	WxEdit6 = new wxTextCtrl(WxPanel1, ID_WXEDIT6, _("00h"), wxPoint(447, 154), wxSize(36, 19), 0, wxDefaultValidator, _("WxEdit6"));
	WxEdit6->Enable(false);

	WxStaticText4 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT4, _("Switches"), wxPoint(203, 12), wxDefaultSize, 0, _("WxStaticText4"));

	WxStaticText5 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT5, _("LEDs"), wxPoint(61, 12), wxDefaultSize, 0, _("WxStaticText5"));

	WxStaticText6 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT6, _("LED 1"), wxPoint(17, 44), wxDefaultSize, 0, _("WxStaticText6"));

	WxStaticText7 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT7, _("LED 2"), wxPoint(17, 88), wxDefaultSize, 0, _("WxStaticText7"));

	WxStaticText8 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT8, _("LED 3"), wxPoint(17, 131), wxDefaultSize, 0, _("WxStaticText8"));

	WxStaticText9 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT9, _("LED 4"), wxPoint(17, 174), wxDefaultSize, 0, _("WxStaticText9"));

	WxStaticText10 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT10, _("LED 5"), wxPoint(17, 215), wxDefaultSize, 0, _("WxStaticText10"));

	WxStaticText11 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT11, _("LED 6"), wxPoint(17, 259), wxDefaultSize, 0, _("WxStaticText11"));

	WxStaticText12 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT12, _("LED 7"), wxPoint(17, 302), wxDefaultSize, 0, _("WxStaticText12"));

	WxStaticText13 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT13, _("LED 8"), wxPoint(17, 345), wxDefaultSize, 0, _("WxStaticText13"));

	WxStaticText14 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT14, _("Switch 1"), wxPoint(132, 44), wxDefaultSize, 0, _("WxStaticText14"));

	WxStaticText15 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT15, _("Switch 2"), wxPoint(132, 88), wxDefaultSize, 0, _("WxStaticText15"));

	WxStaticText16 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT16, _("Switch 3"), wxPoint(132, 131), wxDefaultSize, 0, _("WxStaticText16"));

	WxStaticText17 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT17, _("Switch 4"), wxPoint(132, 174), wxDefaultSize, 0, _("WxStaticText17"));

	WxStaticText18 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT18, _("Switch 5"), wxPoint(132, 215), wxDefaultSize, 0, _("WxStaticText18"));

	WxStaticText19 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT19, _("Switch 6"), wxPoint(132, 259), wxDefaultSize, 0, _("WxStaticText19"));

	WxStaticText20 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT20, _("Switch 7"), wxPoint(132, 302), wxDefaultSize, 0, _("WxStaticText20"));

	WxStaticText21 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT21, _("Switch 8"), wxPoint(132, 345), wxDefaultSize, 0, _("WxStaticText21"));

	WxButton2 = new wxButton(WxPanel1, ID_WXBUTTON2, _("Int 9&0h"), wxPoint(323, 228), wxSize(93, 25), 0, wxDefaultValidator, _("WxButton2"));
	WxButton2->SetHelpText(_("90h Interrupt"));

	WxButton3 = new wxButton(WxPanel1, ID_WXBUTTON3, _("Int 9&1h"), wxPoint(323, 257), wxSize(93, 25), 0, wxDefaultValidator, _("WxButton3"));
	WxButton3->SetHelpText(_("91h Interrupt"));

	WxButton4 = new wxButton(WxPanel1, ID_WXBUTTON4, _("Int 9&2h"), wxPoint(323, 286), wxSize(93, 25), 0, wxDefaultValidator, _("WxButton4"));
	WxButton4->SetHelpText(_("92h Interrupt"));

	WxStaticText22 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT22, _("Hardware interrupts"), wxPoint(323, 204), wxDefaultSize, 0, _("WxStaticText22"));

	//WxStaticText23 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT23, _(sIO_FILE), wxPoint(20, 376), wxDefaultSize, 0, _("WxStaticText23"));
	//WxEdit7 = new wxTextCtrl(WxPanel1, ID_WXEDIT7, _(sIO_FILE), wxPoint(20, 376), wxSize(400, 18), 0, wxDefaultValidator, _("WxEdit7"));
	//WxEdit7->Enable(false);

	WxButton5 = new wxButton(WxPanel1, ID_WXBUTTON5, _("&About"), wxPoint(325, 352), wxSize(74, 25), 0, wxDefaultValidator, _("WxButton5"));
	WxButton5->SetHelpText(_("About the application and the developer team."));

	SetTitle(_(PROGNAME));
	SetIcon(Bancada8086Frm_frmNewForm_XPM);
	SetSize(8,8,513,424);
	Center();
	
	////GUI Items Creation End
}

void Bancada8086Frm::OnClose(wxCloseEvent& event)
{
   Destroy();
}

/*
 * WxButton1Click
 */
void Bancada8086Frm::WxButton1Click(wxCommandEvent& event)
{
   int resposta = wxMessageBox("Close the application?",PROGNAME,wxYES_NO | wxICON_QUESTION, this);
   if(resposta == wxYES){  
      Destroy();  
   }  
}

/*
 * WxButton2Click
 */
void Bancada8086Frm::WxButton2Click(wxCommandEvent& event)
{
   WriteInterrupt(0x90,INT_ON);
}

/*
 * WxButton3Click
 */
void Bancada8086Frm::WxButton3Click(wxCommandEvent& event)
{
   WriteInterrupt(0x91,INT_ON);
}

/*
 * WxButton4Click
 */
void Bancada8086Frm::WxButton4Click(wxCommandEvent& event)
{
   WriteInterrupt(0x92,INT_ON);
}

/*
 * WxButton5Click
 */
void Bancada8086Frm::WxButton5Click(wxCommandEvent& event)
{
   char buf[1500];
   /*strcpy(buf, "Bancada de Testes versão 1.1wx\n\n");
   strcat(buf, "Programa que simula uma bancada com chaves, leds e interrupções\n");
   strcat(buf, "para interação com o emulador de processador 8086 (EMU8086).\n\n");
   strcat(buf, "Criado para a disciplina Microprocessadores: DAS5332 e BLU3302\n");
   strcat(buf, "da Universidade Federal de Santa Catarina.\n");
   strcat(buf, "Inspirado no simulador Abacus do Prof. Roberto Ziller EEL/UFSC.\n\n");
   strcat(buf, "Projetistas/desenvolvedores:\n");
   strcat(buf, "  Fabio Rafael Segundo <fabio.segundo@ufsc.br> UFSC Blumenau\n");
   strcat(buf, "  João Paulo Bodanese <joao.bodanese@gmail.com> PPGEAS/UFSC\n");
   strcat(buf, "  Werner Krauss Junior <werner.kraus@ufsc.br> DAS/UFSC\n\n");
   strcat(buf, "Programa sob licença GNU GPL v3.\n");*/
   strcpy(buf, "Tests Stand for 8086 version 1.2-wx\n\n");
   strcat(buf, "Program wich simulates a test bench with leds, keys, buttons and\n");
   strcat(buf, "displays for interaction to the 8086 microprocessor emulator (EMU8086).\n\n");
   strcat(buf, "Created for the Microprocessors courses: DAS5332 e BLU3302\n");
   strcat(buf, "at Universidade Federal de Santa Catarina (UFSC).\n");
   strcat(buf, "Inspired in the Abacus simulator created by Prof. Roberto Ziller at EEL/UFSC.\n\n");
   strcat(buf, "Designers/developers:\n");
   strcat(buf, "  Fabio Rafael Segundo <fabio.segundo@ufsc.br> UFSC Blumenau;\n");
   strcat(buf, "  João Paulo Bodanese <joao.bodanese@gmail.com> PPGEAS/UFSC;\n");
   strcat(buf, "  Werner Krauss Junior <werner.kraus@ufsc.br> DAS/UFSC.\n\n");
   strcat(buf, "Program under GNU GPL v3 license.\n");
   
   wxMessageBox(buf,PROGNAME, wxOK | wxICON_INFORMATION);
}

/*
 * WxBitmapButton1Click
 */
void Bancada8086Frm::WxBitmapButton1Click(wxCommandEvent& event)
{
   wxBitmapButton *bt = Bancada8086Frm::WxBitmapButton1;
   int b=0;

   switch (event.GetId()) {
      case ID_WXBITMAPBUTTON8: b=7; bt=Bancada8086Frm::WxBitmapButton8; break;
      case ID_WXBITMAPBUTTON7: b=6; bt=Bancada8086Frm::WxBitmapButton7; break;
      case ID_WXBITMAPBUTTON6: b=5; bt=Bancada8086Frm::WxBitmapButton6; break;
      case ID_WXBITMAPBUTTON5: b=4; bt=Bancada8086Frm::WxBitmapButton5; break;
      case ID_WXBITMAPBUTTON4: b=3; bt=Bancada8086Frm::WxBitmapButton4; break;
      case ID_WXBITMAPBUTTON3: b=2; bt=Bancada8086Frm::WxBitmapButton3; break;
      case ID_WXBITMAPBUTTON2: b=1; bt=Bancada8086Frm::WxBitmapButton2; break;
   }

	// b indica o id do botao da chave
	if (chaves[b]==0) {
       chaves[b]=1;
       bt->SetBitmap(WxBitmapButton2_BITMAP);
	} else {
       chaves[b]=0;
       bt->SetBitmap(WxBitmapButton1_BITMAP);
   }

   // obtem decimal
   int vetbin[8] = {1,2,4,8,16,32,64,128};
   unsigned char dec=chaves[0];
   for (int i=1; i<8; i++)
      if (chaves[i]) dec += vetbin[i];
   //  if (chaves[i]) dec += chaves[i] * pow(2,i);
   //  dec += vetbin[i];
   // if (chaves[i]) dec &= (1 << i);

   WriteIObyte(SWITCH_PORT,dec);
  
   // Atualiza os campos na tela    
   char bin[10]="";
   charToBin(bin,dec);
   wxString s; 
   //s.Printf("%01d%01i%01i%01i%01i%01i%01i%01ib",chaves[7],chaves[6],chaves[5],chaves[4],chaves[3],chaves[2],chaves[1],chaves[0]);
   Bancada8086Frm::WxEdit1->SetValue(bin);
   s.Printf("%02Xh", dec);
   Bancada8086Frm::WxEdit3->SetValue(s);
    
   //WxMessageDialog1 =  new wxMessageDialog(this, _(""), _(s));
   //wxDialog *dlg = new wxDialog(event.GetInt());
}

void Bancada8086Frm::OnTimer(wxTimerEvent& event) 
{ 
   // Do whatever you want to do every second here 
   m_timer.Stop();
   Bancada8086Frm::ReadBus();    
   m_timer.Start(TIMER_ID);
   //sleep(100);
}

void Bancada8086Frm::ReadBus() {
	unsigned char val;
	unsigned int  ival;

	ival = ReadIOword(LED_PORT);
	val = ival & 0x00FF;
	SetTextBoxLeds(val);
	val = (ival & 0xFF00) >> 8;
	SetTextBoxPortaC0H(val);

   //val = ReadIObyte(0xC0);
	//SetTextBoxPortaC0H(val);
	val = ReadIObyte(SWITCH_PORT);
	SetTextBoxChaves(val);
	//val = ReadIObyte(LED_PORT);
	//SetTextBoxLeds(val);
}
		
void Bancada8086Frm::charToBin(char bin[10], unsigned char val) 
{
	int i;
	for(i=7;i>=0;i--)
	   (val & (1 << i)) ? bin[7-i]='1' : bin[7-i]='0';
	bin[8]='b';
	bin[9]='\0';
}

void Bancada8086Frm::SetTextBoxPortaC0H(unsigned char val)
{
	char hex[5],bin[10]="";
	
	charToBin(bin,val);
	sprintf(hex,"%02Xh",val);

	WxEdit5->SetValue(bin);
	WxEdit6->SetValue(hex);
}

void Bancada8086Frm::SetTextBoxChaves(unsigned char val)
{
	char hex[5],bin[10]="";
		
	charToBin(bin,val);
	sprintf(hex,"%02Xh",val);

   WxEdit1->SetValue(bin);
   WxEdit3->SetValue(hex);
}
	 
void Bancada8086Frm::SetTextBoxLeds(unsigned char val)
{
	char hex[5],bin[10]="";

	UpdateLeds(val);

	charToBin(bin,val);
	sprintf(hex,"%02Xh",val);

   WxEdit2->SetValue(bin);
   WxEdit4->SetValue(hex);
}

void Bancada8086Frm::UpdateLeds(unsigned char val)
{
   // LED 1
 	if(val & 0x1){
      Bancada8086Frm::WxStaticBitmap1->SetBitmap(WxStaticBitmap2_BITMAP);
	} else{
      Bancada8086Frm::WxStaticBitmap1->SetBitmap(WxStaticBitmap1_BITMAP);
	}
	// LED 2
	if(val & 0x2){
      Bancada8086Frm::WxStaticBitmap2->SetBitmap(WxStaticBitmap2_BITMAP);
	} else{
      Bancada8086Frm::WxStaticBitmap2->SetBitmap(WxStaticBitmap1_BITMAP);
	}
 	// LED 3
	if(val & 0x4){
      Bancada8086Frm::WxStaticBitmap3->SetBitmap(WxStaticBitmap2_BITMAP);
	} else{
      Bancada8086Frm::WxStaticBitmap3->SetBitmap(WxStaticBitmap1_BITMAP);
	}
	// LED 4
	if(val & 0x8){
      Bancada8086Frm::WxStaticBitmap4->SetBitmap(WxStaticBitmap2_BITMAP);
	} else{
      Bancada8086Frm::WxStaticBitmap4->SetBitmap(WxStaticBitmap1_BITMAP);
	}
	// LED 5
	if(val & 0x10){
      Bancada8086Frm::WxStaticBitmap5->SetBitmap(WxStaticBitmap2_BITMAP);
	} else{
      Bancada8086Frm::WxStaticBitmap5->SetBitmap(WxStaticBitmap1_BITMAP);
	}
	// LED 6
	if(val & 0x20){
      Bancada8086Frm::WxStaticBitmap6->SetBitmap(WxStaticBitmap2_BITMAP);
	} else{
      Bancada8086Frm::WxStaticBitmap6->SetBitmap(WxStaticBitmap1_BITMAP);
	}
	// LED 7
	if(val & 0x40){
      Bancada8086Frm::WxStaticBitmap7->SetBitmap(WxStaticBitmap2_BITMAP);
	} else{
      Bancada8086Frm::WxStaticBitmap7->SetBitmap(WxStaticBitmap1_BITMAP);
	}
	// LED 8
	if(val & 0x80){
      Bancada8086Frm::WxStaticBitmap8->SetBitmap(WxStaticBitmap2_BITMAP);
	} else{
      Bancada8086Frm::WxStaticBitmap8->SetBitmap(WxStaticBitmap1_BITMAP);
	}
}

unsigned char Bancada8086Frm::ReadIObyte(long lPORT_NUM) 
{
	unsigned char tb;
	FILE *fp;

	while ((fp = fopen(sIO_FILE, "rb"))==NULL)
	  if (errno!=EACCES) FileNotFound(sIO_FILE);
       
	fseek(fp, lPORT_NUM, SEEK_SET);
	tb = fgetc(fp);

	fclose(fp);

	return tb;
}

unsigned int Bancada8086Frm::ReadIOword(long lPORT_NUM) 
{
	unsigned int ti;
	unsigned char tb1;
	unsigned char tb2;

	tb1 = ReadIObyte(lPORT_NUM);
	tb2 = ReadIObyte(lPORT_NUM+1);

	ti = tb2;
	ti = ti << 8;
	ti = ti + tb1;

	return ti;
}
	 
void Bancada8086Frm::WriteIOword(long lPORT_NUM, unsigned int iValue)
{
	 WriteIObyte (lPORT_NUM, iValue & 0x00FF);
	 WriteIObyte (lPORT_NUM+1, (iValue & 0xFF00) >> 8);
}

	void Bancada8086Frm::WriteIObyte(long lPORT_NUM, unsigned char val)
	{
		FILE *fp;
		
		while ((fp = fopen(sIO_FILE, "rb+"))==NULL)
		  if (errno!=EACCES) FileNotFound(sIO_FILE);

		fseek(fp, lPORT_NUM, SEEK_SET);
		fputc(val, fp);

		fclose(fp);
	}

	void Bancada8086Frm::WriteInterrupt(long interrupt, unsigned char val)
	{
		FILE *fp;

		while ((fp = fopen(sINT_FILE, "rb+"))==NULL)
		  if (errno!=EACCES) FileNotFound(sINT_FILE);

		fseek(fp, interrupt, SEEK_SET);
		fputc(val, fp);

		fclose(fp);
	}

	int Bancada8086Frm::CreateFiles()
	{
		FILE *fIo,*fInt;

        // IO

		int ct=0;
		fIo = fopen(sIO_FILE, "wb+");
		while (fIo == NULL && ct<nrTentativas) {
			ct++;
		}
		if (fIo == NULL && ct==nrTentativas) {
    	    char buf[500];
            strcpy(buf, "Not possible to create the file ");
	        strcat(buf, sIO_FILE);
	        strcat(buf, ". Verify the path and the write grant. Close application?");
            int resposta = wxMessageBox(buf,"Error",  
                           wxYES_NO | wxICON_QUESTION, this);  
            if(resposta == wxYES){  
            	fclose(fIo);
               Destroy();
               return 0;
            }
		}

		fclose(fIo);

		// Interrupção

		ct=0;
		fInt = fopen(sINT_FILE, "wb+");
		while (fInt == NULL && ct<nrTentativas) {
			ct++;
		}
		if (fInt == NULL && ct==nrTentativas) {
    	    char buf[500];
            strcpy(buf, "Not possible to create the file ");
	        strcat(buf, sINT_FILE);
	        strcat(buf, ". Verify the path and the write grant. Close application?");
            int resposta = wxMessageBox(buf,"Error",  
                           wxYES_NO | wxICON_QUESTION, this);  
            if(resposta == wxYES){  
            	fclose(fInt);
               Destroy();  
               return 0;
            }
		}

		fclose(fInt);
      return 1;

	}

void Bancada8086Frm::FileNotFound(char sFile[])
{
	char buf[500];
	char str[255];

	strcpy(buf, "File ");
	strcat(buf, sFile);
	strcat(buf, ". Error: (");
	itoa(errno, str, 10);
	strcat(buf, str);
	strcat(buf, ") ");
	strcat(buf, strerror(errno));
	strcat(buf, ". Close application?");
   int resposta = wxMessageBox(buf,"Error",
                  wxYES_NO | wxICON_QUESTION, this);
   if(resposta == wxYES){
      Destroy();
   }
}

void Bancada8086Frm::FileIniNotFound()
{
	char buf[500];
   strcpy(buf, "File ");
	strcat(buf, sINI_FILE);
	strcat(buf, " not found or with no configuration for EMUPORT and/or HW_INTERRUPT_FILE. Verify the instalation!");
   wxMessageBox(buf, PROGNAME, wxOK | wxICON_INFORMATION);
   Destroy();  
}

// Recupera valor do emu8086.ini
int Bancada8086Frm::ReadIniFile() 
{
   FILE *f;
   f=fopen(sINI_FILE, "r");
   if (f==NULL) {
		FileIniNotFound();
		return 0;
	} else {
		// Busca EMUPORT e HW_INTERRUPT_FILE no emu8086.ini  
		int lineNumber = 0;
		char* Setting=(char*)malloc(40);
      char* Value=(char*)malloc(60);
		int ctvalores=0;

      for(;;) {
		   // le linha do arquivo ini
         char line[255]; 
         fgets(line, 255, f);
         if (feof(f) || ctvalores==2) { 
			   break;
		   } else {
            lineNumber++;
         }

		   // verifica configuracao = valor na linha
		   int ct=0, ctv=0, cts=0;
		   Value[0]='\0';
		   Setting[0]='\0';
		   int posigual=0, ctbarra=0;
		   while (line[ct]!=0 && line[ct]!=';' && line[ct]!=13) {
			   if (line[ct]==10) { ct++; continue; }
			   if (line[ct]==' ' && !posigual) { ct++; continue; }
			   if (line[ct]=='=') { posigual=1; ct++; continue; }
			   if (posigual) {
			      if (ctv<60) { Value[ctv]=line[ct]; ctv++; }
			   } else {
			      if (ctv<40) {	Setting[cts]=line[ct]; cts++; }
			   }
			   if (line[ct]=='\\')
			      if (ctbarra==0) { ctbarra++; continue; }
			   else ctbarra=0;
			      ct++;
		   }
		   Value[ctv]=0;
		   Setting[cts]=0;

         // se a configuracao for EMUPORT ou HW_INTERRUPT_FILE atribui valores
		   // se os dois valores já foram obtidos termina a leitura do arquivo ini
		   // ok int a=sscanf_s(line, "%s=%s", &Setting, &Value);
         //if (sscanf_s(line, "%[^=]=%s", &Setting, &Value)==2) {
		   if(strcmp(Setting,"EMUPORT")==0) {
			   strcpy(sIO_FILE,Value);
		      ctvalores++;
		   } else {
			   if (strcmp(Setting,"HW_INTERRUPT_FILE")==0) {
			      strcpy(sINT_FILE,Value);
		         ctvalores++;
			   }
		   }
      }
      fclose(f);	
   }
   return 1;
}


//========================================================================================================
// Exemplo para interrupção 0x90
#if 0

; interrupt vector (memory from 00000h to 00400h)
; keeps addresses of all interrupts (from 00h to 0ffh).
; you can add new interrupt or modify existing interrupts.
; address of interrupt M is stored in vector at offset M * 4,
; for example: interrupt 10h is stored at offset 10h * 4.
; first goes the offset, then segment (total of 2 bytes).

; for more information refer to "global memory table" in c:\emu8086\documentation.
 
; note: this is simplified example, it is not recommended to make changes to it
; and run it on the real computer, especially it is not recommended to replace disk
; processing interrupts because this may cause data loss and other instability problems.

 
name "custint"

#start=Interrupt.exe#

org 100h

start:
 
; set video mode to 3 - 16 color 80x25
mov ah, 0
mov al, 3
int 10h
 
 
; set es to "0000":
mov ax, 0       
mov es, ax
; calculate vector address for interrupt 90h:
mov al, 90h    
; multiply 90h by 4, store result in ax:
mov bl, 4h       
mul bl          
mov bx, ax
; copy offset into interrupt vector:
mov si, offset [test1]
mov es:[bx], si
add bx, 2   
; copy segment into interrupt vector:    
mov ax, cs     
mov es:[bx], ax
         

; int 90h    ; test newly created interrupt.
wait_for_hw_int:
    in al,111     ;read the port at 111
    jmp wait_for_hw_int
 
; wait for any key press:
mov ah, 0
int 16h
 
 
int 20h     ; halt execution.


; interrupt 90h starts here:
test1: pusha  ; store all registers.

; make sure data segment is code segment:
       push cs
       pop ds

; set segment register to video memory:
       mov     ax, 0b800h
       mov     es, ax

; print message, each character is written as
; a word, high byte is color and low byte is
; ascii code:
      lea si, msg      ; load offset of msg to si.
      mov di, 0        ; point to start of the screen.
print:
      cmp [si], 0      ; if "0" then stop.
      je stop
      mov bl,  [si]    ; read ascii code from msg.
      mov bh, 0f1h     ; set colors: white background, blue text.
      mov es:[di], bx  ; write to vidio memory.
      add di, 2        ; go to next position on screen.
      inc si           ; next char.
      jmp print
stop:
      popa  ; re-store all registers.
      iret  ; return from interrupt.
 
msg db "test of custom interrupt!", 0

#endif

//========================================================================================================



//========================================================================================================
// Exemplo de In/Out
#if 0

; c:\emu8086\devices\Bancada8086.exe

#start=Bancada8086.exe#


#make_bin#

name "Bancada8086"
           
  mov cl, 0
x1:
  in  al, 20h
  mov ah, cl
  out 22h, al  
  inc cl
jmp x1

hlt

#endif
