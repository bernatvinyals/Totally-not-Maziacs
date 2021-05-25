#include "Weapon.h"
#include <time.h>
#include <stdlib.h>
#include "ConsoleControl/ConsoleControl.h"

void Weapon::genPos()
{
	int roundstoPosition = rand() % ((SIZE * 3));
	int roundstoPositiony = rand() % ((SIZE * 3));
	if (roundstoPosition <= 3)
	{
		roundstoPosition += 5;
	}
	if (roundstoPositiony <= 10)
	{
		roundstoPositiony += 10;
	}
	for (int i = 0; i < roundstoPositiony; i++)
	{
		for (int z = 0; z < roundstoPosition; z++)
		{
			if (_collision[z][i] == 0)
			{
				_position.X = z;
				_position.Y = i;
			}
		}
	}
}

Weapon::Weapon()
{
	_id = 0;
	_isActive = true;
	_position.X = 0;
	_position.Y = 0;
	_obj_player = 0;
	_obj_Goal = 0;

}

Weapon::~Weapon()
{
}

void Weapon::init(Mapa* objMap, Goal* ptrGoal, Player* ptrPlayer, int id)
{
	_id = id;
	_isActive = true;
	_obj_player = ptrPlayer;
	_obj_Goal = ptrGoal;
	_position.X = 0;
	_position.Y = 0;
	setCollisionMap(objMap);
	genPos();
	while (_position.X < 5 || _position.Y < 5 && (_obj_Goal->getX() != _position.X && _obj_Goal->getY() != _position.Y))
	{
		genPos();
	}
}

void Weapon::update()
{
	if (_isActive)
	{
		isOverlaping();
	}
	else
	{
		_position.X = 0;
		_position.Y = 0;
	}
}

void Weapon::render()
{
	if (_isActive)
	{
		ConsoleXY(_position.X, _position.Y);
		ConsoleSetColor(DARKGREEN, GREEN);
		std::cout << "/";
	}
}

void Weapon::deactivate()
{
	_isActive = false;
	ConsoleSetColor(BLACK, BLACK);
	ConsoleXY(_position.X, _position.Y);
}

void Weapon::setCollisionMap(Mapa* objMap)
{
	objMap->getMap(_collision);
}

bool Weapon::isOverlaping()
{
	if (_obj_player->getX() == _position.X && _obj_player->getY() == _position.Y)
	{
		deactivate();
		_obj_player->addScore();
		_obj_player->addWeapon();
	}
	return false;
}
