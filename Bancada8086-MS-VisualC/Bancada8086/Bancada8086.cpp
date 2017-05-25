// Bancada8086.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

using namespace Bancada8086;
using namespace std;

DWORD GetProcessByName(PCWSTR name);

int main(array<System::String ^> ^args)
//int main(int argc, char** argv[])
{

  // Obtem o pid do processo para depois obter o módulo e então o full path
  HANDLE hModuleSnap = INVALID_HANDLE_VALUE; 
  MODULEENTRY32 me32; 
 
  //  Take a snapshot of all modules in the specified process. 
  hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, GetProcessByName(L"emu8086.exe") ); 
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
        if (_wcsnicmp(L"emu8086.exe", me32.szModule, sizeof(me32.szModule)) == 0) {
  	      //MessageBox::Show(String(me32.szExePath).ToString(),PROGNAME, MessageBoxButtons::OK,MessageBoxIcon::Information);
		  //errno_t err = strcpy_s(sINI_FILE,60,LPCSTR(me32.szModule));

		  // obtem o caminho completo com nome do executável e troca a extensão por .ini
          size_t   i;
		  errno_t err = wcstombs_s(&i,sINI_FILE, (size_t)60, me32.szExePath, (size_t)60);
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


  // Does not allow to run twice window with the same PROGNAME
  if (FindWindow(NULL, PROGNAME)==0)
  {
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
  }

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


    return NULL;
}
