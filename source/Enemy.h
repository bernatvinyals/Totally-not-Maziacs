#pragma once
#include "Mapa.h"
#include "Entity.h"
#include <vector>
class Enemy:public Entity
{
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

	bool isOverlaping();
};

