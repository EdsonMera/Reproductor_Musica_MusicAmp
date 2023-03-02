/*******************************************************************\
*																	*
*				THIS IS MY OWN AND FUNKTIONS THAT					*
*				  I HAVE FOUND ON THE INTERNET						*
*																	*
*		Put this file in "Microsoft Visual Studio\VC98\Include"		*
*																	*
\*******************************************************************/

/*    My libraries    */
#include <stuff\\console.h>


#include <windows.h>
#include <iostream>
#include <cmath>

#include <winsock.h>
#pragma comment(lib,"wsock32.lib")

using namespace std;

/***********************************\
*COOL FUNKTIONS THAT ALLREADY EXCIST*
\***********************************/
/*		
 *	MOUSE/KEYBOARD FUNKTIONS:
 *
 *	SetCursorPos(x, y);
 *	SwapMouseButton(true or false)
 *	SetDoubleClickTime(milisec);
 *	GetDoubleClickTime()
 *
 *	Values for this is find at end of file
 *
 *	mouse_event(Value, pos x, pos y, NULL, NULL);
 *	keybd_event(Value, 0, 0, 0)
 *	
 *	EXIT WINDOWS:
 *
 *	ExitWindowsEx(Value, EWX_FORCE);
 *
 *	Values:
 *			EWX_LOGOFF		<---- this is the only one i can get to work in XP
 *			EWX_SHUTDOWN
 *			EWX_REBOOT
 *			EWX_POWEROFF
 *
 *	CD-ROM DRIVE:
 *
 *	#pragma comment(lib,"winmm.lib");
 *
 *	mciSendString("Set cdaudio door open wait",0,0,0);
 *	mciSendString("Set cdaudio door closed wait",0,0,0);
 *
 *	MONITORFUN:
 *
 *	SystemParametersInfo(SPI_SETLOWPOWERTIMEOUT, 15, NULL, 0);
 *	SystemParametersInfo(SPI_SETLOWPOWERACTIVE, 1, NULL, 0); // You must use both
 *
 *	SendMessage(GetDesktopWindow(),
 *				WM_SYSCOMMAND,
 *				SC_MONITORPOWER or SC_SCREENSAVE,
 *				(LPARAM)1);
 *
 *	To get it all back to normal, goto Screensaversettings and press settings
 *	or something, change "lowpower" to never.
 *
 */ 
/*******************************************************************\
*						EASY WAY OF USING THREADS					*
\*******************************************************************/
bool Thread(unsigned int Value, INPUT_RECORD InputRecord)
{
	/*Just type like this	 
	INPUT_RECORD	InputRecord;
	DWORD			Events		=0;  
	HANDEL			hInput		= GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT);
	 
	Then in the while/for loop type
	 
	if(WaitForSingleObject(hInput,0)==WAIT_OBJECT_0)
	{
	    ReadConsoleInput(hInput, &InputRecord, 1, &Events );
	} 
    Exampel how to use if, if(Thread(Value, InputRecord))
	Exampel of values in end of file*/	 

	if(InputRecord.Event.KeyEvent.wVirtualKeyCode == Value &&
		InputRecord.Event.KeyEvent.bKeyDown)
		return true;
	else
		return false;
}
/*******************************************************************\
*							CHANGEWALLPAPER							*
\*******************************************************************/
bool ChangeWallpaper(char* FilePath)
{
	// if the wallpaper was changed true will be returned else false
	if(SystemParametersInfo(SPI_SETDESKWALLPAPER,0,(TCHAR*)FilePath,SPIF_SENDCHANGE|SPIF_UPDATEINIFILE))
		return true;
	else
		return false;
}
/*******************************************************************\
*						CONVERTS A INT TO CHAR						*
\*******************************************************************/
char* IntToChar(int a)
{
	// I have no idea how this one works... but it does :)
    char retval[128];
	int b=0;
    int c=a;
	if (c==0)
		b=1;
	else
	{
	     while(c>=1)
		 {
			c=c/10;
			b++;
		 }
	}
	b--;
    for (int i=0; i<=b; i++)
    {
		retval[i]=char((a/pow(10,(b-i)))+48);

        a-=(int(a/pow(10,(b-i)))*pow(10,(b-i)));
    }
    retval[b+1]='\0';

	char * Retval;
	Retval = new char;
	strcpy(Retval,retval);

    return Retval;
}

