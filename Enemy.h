#pragma once
#include "Mapa.h"
#include <vector>
class Enemy
{
	bool _isActive;
	int _id;
	Pos _position;
	int _collision[SIZE * 3][SIZE * 3];
	std::vector <Enemy> *_objs_enemies;

	int _submX;
	int _submY;

	void genPos();
	void randomMov();
public:
	Enemy();
	~Enemy();

	void init(Mapa* objMap, std::vector <Enemy>* objs_enemy, int id);
	void update();
	void render();

	int getId() { return _id; }
	int getX() { return _position.X; }
	int getY() { return _position.Y; }
	void deactivate();
	void setCollisionMap(Mapa* objMap);
	bool isOverlaping();
};

