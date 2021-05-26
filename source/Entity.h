#pragma once
#include "Mapa.h"
#include <vector>
class Entity
{
protected:
	bool _isActive;
	int _id;
	Pos _position;
	int _collision[SIZE * 3][SIZE * 3];

public:
	Entity();
	~Entity();

	void init();
	void update();
	void render();

	int getId() { return _id; }
	int getX() { return _position.X; }
	int getY() { return _position.Y; }
	void setX(int value) { _position.X = value; }
	void setY(int value) { _position.Y = value; }
	void setCollisionMap(Mapa* objMap);
	void deactivate();
	bool isOverlaping();
};

