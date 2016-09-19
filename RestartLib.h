//==============================================================================
//
// Title:       Fonction.h
// Purpose:     A short description of the interface.
//
// Created on:  4/23/2015 at 11:45:27 AM by .
// Copyright:   . All Rights Reserved.
//
//==============================================================================

#ifndef __Fonction_H__
#define __Fonction_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"
#include <userint.h>
#include <windows.h>


//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions
	
void ProgramEnd(void) ;
BOOL ProgramStart(void) ;
void ProgramRestart(LPTSTR lpszTitle);

extern BOOL bBeenRestarted;


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __Fonction_H__ */
