#pragma once

#include "scene.h"

class GameScene : public Scene
{
	Vector3D size;
	double mx, my;
	bool hasPlayer;

public:
	GameScene(bool hp = false) : hasPlayer(hp), Scene() {}
	//inline void setSize(const Vector3D& sizeToSet) { this->size = sizeToSet; this->camera->setPos(Vector3D(size.getX() / 2, size.getY() / 2, size.getZ() * 2)); }
	void render();
	void update(const double& dt);
};