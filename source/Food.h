#pragma once
#include "Mapa.h"
#include "Player.h"
#include "Goal.h"
class Food
{
	int _id;
	bool _isActive;
	Pos _position;
	int _collision[SIZE * 3][SIZE * 3];
	Player* _obj_player;
	Goal* _obj_Goal;

	void genPos();
public:
	Food();
	~Food();

	void init(Mapa* objMap, Goal *ptrGoal, Player* ptrPlayer, int id);
	void update();
	void render();

	int getId() { return _id; }
	int getX() { return _position.X; }
	int getY() { return _position.Y; }
	void deactivate();
	void setCollisionMap(Mapa* objMap);
	bool isOverlaping();
};

