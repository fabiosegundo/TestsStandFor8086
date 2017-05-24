//---------------------------------------------------------------------------
//
// Name:        Bancada8086App.cpp
// Author:      Fabio Rafael Segundo <fabio.segundo@gmail.com>
// Created:     21/10/2015 23:49:26
// Description:
//
//---------------------------------------------------------------------------

#include "Bancada8086App.h"
#include "Bancada8086Frm.h"
#include <tlhelp32.h>

//IMPLEMENT_APP(Bancada8086FrmApp, MY_EXTRA_CODE)
/* IMPLEMENT_APP(Aplicacao) */  
wxAppConsole *wxCreateApp(){  
   wxAppConsole::CheckBuildOptions(WX_BUILD_OPTIONS_SIGNATURE,PROGNAME);
   return new Bancada8086FrmApp;  
}  
wxAppInitializer  
  wxTheAppInitializer((wxAppInitializerFunction) wxCreateApp);  
extern Bancada8086FrmApp& wxGetApp();  
Bancada8086FrmApp& wxGetApp() {  
   return *wx_static_cast(Bancada8086FrmApp*, wxApp::GetInstance());  
}  

using namespace std;

DWORD GetProcessByName(PCWSTR name);

char sINI_FILE[256]       = ".\\emu8086.ini";
char sIO_FILE[256]        = ".\\emu8086.io";
char sINT_FILE[256]       = ".\\emu8086.hw";

int main(int argc, char **argv){  

  // Obtem o pid do processo para depois obter o módulo e então 
  // o full path para localizar o emu8086.ini
  // Considera o próprio nome do executável como nome do .ini
  HANDLE hModuleSnap = INVALID_HANDLE_VALUE; 
  MODULEENTRY32 me32; 
 
  //  Take a snapshot of all modules in the specified process. 
  hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, GetProcessByName(EMU8086EXEFILE) ); 
  if( hModuleSnap != INVALID_HANDLE_VALUE ) 
  { 
    //  Set the size of the structure before using it. 
    me32.dwSize = sizeof( MODULEENTRY32 ); 
    //  Retrieve information about the first module, 
    //  and exit if unsuccessful 
    if( Module32First( hModuleSnap, &me32 ) ) 
    { 
      do 
      {
        if (_wcsnicmp(EMU8086EXEFILE, me32.szModule, sizeof(me32.szModule)) == 0) {
  	       //MessageBox::Show(String(me32.szExePath).ToString(),PROGNAME, MessageBoxButtons::OK,MessageBoxIcon::Information);
		    //errno_t err = strcpy_s(sINI_FILE,60,LPCSTR(me32.szModule));
		    // obtem o caminho completo com nome do executável e troca a extensão por .ini
          size_t   i;
 		    int err = wcstombs(sINI_FILE, me32.szExePath, (size_t)60);
		    int p_ini=strlen(sINI_FILE);
		    sINI_FILE[p_ini-1] = 'i';
		    sINI_FILE[p_ini-2] = 'n';
		    sINI_FILE[p_ini-3] = 'i';
  	       //MessageBox::Show(String(sINI_FILE).ToString(),PROGNAME, MessageBoxButtons::OK,MessageBoxIcon::Information);
		    break;
		  }
	   } while( Module32Next( hModuleSnap, &me32 ) ); 
    }
	CloseHandle( hModuleSnap );     // Must clean up the snapshot object!
  } 
 
  return wxEntry(argc, argv);
}  
  
/* fim IMPLEMENT_APP(Aplicacao) */

bool Bancada8086FrmApp::OnInit()
{
    const wxString name = wxString::Format("Bancada8086-%s", wxGetUserId().c_str());
    m_checker = new wxSingleInstanceChecker(name);
    if ( m_checker->IsAnotherRunning() )
    {
        //wxLogError(_("Another program instance is already running, aborting."));
        delete m_checker; // OnExit() won't be called if we return false
        m_checker = NULL;
        return false;
    }

    Bancada8086Frm* frame = new Bancada8086Frm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}

int Bancada8086FrmApp::OnExit()
{
   delete m_checker;
	return 0;
}

DWORD GetProcessByName(PCWSTR name)
{
    DWORD pid = 0;

    // Create toolhelp snapshot.
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process;
    ZeroMemory(&process, sizeof(process));
    process.dwSize = sizeof(process);

    // Walkthrough all processes.
    if (Process32First(snapshot, &process))
    {
        do
        {
            // Compare process.szExeFile based on format of name, i.e., trim file path
            // trim .exe if necessary, etc.
            //if (string(process.szExeFile) == string(name))
            if (_wcsnicmp(name, process.szExeFile, sizeof(process.szExeFile)) == 0)
            {
               pid = process.th32ProcessID;
               break;
            }
        } while (Process32Next(snapshot, &process));
    }

    CloseHandle(snapshot);

    if (pid != 0)
    {
         return pid; //OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    }

    // Not found
    return 0;
}
