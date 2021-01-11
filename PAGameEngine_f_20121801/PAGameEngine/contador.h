#pragma once
#include "text.h"
#include <windows.h>

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
};

