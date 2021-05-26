#pragma once
#include "Entity.h"
#include "Mapa.h"
#include "Player.h"
class Goal :public Entity
{
	bool _goalIsHit;
	Player* _objPlayer;
	void genPos();
	bool isPlayerTouching();
public:
	Goal();
	~Goal();
	void init(Mapa* objMap, Player *_ptrPlayer);
	void update();
	void render();
	bool hasWin() { return _goalIsHit; };
};

