#include "gameScene.h"

//CameraFPS* GameScene::getCamera()
//{
//	return this->camera;
//}
//
void GameScene::render()
{
	if (this->hasPlayer)
	{
		cout << "renderiza este" << endl;
		Player* myPlayer = static_cast<Player*>(getSolid(0));
		myPlayer->getPlayerCamera()->render();
	}
	else
	{
		//cout << "renderiza este" << endl;
		getCamera()->render();
	}
	//getCamera()->render();
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
		/*if (pos.getZ() > this->getSize().getZ()) {
			pos.setZ(this->getSize().getZ() - 0.01);
			ps->setPos(pos);
			Vector3D vel = ps->getVel();
			vel.setZ(-vel.getZ());
			ps->setVel(vel);
		}
		if (pos.getZ() < 0) {
			pos.setZ(0.01);
			ps->setPos(pos);
			Vector3D vel = ps->getVel();
			vel.setZ(-vel.getZ());
			ps->setVel(vel);
		}*/
	}
}