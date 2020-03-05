#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<direct.h>
///////////////////////////////////////////////////////////////////////////

void delay(int number_of_milli_seconds)
{

	int milli_seconds = 1 * number_of_milli_seconds;


	clock_t start_time = clock();

	while (clock() < start_time + milli_seconds);
}
///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////%%%%%%%%%%%     color     %%%%%%%%%%%%%%/////////////////////////////////////////////////////////////////

#ifdef _WIN32
#include <windows.h>    // for win32 API functions
#include <io.h>         // for _get_osfhandle()
#else
#define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
#include <unistd.h>     // for isatty()
#endif

#include <stdlib.h>
#include <stdio.h>

// use an enum for platform-independent interface:
typedef enum TextColor
{
	TC_BLACK = 0,
	TC_BLUE = 1,
	TC_GREEN = 2,
	TC_CYAN = 3,
	TC_RED = 4,
	TC_MAGENTA = 5,
	TC_BROWN = 6,
	TC_LIGHTGRAY = 7,
	TC_DARKGRAY = 8,
	TC_LIGHTBLUE = 9,
	TC_LIGHTGREEN = 10,
	TC_LIGHTCYAN = 11,
	TC_LIGHTRED = 12,
	TC_LIGHTMAGENTA = 13,
	TC_YELLOW = 14,
	TC_WHITE = 15
} TextColor;

// set output color on the given stream:
void setTextColor(FILE *stream, TextColor color);
void setTextColor(FILE *stream, TextColor color)
{
	int outfd = fileno(stream);
	HANDLE out = (HANDLE)_get_osfhandle(outfd);
	DWORD outType = GetFileType(out);
	DWORD mode;
	//if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
	//{
	// we're directly outputting to a win32 console if the file type
	// is FILE_TYPE_CHAR and GetConsoleMode() returns success

	SetConsoleTextAttribute(out, color);
	// the enum constants are defined to the same values
	// SetConsoleTextAttribute() uses, so just pass on.
	//}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void starshow(void)
{
	setTextColor(stdout, TC_YELLOW);
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("        ##      ##        ###########        ###########        ###########\n"); delay(100);
	printf("        ###     ##                           ###########        ##         \n"); delay(100);
	printf("        ## #    ##                           ##       ##        ##         \n"); delay(100);
	printf("        ##  #   ##        ###########        ##       ##        ###########\n"); delay(100);
	printf("        ##   #  ##        ###########        ##       ##        ###########\n"); delay(100);
	printf("        ##    # ##                           ##       ##                 ##\n"); delay(100);
	printf("        ##     ###                           ###########                 ##\n"); delay(100);
	printf("        ##      ##        ###########        ###########        ###########\n");
	setTextColor(stdout, TC_LIGHTGRAY);
	delay(2000);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void startfolder(void)
{
	system("cls");
	mkdir("os");
	chdir("os");
	mkdir("user");
	chdir("user");
	mkdir("admin");
	//chdir("admin");
	//chdir("..");
}
//////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void timenow(void)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	setTextColor(stdout, TC_YELLOW);
	printf("			   	  %d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	printf("				     %02d:%02d\n", tm.tm_hour, tm.tm_min);
	if (tm.tm_hour >= 5 && tm.tm_hour < 12)
	{
		printf("				  Good Morning\n");
	}
	else if (tm.tm_hour >= 12 && tm.tm_hour < 18)
	{
		printf("				  Good Afternoon\n");
	}
	else if (tm.tm_hour >= 18 && tm.tm_hour < 24)
	{
		printf("				  Good Night\n");
	}
	else if (tm.tm_hour >= 0 && tm.tm_hour < 5)
	{
		printf("				  Good Night\n");
	}
	setTextColor(stdout, TC_LIGHTGRAY);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int  passsterngth(char pass[])
{
	int sumpower = 0;
	for (int i = 0; pass[i] != '\0'; i++)
	{
		if (islower(pass[i]))
		{
			sumpower += 2;
		}
		else if (isupper(pass[i]))
		{
			sumpower += 4;
		}
		else if (isdigit(pass[i]))
		{
			sumpower += 3;
		}
		else if (ispunct(pass[i]))
		{
			sumpower += 8;
		}
		else if (isspace)
		{
			sumpower += 1;
		}
	}
	if (sumpower > 100)
	{
		sumpower = 100;
	}
	return sumpower;
}
///////////////////////////////////////////////////////////////////////////
int ossearch(char v[400])
{
	
	char a[40] = "os\\user\\";
	if (strstr(v, a))
		return 0;
	else
		return 1;

}
////////////////////////////////////////////////////////////////////////////////////
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}