#include "player.h"

void Player::ModifySpeed(float newSpeedMultiplier)
{
	this->speedMultiplier = newSpeedMultiplier;
	this->setVel(Vector3D(this->getVel().getX(), 0, 1 * speedMultiplier));
	//this->update(speedMultiplier);
}

void Player::SideMovement(float newXSpeed)
{
	this->setVel(Vector3D(newXSpeed, 0, this->getVel().getZ()));
}