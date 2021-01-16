#pragma once

#include "game.h"


class MyGame : public Game
{
	
public:
	MyGame() : Game()
	{
		
	}
	void clearScenes();
	void render();
	void update();
	void processKeyPressed(unsigned char key, int x, int y);
	void empezarJuego();
	void gameOver();
};

