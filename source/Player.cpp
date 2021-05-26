#include "Player.h"
#include <vector>
#include "ConsoleControl/ConsoleControl.h"
extern int key;
Player::Player()
{
	_position.X = 0;
	_position.Y = 0;
	_hp = 3;
	_score = 0;
	_submX = 0;
	_submY = 0;
	_food = 0;
	_weaponCount = 0;
}

Player::~Player()
{
}

void Player::init(Mapa* objMap, std::vector <Enemy> *ptr_objs_enemy)
{
	_vect_objs_enemy = ptr_objs_enemy;
	_position.X = 1;
	_position.Y = 1;
	setCollisionMap(objMap);
	resetHP();
	resetFood();
	resetScore();
	resetWeapons();
}

void Player::update()
{
	_submX = _position.X;
	_submY = _position.Y;
	switch (key)
	{
	case KB_DOWN:
		_position.Y = _position.Y+1;
		break;
	case KB_UP:
		_position.Y = _position.Y - 1;
		break;
	case KB_LEFT:
		_position.X = _position.X - 1;
		break;
	case KB_RIGHT:
		_position.X = _position.X + 1;
		break;
	default:
		break;
	}
	//TODO: Colision 
	if (isOverlaping())
	{
		_position.X = _submX;
		_position.Y = _submY;
	}
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
		_position.Y = SIZE*3;
	}
	if (_position.Y < 0)
	{
		_position.Y = 0;
	}
}

void Player::render()
{
	ConsoleXY(_submX, _submY);
	std::cout << " ";
	ConsoleXY(_position.X, _position.Y);
	ConsoleSetColor(BLUE, WHITE);
	std::cout << "0";
}

void Player::addFood()
{
	if (_hp < 3)
	{
		_hp++;
	}
	else
	{
		_food += 1;
	}
}

void Player::setCollisionMap(Mapa* objMap)
{
	objMap->getMap(_collision);
}

void Player::hitPlayer()
{
	if (_weaponCount > 0)
	{
		_weaponCount -= 1;
	}
	else if (_food > 0)
	{
		_food -= 1;
	}
	else
	{
		_hp -= 1; 
	}
}

bool Player::isOverlaping()
{
	for (unsigned int i = 0; i < _vect_objs_enemy->size(); i++)
	{
		if (_vect_objs_enemy->at(i).getX() == _submX && _vect_objs_enemy->at(i).getY() == _submY)
		{
			_vect_objs_enemy->at(i).deactivate();
			hitPlayer();
			if (_hp>0)
			{
				addScore();
			}
		}
	}
	if (_collision[_position.X][_position.Y] == 0)
	{
		return false;
	}
	return true;
}
