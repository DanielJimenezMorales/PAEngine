#pragma once
#include "text.h"
#include <chrono>

using namespace std::chrono;

class Contador : public Text
{
	int maxLifes;
	int lifesLeft;

public:
	Contador(int ml = 3) : maxLifes(ml), Text()
	{
		lifesLeft = ml;
	}

	~Contador() {}

	int getLifesLeft() { return this->lifesLeft; }
	void getDamaged();
};

