#pragma once
#include "game.h"


class MyGame : public Game
{


public:
	MyGame() : Game() {}	
	void processKeyPressed(unsigned char key, int x, int y);
};

