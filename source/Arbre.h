#pragma once
class Arbre
{
	int mX;
	int mY;

public:
	Arbre();
	~Arbre();

	void init();
	void update();
	void render();


	int getX() { return mX; }
	int getY() { return mY; }

	void setX(int value) { mX = value; }
	void setY(int value) { mY = value; }
};

