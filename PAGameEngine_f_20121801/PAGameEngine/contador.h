#pragma once
#include "text.h"
#include <chrono>

using namespace std::chrono;

class Contador : public Text
{
	int min;
	int seg;
	int maxMin;
public:
	Contador() : Text()
	{
		maxMin = 2;
		min = maxMin;
		seg = 0;
	}

	void empezarContador();
	void update();
};

