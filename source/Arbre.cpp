#include "Arbre.h"
#include <iostream>
#include "ConsoleControl/ConsoleControl.h"


Arbre::Arbre()
{
	mX = 0;
	mY = 0;
}


Arbre::~Arbre()
{
}

void Arbre::init()
{
}

void Arbre::update()
{
}

void Arbre::render()
{
	ConsoleXY(mX, mY);
	ConsoleSetColor(DARKGREEN, DARKYELLOW);
	std::cout << "$";
}
