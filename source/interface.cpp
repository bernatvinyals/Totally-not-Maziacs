#include "Player.h"
#include "Mapa.h"
#include "Goal.h"
#include "Food.h"
#include "Enemy.h"
#include "Weapon.h"
#include "ConsoleControl/ConsoleControl.h"
#include "fileRWandC.h"
#include <iostream>
#include <vector>
#include <string>
extern int key;
bool menu(bool readFailed) {
	ConsoleSetColor(CYAN, BLACK);
	std::cout << "\n\n    $$$$$$$$\\         $$\\               $$\\ $$\\                 $$\\   $$\\  $$$$$$\\ $$$$$$$$\\ \n";
	std::cout << "    \\__$$  __|        $$ |              $$ |$$ |                $$$\\  $$ |$$  __$$\\\\__$$  __|  \n";
	std::cout << "       $$ | $$$$$$\\ $$$$$$\\    $$$$$$\\  $$ |$$ |$$\\   $$\\       $$$$\\ $$ |$$ /  $$ |  $$ |  \n";
	std::cout << "       $$ |$$  __$$\\\\_$$  _|   \\____$$\\ $$ |$$ |$$ |  $$ |      $$ $$\\$$ |$$ |  $$ |  $$ | \n";
	std::cout << "       $$ |$$ /  $$ | $$ |     $$$$$$$ |$$ |$$ |$$ |  $$ |      $$ \\$$$$ |$$ |  $$ |  $$ | \n";
	std::cout << "       $$ |$$ |  $$ | $$ |$$\\ $$  __$$ |$$ |$$ |$$ |  $$ |      $$ |\\$$$ |$$ |  $$ |  $$ | \n";
	std::cout << "       $$ |\\$$$$$$  | \\$$$$  |\\$$$$$$$ |$$ |$$ |\\$$$$$$$ |      $$ | \\$$ | $$$$$$  |  $$ | \n";
	std::cout << "       \\__| \\______/   \\____/  \\_______|\\__|\\__| \\____$$ |      \\__|  \\__| \\______/   \\__| \n";
	std::cout << "                                                $$\\   $$ | \n";
	std::cout << "                                                \\$$$$$$  | \n";
	std::cout << "                                                 \\______/ \n";
	ConsoleSetColor(GREEN, BLACK);
	std::cout << "               $$\\      $$\\                     $$\\ \n";
	std::cout << "               $$$\\    $$$ |                    \\__| \n";
	std::cout << "               $$$$\\  $$$$ | $$$$$$\\  $$$$$$$$\\ $$\\  $$$$$$\\   $$$$$$$\\  $$$$$$$\\ \n";
	std::cout << "               $$\\$$\\$$ $$ | \\____$$\\ \\____$$  |$$ | \\____$$\\ $$  _____|$$  _____| \n";
	std::cout << "               $$ \\$$$  $$ | $$$$$$$ |  $$$$ _/ $$ | $$$$$$$ |$$ /      \\$$$$$$\\ \n";
	std::cout << "               $$ |\\$  /$$ |$$  __$$ | $$  _/   $$ |$$  __$$ |$$ |       \\____$$\\ \n";
	std::cout << "               $$ | \\_/ $$ |\\$$$$$$$ |$$$$$$$$\\ $$ |\\$$$$$$$ |\\$$$$$$$\\ $$$$$$$  | \n";
	std::cout << "               \\__|     \\__| \\_______|\\________|\\__| \\_______| \\_______|\\_______/ \n";
	ConsoleSetColor(WHITE, BLACK);

	if (readFailed)
	{
		ConsoleXY(((SIZE * 3) / 2), (SIZE * 3)-10);
		std::cout << "Play some games to see the scoreboard";
	}
	ConsoleXY((SIZE*3)/2, SIZE * 3);
	std::cout << "(1) To Start.";
	ConsoleXY((SIZE * 3) / 2, SIZE * 3 + 1);
	std::cout << "(2) To see the scoreboard.";
	ConsoleXY((SIZE * 3) / 2, SIZE * 3 + 2);
	std::cout << "(3 or ESC) To exit.";

	return true;
}
void gameOver() {
	ConsoleSetColor(RED, BLACK);
	ConsoleXY(0, 4);
	std::cout << "                          $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\  \n";
	std::cout << "                         $$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|   \n";
	std::cout << "                         $$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |          \n";
	std::cout << "                         $$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\       \n";
	std::cout << "                         $$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|       \n";
	std::cout << "                         $$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |           \n";
	std::cout << "                         \\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\    \n";
	std::cout << "                          \\______/ \\__|  \\__|\\__|     \\__|\\________|\n";
	std::cout << "                           $$$$$$\\  $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\  \n";
	std::cout << "                          $$  __$$\\ $$ |   $$ |$$  _____|$$  __$$\\ \n";
	std::cout << "                          $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |\n";
	std::cout << "                          $$ |  $$ |\\$$\\  $$  |$$$$$\\    $$$$$$$  |\n";
	std::cout << "                          $$ |  $$ | \\$$\\$$  / $$  __|   $$  __$$< \n";
	std::cout << "                          $$ |  $$ |  \\$$$  /  $$ |      $$ |  $$ |\n";
	std::cout << "                           $$$$$$  |   \\$  /   $$$$$$$$\\ $$ |  $$ |\n";
	std::cout << "                           \\______/     \\_/    \\________|\\__|  \\__|\n";
	ConsoleSetColor(WHITE, BLACK);
	ConsoleXY((SIZE * 3) / 2, SIZE * 3);
	std::cout << "(1) To Return.";
	key = 0;
	while (key != KB_ESCAPE)
	{
		key = ConsoleInKey();
		switch (key)
		{
		case KB_1:
			return;
			break;
		default:
			break;
		}
	}
}
void gameWin() {
	ConsoleSetColor(GREEN, BLACK);
	ConsoleXY(0, 4);
	std::cout << "                         $$\\     $$\\  $$$$$$\\  $$\\   $$\\       \n";
	std::cout << "                         \\$$\\   $$  |$$  __$$\\ $$ |  $$ |      \n";
	std::cout << "                          \\$$\\ $$  / $$ /  $$ |$$ |  $$ |      \n";
	std::cout << "                           \\$$$$  /  $$ |  $$ |$$ |  $$ |      \n";
	std::cout << "                            \\$$  /   $$ |  $$ |$$ |  $$ |      \n";
	std::cout << "                             $$ |    $$ |  $$ |$$ |  $$ |      \n";
	std::cout << "                             $$ |     $$$$$$  |\\$$$$$$  |      \n";
	std::cout << "                             \\__|     \\______/  \\______/       \n";
	std::cout << "                          $$\\      $$\\ $$$$$$\\ $$\\   $$\\ $$\\    \n";
	std::cout << "                          $$ | $\\  $$ |\\_$$  _|$$$\\  $$ |$$ |   \n";
	std::cout << "                          $$ |$$$\\ $$ |  $$ |  $$$$\\ $$ |$$ |   \n";
	std::cout << "                          $$ $$ $$\\$$ |  $$ |  $$ $$\\$$ |$$ |   \n";
	std::cout << "                          $$$$  _$$$$ |  $$ |  $$ \\$$$$ |\\__|   \n";
	std::cout << "                          $$$  / \\$$$ |  $$ |  $$ |\\$$$ |       \n";
	std::cout << "                          $$  /   \\$$ |$$$$$$\\ $$ | \\$$ |$$\\    \n";
	std::cout << "                          \\__/     \\__|\\______|\\__|  \\__|\\__|   \n";
	ConsoleSetColor(WHITE, BLACK);
	ConsoleXY((SIZE * 3) / 2, SIZE * 3);
	std::cout << "(1) To Return.";
	key = 0;
	while (key != KB_ESCAPE)
	{
		key = ConsoleInKey();
		switch (key)
		{
		case KB_1:
			return;
			break;
		default:
			break;
		}
	}
}

