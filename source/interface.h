#pragma once
#include "Food.h"
#include "Weapon.h"
void gameUI(int hp, int score, int food, int weaponCount);
bool menu();
void gameWin();
void gameOver();
bool sceneScoreboard();
bool sceneGame(Player* player, Goal* goal, Mapa* map, std::vector <Enemy>* objs_enemy, std::vector <Food>* objs_food, std::vector <Weapon> *objs_weapons);