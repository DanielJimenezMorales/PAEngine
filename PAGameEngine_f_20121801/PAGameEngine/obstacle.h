#pragma once
#include "cube.h"

class Obstacle : public Cube
{

public:
	Obstacle(Vector3D col = Vector3D(1,0,0)) : Cube() {
		this->setColor(col);
	}
	~Obstacle() {}

	Obstacle* clone() {
		return new Obstacle(*this);
	}
};