/*******************************************************************\
*						CONVERTS A CHAR TO INT						*
\*******************************************************************/
int CharToInt(char *Numbers)
{
	// OBS! A maximum of TEN letters
	int Retval=0;

	for(int i=0; i<strlen(Numbers); i++)
	{
		if(Numbers[i]=='0')
			Retval+=0;
		else if(Numbers[i]=='1')
			Retval+=1;
		else if(Numbers[i]=='2')
			Retval+=2;
		else if(Numbers[i]=='3')
			Retval+=3;
		else if(Numbers[i]=='4')
			Retval+=4;
		else if(Numbers[i]=='5')
			Retval+=5;
		else if(Numbers[i]=='6')
			Retval+=6;
		else if(Numbers[i]=='7')
			Retval+=7;
		else if(Numbers[i]=='8')
			Retval+=8;
		else if(Numbers[i]=='9')
			Retval+=9;
		if(i!=strlen(Numbers)-1)
			Retval*=10;
	}
	return Retval;
}

/*******************************************************************\
*					GETS USERNAME AND DOMAINNAME	 				*
\*******************************************************************/
bool GetUserInfo(char *UserName, char *Domain)
{
    char chrUserName[100];
    DWORD dwUserName = sizeof(chrUserName);
    if(GetUserName(chrUserName, &dwUserName) == false)
		return false;

	strcpy(UserName,chrUserName);

	return true;
}

/*******************************************************************\
*				GETS COMPUTER NAME AND IP ADDRESS	 				*
\*******************************************************************/
bool GetComputerInfo(char *ComputerName, char *IPAddress)
{
	bool Retval=true;
	/* COMPUTER NAME */
    char HostName[MAX_COMPUTERNAME_LENGTH + 1];

    DWORD BufLen = sizeof(HostName);
    GetComputerName(HostName, &BufLen);

    if (!HostName)
		Retval=false;
	else
		strcpy(ComputerName, HostName);
	/*****************/

	/* IP ADRESS */
	WSADATA wsadata;
	WSAStartup(514,&wsadata);

	char Address[20]="\0";

	struct hostent *host;
	host = gethostbyname(HostName);

	if(host != NULL)
	{
		for(int i=0; i<4; i++)
		{
			
			strcat(Address,IntToChar(host->h_addr_list[0][i]));
			if(i!=3)
				strcat(Address,".");
		}
	}
	else
		Retval=false;

	strcpy(IPAddress, Address);
	/*****************/

    return Retval;
}

