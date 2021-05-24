#include "Mapa.h"
#include <time.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include "ConsoleControl/ConsoleControl.h"


void Mapa::addToCount(int i){
	_randPrev[i] = true;
}
void Mapa::canContinue(int x, int y) {
	_posCount += 1;
	_prevPosList.push_back(_currentPos);

	_maze[_currentPos.X][_currentPos.Y] += _randNum;
	_currentPos.X = _currentPos.X + x;
	_currentPos.Y = _currentPos.Y + y;

	switch (_randNum)
	{
	case 1:
		_randNum = 2;
		break;
	case 2:
		_randNum = 1;
		break;
	case 4:
		_randNum = 8;
		break;
	case 8:
		_randNum = 4;
		break;
	default:
		break;
	}
	_maze[_currentPos.X][_currentPos.Y] += _randNum;
	_checkedPos = 0;
	for (int i = 0; i < 4; i++)
	{
		_randPrev[i] = false;
	}
}
void Mapa::generateGFX()
{
	for (int X = 0; X < SIZE; X++)
	{
		for (int Y = 0; Y < SIZE; Y++)
		{
			switch (_maze[X][Y])
			{
			case 1:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 0;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 1;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 2:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 1;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 1;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 3:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 0;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 1;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 4:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 1;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 0;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 5:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 0;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 0;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 6:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 1;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 0;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 7:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 0;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 0;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 8:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 1;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 1;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 9:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 0;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 1;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 10:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 1;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 1;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 11:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 0;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 1;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 12:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 1;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 0;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 13:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 0;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 0;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 14:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 1;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 0;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			case 15:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 0;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 0;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 0; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			default:
				_mazeGFX[X * 3][Y * 3] = 1;     _mazeGFX[X * 3 + 1][Y * 3] = 1;     _mazeGFX[X * 3 + 2][Y * 3] = 1;
				_mazeGFX[X * 3][Y * 3 + 1] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 1] = 1; _mazeGFX[X * 3 + 2][Y * 3 + 1] = 1;
				_mazeGFX[X * 3][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 1][Y * 3 + 2] = 1; _mazeGFX[X * 3 + 2][Y * 3 + 2] = 1;
				break;
			}
		}
	}

}
void Mapa::generator()
{

	if (_checkedPos >=15)
	{
		//2.4 al llibre SOME THING IT OUT OF TABLE
		if (_prevPosList.size() != 0 )
		{
			_currentPos = _prevPosList.at(_prevPosList.size() - 1);
			_prevPosList.erase(_prevPosList.begin() + _prevPosList.size() - 1);
			for (int i = 0; i < 4; i++)
			{
				_randPrev[i] = false;
			}
		}
		_checkedPos = 0;
	}
	_randNum = getRandomDirection();	
	switch (_randNum)//1  2  4  8
	{
	case 1:
		if (!isWalOnPos(_currentPos.X, _currentPos.Y - 1))
		{
			canContinue(0,-1);
		}
		else
		{
			//Check we dont add more tries if it is the same rand number 
			addToCount(0);
		}
		break;
	case 2:
		if (!isWalOnPos(_currentPos.X, _currentPos.Y + 1))
		{
			canContinue(0,1);
		}
		else
		{
			addToCount(1);
		}
		break;
	case 4:
		if (!isWalOnPos(_currentPos.X + 1, _currentPos.Y))
		{
			canContinue(1,0);
		}
		else
		{
			addToCount(2);
		}
		break;
	case 8:
		if (!isWalOnPos(_currentPos.X - 1, _currentPos.Y))
		{
			canContinue(-1,0);
		}
		else
		{
			addToCount(3);
		}
		break;
	default:
		break;
	}
}

int Mapa::getRandomDirection()
{
	bool reset = true;
	int tempN = 0;
	do
	{
		tempN = rand() % 4;//0 1 2 3
		if (_randPrev[tempN] == false)
		{
			reset = false;
		}
	} while (reset);
	return (std::pow(2, tempN));//0=1  1=2  2=4  3=8
}

Mapa::Mapa()
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			_maze[y][x] = 0;
			
		}
	}
	for (int y = 0; y < (SIZE*3); y++)
	{
		for (int x = 0; x < SIZE*3; x++)
		{
			_mazeGFX[y][x] = 0;

		}
	}
	
	_posCount = 1;
	_currentPos.X = 0;
	_currentPos.Y = 0;
	_randNum = 0;
	for (int i = 0; i < 4; i++)
	{
		_randPrev[i] = false;
	}
	_checkedPos = 0;
}


Mapa::~Mapa()
{
}

void Mapa::init()
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			_maze[y][x] = 0;

		}
	}
	for (int y = 0; y < (SIZE * 3); y++)
	{
		for (int x = 0; x < SIZE * 3; x++)
		{
			_mazeGFX[y][x] = 0;

		}
	}

	_posCount = 1;
	_currentPos.X = 0;
	_currentPos.Y = 0;
	_randNum = 0;
	for (int i = 0; i < 4; i++)
	{
		_randPrev[i] = false;
	}
	_checkedPos = 0;
	_currentPos.X = rand() % SIZE;
	_currentPos.Y = rand() % SIZE;
	_prevPosList.push_back(_currentPos);
	while (_posCount != (SIZE * SIZE))
	{
		generator();
	}
	generateGFX();
}

void Mapa::render(int mode)
{
	std::cout << std::endl;
	char wall = '#';
	char corridor = ' ';
	for (int y = 0; y < (SIZE*3); y++)
	{
		for (int x = 0; x < (SIZE * 3); x++)
		{
			if (mode == 0)
			{
				if (_mazeGFX[x][y] == 1)
				{
					std::cout << wall;
				}
				else
				{
					std::cout << corridor;
				}
			}
			if (mode == 1)
			{
				ConsoleXY(x, y);
				if (_mazeGFX[x][y] == 1)
				{
					ConsoleSetColor(WHITE, WHITE);
					std::cout << wall;
				}
				else
				{
					ConsoleSetColor(BLACK, BLACK);
					std::cout << corridor;
				}
			}
		}
		std::cout << std::endl;
	}
}


bool Mapa::isWalOnPos(int x, int y)
{
	if (x >=SIZE || y>=SIZE || y<0 || x<0 )
	{
		_checkedPos += _randNum;
		return true;
	}
	if (_maze[x][y] !=0)
	{
		_checkedPos += _randNum;
		return true;
	}
	return false;
}

void Mapa::getMap(int outMAP[][SIZE * 3])
{
	for (int y = 0; y < (SIZE * 3); y++)
	{
		for (int x = 0; x < (SIZE * 3); x++)
		{
			outMAP[x][y] = _mazeGFX[x][y];
		}
		std::cout << std::endl;
	}
}
