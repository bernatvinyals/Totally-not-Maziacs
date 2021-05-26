#pragma once
#include "Mapa.h"
#include "Enemy.h"
#include <vector>
class Player
{
	Pos _position;
	int _collision[SIZE * 3][SIZE * 3];
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

	int getX() { return _position.X; }
	int getY() { return _position.Y; }
	int getHP() { return _hp; }
	int getScore() { return _score; }
	int getFood() { return _food; }
	int getWeapons() { return _weaponCount; }

	void setX(int value) { _position.X = value; }
	void setY(int value) { _position.Y = value; }
	void addScore() { _score += 10; }
	void addWeapon() { _weaponCount += 1; }
	void addFood();
	void setCollisionMap(Mapa* objMap);

	void hitPlayer();
	void resetHP() { _hp = 3; }
	void resetScore() { _score = 0; }
	void resetFood() { _food = 0; }
	void resetWeapons() { _weaponCount = 0; }
	bool isOverlaping();
	bool isDead() { return _hp == 0; }
};

