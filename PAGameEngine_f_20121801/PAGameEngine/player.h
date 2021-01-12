#pragma once
#include "cube.h"
#include "contador.h"

class Player : public Cube
{
	Contador* contador = new Contador();
	float speedMultiplier;
	Vector3D minPoint;
	Vector3D maxPoint;
public:
	Player() : Cube()
	{
		speedMultiplier = 1.0f;
	}

	Contador* getContador() { return this->contador; }
	void ModifySpeed(float newSpeedMultiplier);
	void SideMovement(float newXSpeed);
	Vector3D getMinPoint() { return this->getPos() - Vector3D(0.5, 0.5, 0.5); }
	Vector3D getMaxPoint() { return this->getPos() + Vector3D(0.5, 0.5, 0.5); }
	bool collisionDetectionAABB(Cube* obstacle);
};