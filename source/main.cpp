#include "Mapa.h"
#include "Player.h"
#include "Goal.h"
#include "Food.h"
#include "Weapon.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "ConsoleControl/ConsoleControl.h"
#include "interface.h"


int key;
int main() {
	srand((unsigned int)time(NULL));
	Mapa map;
	Player player;
	Goal goal;
	std::vector <Enemy> objs_enemy;
	std::vector <Food> objs_food;
	std::vector <Weapon> objs_weapons;
	bool menuOn = false;
	bool hasWin = false;
	bool readFailed = false;
	ConsoleWindowSize(102, 69);
	ChangeTextFontSize(8, 8);
	HideConsoleCursor();
	while (key != KB_ESCAPE)
	{
		ConsoleWindowSize(102, 69);
		ChangeTextFontSize(8, 8);
		key = ConsoleInKey();
		if (!menuOn)
		{
			menuOn = menu(readFailed);
		}
		switch (key)
		{
		case KB_1:
			hasWin = sceneGame(&player, &goal, &map, &objs_enemy, &objs_food, &objs_weapons);
			ConsoleClear();
			if (hasWin)
			{
				gameWin();
				readFailed = false;
			}
			else
			{
				gameOver();
				readFailed = false;
			}
			ConsoleClear();
			menuOn = false;
			key = 0;
			break;
		case KB_2:
			ConsoleClear();
			readFailed = sceneScoreboard();
			ConsoleClear();
			menuOn = false;
			break;
		case KB_3://TODO: SCOREBOARD
			key = KB_ESCAPE;
			break;
		default:
			break;
		}
	}
	return 0;
}