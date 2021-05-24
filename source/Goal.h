#pragma once
#include "Mapa.h"
#include "Player.h"
class Goal
{
	Pos _position;
	int _collision[SIZE * 3][SIZE * 3];
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
	void setCollisionMap(Mapa* objMap);
	bool hasWin() { return _goalIsHit; };
	int getX() { return _position.X; }
	int getY() { return _position.Y; }
};

