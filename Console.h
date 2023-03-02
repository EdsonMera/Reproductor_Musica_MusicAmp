/*******************************************************************\
*																	*
*				THIS IS MY OWN CONSOLE FUNKTIONS AND				*
*			  OTHERS THAT I HAVE FOUND ON THE INTERNET				*
*																	*
*	Put this file in "Microsoft Visual Studio\VC98\Include\Stuff"	*
*																	*
\*******************************************************************/

#include <windows.h>

/*******************************************************************\
*			MOVES THE CONSOLE CURSOR ANYWHERE ON THE SCREEN			*
\*******************************************************************/
void gotoxy(const unsigned short int x, const unsigned short int y)
{
	// creates the handle we need to use
	HANDLE OutputH;
	
	/* the (x,y) position we want to place the cursor at
	Max: y=80 x=50*/
	COORD position = {x, y};

	// grab the handle so we can use it
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);

	// sets the cursor to the (x,y) position desired
	SetConsoleCursorPosition(OutputH, position);
}

/*******************************************************************\
*						HIDES THE CONSOLE CURSOR					*
\*******************************************************************/
void ShowConsoleCursor(bool Show)
{
	//The nSize = the cursor height, optional parameter, by default 25. Size range: 1 - 100
	_CONSOLE_CURSOR_INFO CurInfo; //Define the cursor size

	//Define the visibility of the cursor
	CurInfo.bVisible	= Show;
	CurInfo.dwSize		= 25;
	
	//Set parameters
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}

/***********************************\
*		VALUES FOR COLOR()			*
\***********************************/
#define C_BLACK			0
#define C_DARKBLUE		1
#define C_DARKGREEN		2
#define C_DARKBEIGE		3
#define C_DARKRED		4
#define C_DARKPURPLE	5
#define C_DARKYELLOW	6
#define C_GREY			7
#define C_DARKGREY		8
#define C_BLUE			9
#define C_GREEN			10
#define C_BEIGE			11
#define C_RED			12
#define C_PURPLE		13
#define C_YELLOW		14
#define C_WHITE			15

/*******************************************************************\
*				SETS THE TEXT AND BACKGROUND COLOR	 				*
\*******************************************************************/
void Color(int TextColor, int BackColor)
{
	// converts the TextColor and BackColor to one
	int color = TextColor + (BackColor * 16);

	// creates the handle we need to use
	HANDLE Console_Handle;

	// grab the handle so we can use it
	Console_Handle= GetStdHandle(STD_OUTPUT_HANDLE);

	// sets the color desired
	SetConsoleTextAttribute(Console_Handle, color);
}