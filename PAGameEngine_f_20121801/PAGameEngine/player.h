#pragma once
#include "cube.h"
#include "contador.h"

class Player : public Cube
{
	Contador* contador = new Contador();
	float speedMultiplier;
public:
	Player() : Cube()
	{
		speedMultiplier = 1.0f;
	}

	Contador* getContador() { return this->contador; }
	void ModifySpeed(float newSpeedMultiplier);
	void SideMovement(float newXSpeed);
};