void gameUI(int hp, int score, int food, int weaponCount) {
	ConsoleSetColor(WHITE, BLUE);
	for (int i = 0; i < (SIZE*3); i++)
	{
		ConsoleXY(i, SIZE * 3);
		std::cout << " ";
	}
	ConsoleXY(0, SIZE*3);
	std::cout << "Health: " << hp << " Food: "<< food << " Weapons: " << weaponCount << " Score: "<<score;
}

bool sceneScoreboard() {
	std::vector <ScoreUser> vectScores;
	ConsoleSetColor(GREEN, BLACK);
	ConsoleXY(0, 4);
	std::cout << "   $$$$$$\\   $$$$$$\\   $$$$$$\\  $$$$$$$\\  $$$$$$$$\\ $$$$$$$\\   $$$$$$\\   $$$$$$\\  $$$$$$$\\  $$$$$$$\\  \n";
	std::cout << "  $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ \n";
	std::cout << "  $$ /  \\__|$$ /  \\__|$$ /  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$ /  $$ |$$ /  $$ |$$ |  $$ |$$ |  $$ |\n";
	std::cout << "  \\$$$$$$\\  $$ |      $$ |  $$ |$$$$$$$  |$$$$$\\    $$$$$$$\\ |$$ |  $$ |$$$$$$$$ |$$$$$$$  |$$ |  $$ |\n";
	std::cout << "   \\____$$\\ $$ |      $$ |  $$ |$$  __$$< $$  __|   $$  __$$\\ $$ |  $$ |$$  __$$ |$$  __$$< $$ |  $$ |\n";
	std::cout << "  $$\\   $$ |$$ |  $$\\ $$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |\n";
	std::cout << "  \\$$$$$$  |\\$$$$$$  | $$$$$$  |$$ |  $$ |$$$$$$$$\\ $$$$$$$  | $$$$$$  |$$ |  $$ |$$ |  $$ |$$$$$$$  |\n";
	std::cout << "   \\______/  \\______/  \\______/ \\__|  \\__|\\________|\\_______/  \\______/ \\__|  \\__|\\__|  \\__|\\_______/ \n";
	if (!scoreComp(&vectScores))
	{
		return true;
	}
	
	ConsoleXY(((SIZE * 3) / 2), (SIZE * 3) - 35);
	for (unsigned int i = 0; i < vectScores.size() && i < 10; i++)
	{
		ConsoleColor tempColor;
		if (i % 2 != 0)
		{
			tempColor = CYAN;
		}
		else
		{
			tempColor = DARKCYAN;
		}
		ConsoleSetColor(tempColor, tempColor);
		for (int j = 0; j < 40; j++)
		{
			ConsoleXY(((SIZE * 3) / 2) + j, (SIZE * 3) - 35+ (i*2));
			std::cout << " ";
		}
		ConsoleSetColor(BLACK, tempColor);
		ConsoleXY(((SIZE * 3) / 2)+2, (SIZE * 3) - 35 + (i * 2));
		std::cout << vectScores.at(i)._score;
		ConsoleXY(((SIZE * 3) / 2)+20, (SIZE * 3) - 35 + (i * 2));
		std::cout << vectScores.at(i)._username;
	}
	ConsoleSetColor(WHITE, BLACK);
	ConsoleXY((SIZE * 3) / 2, SIZE * 3);
	std::cout << "(1) To Return.";
	key = 0;
	while (key != KB_ESCAPE)
	{
		key = ConsoleInKey();
		switch (key)
		{
		case KB_1:
			return false;
			break;
		default:
			break;
		}
	}
	return false;
}


