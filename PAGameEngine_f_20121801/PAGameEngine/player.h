#pragma once
#include "cube.h"
#include "contador.h"
#include "camera_fps.h"
#include "obstacle.h"

class Player : public Cube
{
	Contador* contador = new Contador();
	CameraFPS* playerCamera;
	float speedMultiplier;
	Vector3D minPoint;
	Vector3D maxPoint;
public:
	Player() : Cube()
	{
		speedMultiplier = 1.0f;
		this->playerCamera = new CameraFPS();
		this->playerCamera->setPos(Vector3D(this->getPos().getX(), 6, this->getPos().getZ()));
	}
	CameraFPS* getPlayerCamera() { return this->playerCamera; }
	Contador* getContador() { return this->contador; }
	void setPlayerPos(Vector3D newPos) { this->setPos(newPos); this->playerCamera->setPos(Vector3D(newPos.getX(), 6, newPos.getZ() + 20));}
	void ModifySpeed(float newSpeedMultiplier);
	void SideMovement(float newXSpeed);
	Vector3D getMinPoint() { return this->getPos() - Vector3D(0.5, 0.5, 0.5); }
	Vector3D getMaxPoint() { return this->getPos() + Vector3D(0.5, 0.5, 0.5); }
	bool collisionDetectionAABB(Obstacle* obstacle);
};