#include "player.h"

void Player::ModifySpeed(float newSpeedMultiplier)
{
	this->speedMultiplier = newSpeedMultiplier;
	this->setVel(Vector3D(this->getVel().getX(), 0, speedMultiplier));
}

void Player::SideMovement(float newXSpeed)
{
	this->setVel(Vector3D(newXSpeed, 0, this->getVel().getZ()));
}

bool Player::collisionDetectionAABB(Solid* otherObject)
{
	//https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection
	if (this->getMinPoint().getX() < otherObject->getPos().getX() + otherObject->getSize() / 2 &&
		this->getMinPoint().getZ() < otherObject->getPos().getZ() + otherObject->getSize() / 2 &&
		this->getMaxPoint().getX() > otherObject->getPos().getX() - otherObject->getSize() / 2 &&
		this->getMaxPoint().getZ() > otherObject->getPos().getZ() - otherObject->getSize() / 2)
	{
		return true;
	}
	else {
		return false;
	}
}

void Player::update(double dt)
{
	playerCamera->setPos(Vector3D(playerCamera->getPos().getX(), playerCamera->getPos().getY(), this->getPos().getZ() + 10));
	Solid::update(dt);
}