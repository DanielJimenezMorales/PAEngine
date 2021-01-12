#include "myGame.h"

void MyGame::processKeyPressed(unsigned char key, int x, int y) {
	switch (key)
	{
	case '3':
		if (getScenes()[2] != nullptr)
		{
			setActiveScene(getScenes()[2]);
		}
		break;
	case 'a':
		if (getActiveScene() != nullptr)
		{
			//this->scenes[0]->getSolid(0)->setVel(Vector3D(-1, 0, 0));
			Player* myPlayer = static_cast<Player*>(getScenes()[0]->getSolid(0));
			myPlayer->SideMovement(-1.0f);
		}
		break;
	case 'd':
		if (getActiveScene() != nullptr)
		{
			//this->scenes[0]->getSolid(0)->setVel(Vector3D(1, 0, 0));
			Player* myPlayer = static_cast<Player*>(getScenes()[0]->getSolid(0));
			myPlayer->SideMovement(1.0f);
		}
		break;
	case 'x':
		if (getActiveScene() == getScenes()[1])
		{
			empezarJuego();
		}
		else if (getActiveScene() == getScenes()[2])
		{
			getScenes().clear();
			init();
		}
		break;
	}
	getActiveScene()->processKeyPressed(key, x, y);
}