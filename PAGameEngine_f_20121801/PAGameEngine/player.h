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

	int pointsNumber;

public:
	Player(Vector3D col = Vector3D(0.5,0.5,1)) : Cube()
	{
		this->setColor(col);
		speedMultiplier = 1.0f;
		pointsNumber = 0;
		this->playerCamera = new CameraFPS();
		this->playerCamera->setPos(Vector3D(this->getPos().getX(), 6, this->getPos().getZ()));
	}

	~Player()
	{
		delete contador;
		delete playerCamera;
	}

	int getPoints() { return this->pointsNumber; }
	void addPoints(int x) { this->pointsNumber += x; };
	CameraFPS* getPlayerCamera() { return this->playerCamera; }
	Contador* getContador() { return this->contador; }
	void setPlayerPos(Vector3D newPos) { this->setPos(newPos); this->playerCamera->setPos(Vector3D(newPos.getX(), 6, newPos.getZ() + 10));}
	void ModifySpeed(float newSpeedMultiplier);
	void SideMovement(float newXSpeed);
	Vector3D getMinPoint() { return this->getPos() - Vector3D(this->getSize() / 2, this->getSize() / 2, this->getSize() / 2); }
	Vector3D getMaxPoint() { return this->getPos() + Vector3D(this->getSize() / 2, this->getSize() / 2, this->getSize() / 2); }
	bool collisionDetectionAABB(Solid* obstacle);
	void update(double dt);
};