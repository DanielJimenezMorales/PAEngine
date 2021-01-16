#include "gameScene.h"

void GameScene::render()
{
	Player* myPlayer = static_cast<Player*>(getSolid(0));
	if (this->hasPlayer && cameraIsChange == false)
	{
		Player* myPlayer = static_cast<Player*>(getSolid(0));
		myPlayer->getPlayerCamera()->render();
	}
	else
	{
		getCamera()->render();
	}

	Composite::render();
}

void GameScene::update(const double& dt) {
	for (Solid* ps : getSolids()) {
		ps->update(dt);
		Vector3D pos = ps->getPos();
		
		if (pos.getX() > this->getSize().getX()) {
			pos.setX(this->getSize().getX() - 0.01);
			ps->setPos(pos);
			Vector3D vel = ps->getVel();
			vel.setX(-vel.getX());
			ps->setVel(vel);
		}
		if (pos.getX() < 0) {
			pos.setX(0.01);
			ps->setPos(pos);
			Vector3D vel = ps->getVel();
			vel.setX(-vel.getX());
			ps->setVel(vel);
		}
	}
}