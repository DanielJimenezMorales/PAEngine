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

bool Player::collisionDetectionAABB(Cube* obstacle)
{
	//https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection
	if (this->getMinPoint().getX() < obstacle->getPos().getX() + 0.5 &&
		this->getMinPoint().getZ() < obstacle->getPos().getZ() + 0.5 &&
		this->getMaxPoint().getX() > obstacle->getPos().getX() - 0.5 &&
		this->getMaxPoint().getZ() > obstacle->getPos().getZ() - 0.5)
	{
		cout << "colision" << endl;
		return true;
	}
	else {
		return false;
	}
}