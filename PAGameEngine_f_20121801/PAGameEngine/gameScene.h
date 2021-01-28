#pragma once

#include "scene.h"

class GameScene : public Scene
{
	Composite* obstacles;
	Composite* collectables;
	Vector3D size;
	double mx, my;
	bool hasPlayer;
	bool cameraIsChange;

public:
	GameScene(bool hp = false) : hasPlayer(hp), Scene()
	{
		cameraIsChange = false;
		obstacles = new Composite();
		collectables = new Composite();
	}

	~GameScene()
	{
		delete obstacles;
		delete collectables;
	}

	GameScene* clone() {
		return new GameScene(*this);
	}

	vector<Solid*> getObstacleArray() { return this->obstacles->getSolids(); }
	Solid* getObstacles(int i) {return this->obstacles->getSolid(i);}
	void addObstacle(Solid* ps) { this->obstacles->add(ps); }

	vector<Solid*> getCollectableArray() { return this->collectables->getSolids(); }
	Solid* getCollectables(int i) { return this->collectables->getSolid(i); }
	void addCollectable(Solid* ps) { this->collectables->add(ps); }

	void setCameraIsChange() { cameraIsChange = !cameraIsChange; }
	bool getHasPlayer() { return this->hasPlayer; }
	//inline void setSize(const Vector3D& sizeToSet) { this->size = sizeToSet; this->camera->setPos(Vector3D(size.getX() / 2, size.getY() / 2, size.getZ() * 2)); }
	void render();
	void update(const double& dt);
};