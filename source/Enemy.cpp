#include "Enemy.h"
#include <time.h>
#include <stdlib.h>
#include "ConsoleControl/ConsoleControl.h"

void Enemy::genPos()
{
	int roundstoPosition = rand() % ((SIZE * 3));
	int roundstoPositiony = rand() % ((SIZE * 3));
	if (roundstoPosition <= 10)
	{
		roundstoPosition += 10;
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

void Enemy::randomMov()
{
	int whereToGo = rand() % 180;
	switch (whereToGo)
	{
	case 1:
		_position.Y += 1;
		break;
	case 2:
		_position.Y -= 1;
		break;
	case 4:
		_position.X += 1;
		break;
	case 8:
		_position.X -= 1;
		break;
	default:
		break;
	}

}

Enemy::Enemy()
{
	_id = 0;
	_isActive=true;
	_position.X = 0;
	_position.Y = 0;
	_submX = 0;
	_submY = 0;
}

Enemy::~Enemy()
{
}

void Enemy::init(Mapa* objMap, std::vector <Enemy>* objs_enemy, int id)
{
	_id = id;
	_isActive = true;
	_objs_enemies = objs_enemy;
	setCollisionMap(objMap);
	genPos();
	while (_position.X < 5 || _position.Y < 5)
	{
		genPos();
	}
}

void Enemy::update()
{
	if (_isActive)
	{
		_submX = _position.X;
		_submY = _position.Y;
		//Movement
		randomMov();
		isOverlaping();
		if (_position.X > (SIZE * 3))
		{
			_position.X = SIZE * 3;
		}
		if (_position.X < 0)
		{
			_position.X = 0;
		}
		if (_position.Y > (SIZE * 3))
		{
			_position.Y = SIZE * 3;
		}
		if (_position.Y < 0)
		{
			_position.Y = 0;
		}
	}
	else
	{
		_position.X = 0;
		_position.Y = 0;
	}
}

void Enemy::render()
{
	if (_isActive)
	{
		ConsoleSetColor(BLACK, BLACK);
		ConsoleXY(_submX, _submY);
		std::cout << " ";
		ConsoleXY(_position.X, _position.Y);
		ConsoleSetColor(DARKRED, RED);
		std::cout << "!";
	}
}

void Enemy::deactivate()
{
	_isActive = false;
	ConsoleSetColor(BLACK, BLACK);
	ConsoleXY(_position.X, _position.Y);
}

void Enemy::setCollisionMap(Mapa* objMap)
{
	objMap->getMap(_collision);
}

bool Enemy::isOverlaping()
{
	for (unsigned int i = 0; i < _objs_enemies->size(); i++)
	{
		if (_objs_enemies->at(i).getX() == _position.X && _objs_enemies->at(i).getY() == _position.Y && _objs_enemies->at(i).getId() != _id)
		{
			_position.X = _submX;
			_position.Y = _submY;
			return true;
		}
	}
	if (_collision[_position.X][_position.Y] == 1)
	{
		_position.X = _submX;
		_position.Y = _submY;
		return true;
	}
	return false;
}
