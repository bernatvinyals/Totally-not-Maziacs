#pragma once
#include "Mapa.h"
#include "Enemy.h"
#include <vector>
#include "Entity.h"
class Player:public Entity
{
	std::vector <Enemy> *_vect_objs_enemy;

	int _submX;
	int _submY;

	int _hp;
	int _score;
	int _food;
	int _weaponCount;
public:
	Player();
	~Player();

	void init(Mapa* objMap, std::vector <Enemy>* ptr_objs_enemy);
	void update();
	void render();

	int getHP() { return _hp; }
	int getScore() { return _score; }
	int getFood() { return _food; }
	int getWeapons() { return _weaponCount; }

	void addScore() { _score += 10; }
	void addWeapon() { _weaponCount += 1; }
	void addFood();

	void hitPlayer();
	void resetHP() { _hp = 3; }
	void resetScore() { _score = 0; }
	void resetFood() { _food = 0; }
	void resetWeapons() { _weaponCount = 0; }
	bool isOverlaping();
	bool isDead() { return _hp == 0; }
};

