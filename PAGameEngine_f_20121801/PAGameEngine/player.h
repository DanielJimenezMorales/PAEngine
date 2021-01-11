#pragma once
#include "cube.h"

class Player : public Cube
{
	float speedMultiplier;
public:
	Player() : Cube()
	{
		speedMultiplier = 1.0f;
	}

	void ModifySpeed(float newSpeedMultiplier);
	void SideMovement(float newXSpeed);
};