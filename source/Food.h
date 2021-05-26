#pragma once
#include "Entity.h"
#include "Mapa.h"
#include "Player.h"
#include "Goal.h"
class Food :public Entity
{
	Player* _obj_player;
	Goal* _obj_Goal;

	void genPos();
public:
	Food();
	~Food();

	void init(Mapa* objMap, Goal *ptrGoal, Player* ptrPlayer, int id);
	void update();
	void render();

	bool isOverlaping();
};

