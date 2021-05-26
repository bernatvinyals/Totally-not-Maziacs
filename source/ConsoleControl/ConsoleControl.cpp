#include "ConsoleControl.h"

#include <conio.h>
#include <windows.h>

HANDLE StdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void ConsoleSetColor(ConsoleColor ForeColor, ConsoleColor BackColor){
	WORD color = (BackColor << 4) | ForeColor;
	SetConsoleTextAttribute(StdHandle, color);	
}

void ConsoleXY(short int x, short int y){
	COORD pos = { x, y };
	SetConsoleCursorPosition(StdHandle, pos);
}

void ConsoleClear() {
	ConsoleClearCharacter(' ', WHITE, BLACK);
}

void ConsoleClearCharacter(char character, ConsoleColor ForeColor, ConsoleColor BackColor) {
	COORD topLeft = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;
	WORD color = (BackColor << 4)| ForeColor;
	GetConsoleScreenBufferInfo(StdHandle, &screen);
	FillConsoleOutputCharacter(
		StdHandle, character, screen.srWindow.Right * screen.srWindow.Bottom, topLeft, &written
		);
	FillConsoleOutputAttribute(
		StdHandle, color,
		screen.srWindow.Right * screen.srWindow.Bottom, topLeft, &written
		);
	SetConsoleCursorPosition(StdHandle, topLeft);
}

void ConsoleWait(unsigned long milisecons){
	Sleep(milisecons);
}
void ChangeTextFontSize(int sizeX, int sizeY) {
	CONSOLE_FONT_INFOEX cfi = { sizeof(cfi) };
	GetCurrentConsoleFontEx(StdHandle, FALSE, &cfi);
	// Modify the font size in cfi
	cfi.dwFontSize.X = sizeX;
	cfi.dwFontSize.Y = sizeY;
	SetCurrentConsoleFontEx(StdHandle, FALSE, &cfi);
}
void ConsoleWindowSize(int xSize, int ySize) {
	_SMALL_RECT rect = { sizeof(rect) };
	rect.Right = xSize;
	rect.Bottom = ySize;
	rect.Top = 0;
	rect.Left = 0;
	SetConsoleWindowInfo(StdHandle, TRUE, &rect);
}
void HideConsoleCursor() {
	_CONSOLE_CURSOR_INFO cci = { sizeof(cci) };
	cci.dwSize = 1;
	cci.bVisible = false;
	SetConsoleCursorInfo(StdHandle, &cci);
}
int ConsoleInKey(){
	int KB_code = 0;

	if (_kbhit())
	{
		KB_code = _getch();
	}
	return KB_code;
}