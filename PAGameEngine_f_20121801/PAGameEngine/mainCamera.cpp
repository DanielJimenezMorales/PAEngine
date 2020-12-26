#include "mainCamera.h"

void MainCamera::render() {
	glTranslated(-this->getPos().getX(), -this->getPos().getY(), -this->getPos().getZ());
}