#pragma once

#include "game.h"


class MyGame : public Game
{
	
public:
	MyGame() : Game()
	{
		string userName = "";
		cout << "Introduce tu nombre de jugador y pulsa ENTER para continuar" << endl;
		cin >> userName;
		ranking->setPlayerName(userName);
	}
	void clearScenes();
	void render();
	void update();
	void processKeyPressed(unsigned char key, int x, int y);
	void empezarJuego();
	void gameOver();
};