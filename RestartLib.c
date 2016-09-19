//==============================================================================
//
// Title:       Fonction.c
// Purpose:     A short description of the implementation.
//
// Created on:  4/23/2015 at 11:45:27 AM by .
// Copyright:   . All Rights Reserved.
//
//==============================================================================

#include "RestartLib.h"

static LPTSTR lpszRestartMutex = TEXT("NapalmSelfRestart");
static HANDLE hRestartMutex;
BOOL bBeenRestarted;


void ProgramEnd()
{
    if(hRestartMutex){
        ReleaseMutex(hRestartMutex);
        CloseHandle(hRestartMutex);
    }
}

BOOL ProgramStart()
{
    //InitCommonControls();
     
    // Wait for previous version to close (Must be done at the beginning of the program)
    hRestartMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, lpszRestartMutex);
    if(hRestartMutex){
        INT nResult = IDYES;
        while(nResult == IDYES){
            if(WaitForSingleObject(hRestartMutex, 10000) != WAIT_OBJECT_0){ // 10 seconde
            }else{
                nResult = IDOK;
            }
        }
         
        if(nResult == IDNO){
            ProgramEnd();
            ExitProcess(1);
        }
         
        return TRUE;
    }
     
    return FALSE;
}

void ProgramRestart(LPTSTR lpszTitle)
{
    // Just doing this so you can tell that is a new process
    TCHAR szBuffer[512];
    if(strlen(lpszTitle) > 500) 
		lpszTitle[500] = 0;
    
	wsprintf(szBuffer, TEXT("%s - %08X"), lpszTitle, GetCurrentProcessId());
 
	TCHAR szPath[MAX_PATH + 1];
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
     
    GetStartupInfo(&si);
    GetModuleFileName(NULL, szPath, MAX_PATH);
     
    hRestartMutex = CreateMutex(NULL, TRUE, lpszRestartMutex);
     
    if(CreateProcess(szPath, GetCommandLine(), NULL, NULL, 
        FALSE, DETACHED_PROCESS, NULL, NULL, &si, &pi) == 0)
    {
        MessageBox(HWND_DESKTOP, TEXT("Failed to restart program.\n"
            "Please try manually."), TEXT("Error"), MB_ICONERROR);
    }else{
		Sleep(50); 
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);  
    }			
}