bool sceneGame(Player *player, Goal *goal, Mapa *map, std::vector <Enemy> *objs_enemy, std::vector <Food> *objs_food, std::vector <Weapon> *objs_weapons) {
	map->init();
	goal->init(map, player);
	if (objs_enemy->size() == SIZE)
	{
		objs_enemy->clear();
	}
	if (objs_food->size() == SIZE)
	{
		objs_food->clear();
	}
	if (objs_weapons->size() == SIZE)
	{
		objs_weapons->clear();
	}
	objs_enemy->resize(SIZE);
	objs_food->resize(SIZE);
	objs_weapons->resize(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		objs_enemy->at(i).init(map, objs_enemy, i);
		objs_food->at(i).init(map, goal, player, i);
		objs_weapons->at(i).init(map, goal, player, i);
	}
	player->init(map, objs_enemy);
	ConsoleClear();
	map->render(1);
	bool onGame = true;
	while (key != KB_ESCAPE && onGame)
	{
		//Input
		key = ConsoleInKey();

		//UPDATE
		ConsoleSetColor(BLACK, BLACK);
		for (unsigned int i = 0; i < objs_enemy->size(); i++)
		{
			objs_enemy->at(i).update();
			objs_food->at(i).update();
			objs_weapons->at(i).update();
		}
		player->update();
		goal->update();
		//RENDER
		for (unsigned int i = 0; i < objs_enemy->size(); i++)
		{
			objs_enemy->at(i).render();
			objs_food->at(i).render();
			objs_weapons->at(i).render();
		}
		goal->render();
		ConsoleXY(0, 0);
		ConsoleSetColor(WHITE, BLACK);

		player->render();
		gameUI(player->getHP(), player->getScore(), player->getFood(), player->getWeapons());
		ConsoleSetColor(WHITE, BLACK);
		if (goal->hasWin())
		{
			onGame = false;
		}
		if (player->isDead())
		{
			onGame = false;
		}
		ConsoleWait(25);
	}

	std::string input;
	ConsoleXY(SIZE * 3 / 2 -1, SIZE * 3 / 2);
	ConsoleSetColor(WHITE, BLUE);
	std::cout << " ";
	ConsoleXY(SIZE * 3 / 2, SIZE * 3 / 2);
	std::cout << "Write your name: ";
	for (int i = -1; i < 17; i++)
	{
		ConsoleXY((SIZE * 3 / 2) + i, (SIZE * 3 / 2) - 1);
		std::cout << " ";
		ConsoleXY((SIZE*3 / 2)+i, (SIZE * 3 / 2) + 1);
		std::cout << " ";
		ConsoleXY((SIZE * 3 / 2) + i, (SIZE * 3 / 2) + 2);
		std::cout << " ";
	}
	ConsoleXY(SIZE * 3 / 2, (SIZE * 3 / 2) +1);
	std::getline(std::cin, input);
	writeScore(player, &input);
	if (goal->hasWin())
	{
		return true;
	}

	return false;
}