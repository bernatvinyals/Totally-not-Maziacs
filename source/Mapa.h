#pragma once
#include <vector>
#include <iostream>
#define SIZE 16
struct Pos {
	int X;
	int Y;
};

//NORD: 1
//SOUTH: 2
//EST: 4
//WEST: 8
class Mapa
{
	int _maze[SIZE][SIZE];
	int _mazeGFX[SIZE*3][SIZE*3];
	int _posCount;
	Pos _currentPos;
	std::vector <Pos> _prevPosList;
	int _randNum;
	bool _randPrev[4];

	int _checkedPos;

	void generator();
	int getRandomDirection();
	void addToCount(int i);
	void canContinue(int x, int y);
	void generateGFX();

public:
	Mapa();
	~Mapa();
	void init();
	void render(int mode);
	bool isWalOnPos(int x, int y);
	void getMap(int outMAP[][SIZE*3]);
};

