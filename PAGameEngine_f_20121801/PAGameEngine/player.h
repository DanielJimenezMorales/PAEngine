#pragma once

#include "model_mesh_triangles.h"

class Player : public ModelMeshTriangles
{
	ModelMeshTriangles* playerMesh;
public:

	Player() : ModelMeshTriangles() {}
	//ModelMeshTriangles* getPlayerMesh() { return this->playerMesh; }
	void setPlayerMesh(ModelMeshTriangles* newMesh) { this->playerMesh = newMesh; }
};

