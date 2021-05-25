#include "Mapa.h"
#include "Player.h"
#include "Goal.h"
#include "Food.h"
#include "Weapon.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <fstream>

bool writeScore(Player *ptrObjPlayer, std::string * ptrInput) {
	std::fstream handler;
	handler.open("./score.txt", std::ios::app);
	if (!handler.is_open())
	{
		std::cout << "No s'ha obert el fitxer";
		return false;
	}
	handler << ptrObjPlayer->getScore() << ";" << *ptrInput;
	handler << "\n";
	return true;
}
