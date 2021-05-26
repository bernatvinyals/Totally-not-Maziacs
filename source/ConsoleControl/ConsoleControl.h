#pragma once
#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_SPACE 32
#define KB_ESCAPE 27
#define KB_0 48
#define KB_1 49
#define KB_2 50
#define KB_3 51
#define KB_4 52
#define KB_5 53
#define KB_6 54
#define KB_7 55
#define KB_8 56
#define KB_9 57
enum ConsoleColor { 
	BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA, DARKYELLOW, LIGHTGREY,
	DARKGREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
};

void ConsoleSetColor(ConsoleColor ForeColor, ConsoleColor BackColor);
void ConsoleXY(short int x, short int y);
void ConsoleClear();
void ConsoleClearCharacter(char character, ConsoleColor ForeColor, ConsoleColor BackColor);

void ConsoleWait(unsigned long milisecons);
void ConsoleWindowSize(int xSize, int ySize);
void HideConsoleCursor();
int ConsoleInKey();
void ChangeTextFontSize(int sizeX, int sizeY);