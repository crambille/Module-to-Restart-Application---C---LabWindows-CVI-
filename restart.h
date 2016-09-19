/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2015. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>
#include <windows.h>


#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL1                           1
#define  PANEL1_COMMANDBUTTON_2           2       /* control type: command, callback function: eteindre */
#define  PANEL1_COMMANDBUTTON             3       /* control type: command, callback function: comm */
#define  PANEL1_LED1                      4       /* control type: LED, callback function: comm */
#define  PANEL1_TEXTMSG                   5       /* control type: textMsg, callback function: (none) */
#define _WIN32_WINNT            0x0501
#define _WIN32_IE               0x0700

     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK comm(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK eteindre(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif

