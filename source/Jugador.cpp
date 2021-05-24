#include "Jugador.h"
#include <iostream>
#include "ConsoleControl/ConsoleControl.h"

extern int tecla;

Jugador::Jugador()
{
	mX = 0;
	mY = 0;
}


Jugador::~Jugador()
{
}

void Jugador::init()
{
	mX = 79;
	mY = 23;
}

void Jugador::update()
{
	int submX = mX;
	int submY = mY;
	switch (tecla)
	{
		case KB_DOWN:
			mY++;
			break;
		case KB_UP:
			mY--;
			break;
		case KB_LEFT:
			mX--;
			break;
		case KB_RIGHT:
			mX++;
			break;
		default:
			break;
	}
	if (isOverlaping(Bosc))
	{
		mX = submX;
		mY = submY;
	}
	if (mX >80)
	{
		mX = 80;
	}
	if (mX < 0)
	{
		mX = 0;
	}
	if (mY > 23)
	{
		mY = 23;
	}
	if (mY < 0)
	{
		mY = 0;
	}
}

void Jugador::render()
{
	ConsoleXY(mX, mY);
	ConsoleSetColor(BLUE, WHITE);
	std::cout << "0";
}

void Jugador::setBosc(std::vector<Arbre>* _Bosc)
{
	Bosc = _Bosc;
}

bool Jugador::isOverlaping(std::vector<Arbre>* punter)
{
	for (int i = 0; i < punter->size(); i++)
	{
		int checkInt = 0;
		if (mX == punter->at(i).getX())
		{
			checkInt++;
		}
		if (mY == punter->at(i).getY())
		{
			checkInt++;
		}
		if (checkInt == 2)
		{
			return true;
		}
	}
	return false;
}
