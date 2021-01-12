#pragma once

#include "composite.h"
#include "camera_fps.h"

class GameScene : public Composite
{
	Vector3D size;
	double mx, my;
	CameraFPS* camera;

public:
	GameScene(Vector3D s = Vector3D(10, 10, 10)) : size(s), Composite()
	{
		this->camera = new CameraFPS();
		this->camera->setPos(Vector3D(this->size.getX() / 2, this->size.getY() / 2, size.getZ()));
	}
	inline Vector3D getSize() const { return this->size; }
	inline void setSize(const Vector3D& sizeToSet) { this->size = sizeToSet; this->camera->setPos(Vector3D(size.getX() / 2, size.getY() / 2, size.getZ() * 2)); }
	CameraFPS* getCamera();
	void update(const double& dt);
	void render(CameraFPS* renderCamera);
	void processKeyPressed(unsigned char key, int x, int y);
	void processMouseMovement(int x, int y);
	void processMouseClick(int button, int state, int x, int y);
	GameScene* clone();
};

