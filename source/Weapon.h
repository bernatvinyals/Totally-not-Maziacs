#pragma once
#include "Entity.h"
#include "Mapa.h"
#include "Player.h"
#include "Goal.h"
class Weapon:public Entity
{
	Player* _obj_player;
	Goal* _obj_Goal;

	void genPos();
public:
	Weapon();
	~Weapon();

	void init(Mapa* objMap, Goal* ptrGoal, Player* ptrPlayer, int id);
	void update();
	void render();

	bool isOverlaping();
};

