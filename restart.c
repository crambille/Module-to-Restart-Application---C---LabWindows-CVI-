#include "restart.h"  
#include "RestartLib.h" 


static int panelHandle; 

static LPTSTR lpszRestartMutex = TEXT("NapalmSelfRestart");
HANDLE hRestartMutex;
BOOL bBeenRestarted;


int main ( int argc, char *argv [] )
{	
	bBeenRestarted = ProgramStart();
	if ((panelHandle = LoadPanel (0, "essai.uir", PANEL1)) < 0)
    return -1;
	DisplayPanel (panelHandle);
	RunUserInterface (); 
	ProgramEnd();
 
	return ( 0 );
}
 

int CVICALLBACK comm (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			SetCtrlVal(PANEL1,PANEL1_LED1,1); 
			SetCtrlVal (panelHandle,PANEL1_TEXTMSG,"Update ok");    
			
		    if(!bBeenRestarted)
			{
				
					ProgramRestart(TEXT("Updates Completed"));
					QuitUserInterface(0);    

			}
 			

			break;
	}
	return 0;
}

int CVICALLBACK eteindre (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface(0); 
			break;
	}
	return 0;
}