/*******************************************************************\
*						LOADS A BITMAP FILE							*
\*******************************************************************/
HBITMAP__ *LoadBMP(LPCSTR FilePath, int SizeX, int SizeY)
{
	HBITMAP TempBmp;
	TempBmp = (HBITMAP) LoadImage(GetModuleHandle(NULL), FilePath, IMAGE_BITMAP, SizeX, SizeY, LR_CREATEDIBSECTION);

    if(TempBmp == NULL)
        TempBmp = (HBITMAP) LoadImage(NULL, FilePath, IMAGE_BITMAP, SizeX, SizeY, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	return TempBmp;
}
/*******************************************************************\
*						LOADS A ICON FILE							*
\*******************************************************************/
HICON__ *LoadICON(LPCSTR FilePath, int SizeX, int SizeY)
{
	HICON TempIcon;
	TempIcon = (HICON) LoadImage(GetModuleHandle(NULL), FilePath, IMAGE_ICON, SizeX, SizeY, LR_CREATEDIBSECTION);

    if(TempIcon == NULL)
        TempIcon = (HICON) LoadImage(NULL, FilePath, IMAGE_ICON, SizeX, SizeY, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	return TempIcon;
}
/*******************************************************************\
*						LOADS A CURSOR FILE							*
\*******************************************************************/
HICON__ *LoadCURSOR(LPCSTR FilePath, int SizeX, int SizeY)
{
	HCURSOR TempCUR;
	TempCUR = (HCURSOR) LoadImage(GetModuleHandle(NULL), FilePath, IMAGE_CURSOR, 0, 0, LR_CREATEDIBSECTION);

    if(TempCUR == NULL)
        TempCUR = (HCURSOR) LoadImage(NULL, FilePath, IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	return TempCUR;
}

/*******************************************************************\
*							MOUSE EVENTS			 				*
\*******************************************************************/
/*
 *  MOUSEEVENTF_MOVE        // mouse move
 *  MOUSEEVENTF_LEFTDOWN    // left button down
 *  MOUSEEVENTF_LEFTUP      // left button up
 *  MOUSEEVENTF_RIGHTDOWN   // right button down
 *  MOUSEEVENTF_RIGHTUP     // right button up
 *  MOUSEEVENTF_MIDDLEDOWN  // middle button down
 *  MOUSEEVENTF_MIDDLEUP    // middle button up
 *  MOUSEEVENTF_WHEEL       // wheel button rolled
 *  MOUSEEVENTF_ABSOLUTE    // absolute move	
 */

/*******************************************************************\
*							KEYBOARD EVENTS			 				*
\*******************************************************************/
/*
 *  VK_NUMLOCK
 *  VK_CAPSLOCK
 *  VK_SCROLL
 *
 *  
 *  VK_BACK
 *  VK_TAB
 *  
 *  VK_CLEAR
 *  VK_RETURN
 *  
 *  VK_SHIFT
 *  VK_CONTROL
 *  VK_MENU
 *  VK_PAUSE
 *  VK_CAPITAL
 *  
 *  VK_KANA
 *  VK_HANGEUL		// old name - should be here for compatibility
 *  VK_HANGUL
 *  VK_JUNJA 
 *  VK_FINAL          
 *  VK_HANJA          
 *  VK_KANJI          
 *  
 *  VK_ESCAPE         
 *  
 *  VK_CONVERT        
 *  VK_NONCONVERT     
 *  VK_ACCEPT         
 *  VK_MODECHANGE     
 *  
 *  VK_SPACE          
 *  VK_PRIOR          
 *  VK_NEXT           
 *  VK_END            
 *  VK_HOME           
 *  VK_LEFT           
 *  VK_UP             
 *  VK_RIGHT          
 *  VK_DOWN           
 *  VK_SELECT         
 *  VK_PRINT          
 *  VK_EXECUTE        
 *  VK_SNAPSHOT       
 *  VK_INSERT         
 *  VK_DELETE         
 *  VK_HELP           
 *
 *  VK_0 - VK_9(0x30 - 0x39)
 *  VK_A - VK_Z(0x41 - 0x5A)
 *  
 *  VK_LWIN           
 *  VK_RWIN          
 *  VK_APPS           
 *  
 *  VK_NUMPAD0 - VK_NUMPAD9      
 *  VK_MULTIPLY       
 *  VK_ADD            
 *  VK_SEPARATOR      
 *  VK_SUBTRACT       
 *  VK_DECIMAL       
 *  VK_DIVIDE         
 *  VK_F1 - VK_F24                                 
 *
 *  VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
 *  Used only as parameters to GetAsyncKeyState() and GetKeyState().
 *  No other API or message will distinguish left and right keys in this way.
 *
 *  VK_LSHIFT         
 *  VK_RSHIFT         
 *  VK_LCONTROL       
 *  VK_RCONTROL       
 *  VK_LMENU          
 *  VK_RMENU          
 * 
 *  VK_ATTN           
 *  VK_CRSEL          
 *  VK_EXSEL          
 *  VK_EREOF          
 *  VK_PLAY           
 *  VK_ZOOM           
 *  VK_NONAME         
 *  VK_PA1            
 *  VK_OEM_CLEAR
 */