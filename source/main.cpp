#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "ConsoleControl/ConsoleControl.h"
#include "Jugador.h"
#include "Arbre.h"

int tecla;

void initBosc(std::vector <Arbre> *punter);
void renderBosc(std::vector <Arbre> *punter);

int main() {
	//Init
	srand(time(NULL));
	std::vector <Arbre> Bosc;

	Jugador Jan;
	Jan.init();
	Jan.setBosc(&Bosc);
	initBosc(&Bosc);

	while (tecla != KB_ESCAPE)
	{
		//Input
		tecla = ConsoleInKey();

		//Update
		Jan.update();

		//Render
		renderBosc(&Bosc);
		Jan.render();

		ConsoleWait(45);
		ConsoleClear();
	}

	return 0;
}

void initBosc(std::vector <Arbre> *punter)
{
	punter->resize(40 + rand() % 40);
	for (int i = 0; i < punter->size(); i++)
	{
		int rndX = rand() % 80;
		int rndY = rand() % 24;
		punter->at(i).setX(rndX);
		punter->at(i).setY(rndY);
	}
}

void renderBosc(std::vector <Arbre> *punter)
{
	for (int i = 0; i < punter->size(); i++)
	{
		punter->at(i).render();
	}
}
