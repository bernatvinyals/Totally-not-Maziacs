#pragma once
#include "Arbre.h"
#include <vector>
class Jugador
{
	int mX;
	int mY;
	std::vector <Arbre> *Bosc;

public:
	Jugador();
	~Jugador();

	void init();
	void update();
	void render();

	int getX() { return mX; }
	int getY() { return mY; }

	void setX(int value) { mX = value; }
	void setY(int value) { mY = value; }

	void setBosc(std::vector <Arbre> *_Bosc);

	bool isOverlaping(std::vector <Arbre> *punter);

};

