#pragma once
#include "sphere.h"

class Collectable : public Sphere
{
	//PROVISIONAL
public:
	int borrado = false;
	Collectable() : Sphere() {}
	virtual ~Collectable() {}

	Collectable* clone() {
		return new Collectable(*this);
	}
};