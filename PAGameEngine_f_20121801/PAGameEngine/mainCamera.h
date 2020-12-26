#pragma once

#include "solid.h"

class MainCamera : public Solid
{
public:
	MainCamera(Vector3D p = Vector3D(0, 0, 0)) :Solid()
	{
		setPos(p);
	}
	void render();
};