#pragma once
#include "game.h"


class MyGame : public Game
{

public:
	MyGame() : Game() {}
	void clearScenes();
	void render();
	void update();
	void processKeyPressed(unsigned char key, int x, int y);
	void empezarJuego();
	void gameOver();
	void espera(int segundos)
	{
		clock_t instanteFinal;
		instanteFinal = clock() + segundos * CLOCKS_PER_SEC;
		while (clock() < instanteFinal) {}
		cout << "fin" << endl;
	}
};

