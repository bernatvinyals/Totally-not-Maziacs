#include "Goal.h"
#include "Mapa.h"
#include <time.h>
#include <stdlib.h>
#include "ConsoleControl/ConsoleControl.h"


Goal::Goal()
{
	_position.X = 0;
	_position.Y = 0;
	_objPlayer = 0;
	_goalIsHit = false;
}

Goal::~Goal()
{
}

void Goal::init(Mapa* objMap, Player* _ptrPlayer)
{
	setCollisionMap(objMap);
	_goalIsHit = false;
	_objPlayer = _ptrPlayer;
	genPos();
	while(_position.X < 20 || _position.Y < 20)
	{
		genPos();
	}
}

void Goal::update()
{
	if (isPlayerTouching())
	{
		_goalIsHit = true;
	}
}

void Goal::render()
{
	ConsoleXY(_position.X, _position.Y);
	ConsoleSetColor(WHITE, CYAN);
	std::cout << "*";
}

void Goal::genPos()
{
	int roundstoPosition = rand() % ((SIZE * 3));
	if (roundstoPosition <= 10)
	{
		roundstoPosition += 20;
	}
	for (int i = 0; i < roundstoPosition; i++)
	{
		for (int z = 0; z < roundstoPosition; z++)
		{
			if (_collision[z][i]==0)
			{
				_position.X = z;
				_position.Y = i;
			}
		}
	}
}

bool Goal::isPlayerTouching()
{
	if (_objPlayer->getX() == _position.X && _objPlayer->getY() == _position.Y)
	{
		_objPlayer->addScore();
		return true;
	}
	return false;
}
