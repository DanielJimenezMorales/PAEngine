#pragma once

#include "game.h"

class MyGame : public Game
{
	Ranking* ranking;
public:
	MyGame() : Game()
	{
		ranking = new Ranking();
		askForPlayerName();
	}

	~MyGame() 
	{
		delete ranking;
	}

	void askForPlayerName();
	void clearScenes();
	void render();
	void update();
	void checkCollisions();
	bool checkWin(float winDistance);
	void processKeyPressed(unsigned char key, int x, int y);
	void empezarJuego();
	void winGame();
};