#pragma once
#include "cube.h"

class Obstacle : public Cube
{

public:
	Obstacle() : Cube() {}

	Obstacle* clone() {
		return new Obstacle(*this);
	}
};

