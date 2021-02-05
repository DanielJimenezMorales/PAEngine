#pragma once
#include "sphere.h"

class Collectable : public Sphere
{
public:
	Collectable() : Sphere() {
	}
	~Collectable() {}

	Collectable* clone() {
		return new Collectable(*this);
	}
};