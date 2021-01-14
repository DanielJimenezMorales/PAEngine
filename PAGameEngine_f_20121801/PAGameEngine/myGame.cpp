#include "myGame.h"

void MyGame::clearScenes()
{
	vector<Scene*> newVector;
	setScenes(newVector);
}

void MyGame::render() {
	getActiveScene()->render();
}

void MyGame::update() {

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - getInitialMilliseconds().count()) - getLastUpdatedTime() > getUpdatePeriod())
	{
		getActiveScene()->update(getTimeIncrement());
		setLastUpdatedTime(currentTime.count() - getInitialMilliseconds().count());
	}

	//Colisiones
	Player* myPlayer = static_cast<Player*>(getScenes()[0]->getSolid(0));
	for (int i = 1; i < getScenes()[0]->getSolids().size() - 2; i++) //-2 porque la luz y el terreno siempre irán al final y no queremos comprobar colisiones con ellos
	{
		if (myPlayer->collisionDetectionAABB(static_cast<Obstacle*>(getScenes()[0]->getSolid(i))) == true)
		{
			myPlayer->setPos(Vector3D(getScenes()[0]->getSize().getX() / 2, 2, 0));
			cout << "reset" << endl;
		}
	}

	if (myPlayer->getPos().getZ() < -20 && getActiveScene() == getScenes()[0])
	{
		//cout << "has ganado" << endl;
		gameOver();
	}
}

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
			//getScenes().clear();
			this->clearScenes();
			init();
		}
		break;
	}
	getActiveScene()->processKeyPressed(key, x, y);
}

void MyGame::empezarJuego()
{
	if (getActiveScene() == getScenes()[1] && getScenes()[0] != nullptr)
	{
		//Cambiamos a la escena del juego
		setActiveScene(getScenes()[0]);

		//Comenzamos a mover al jugador
		Player* myPlayer = static_cast<Player*>(getScenes()[0]->getSolid(0));
		myPlayer->ModifySpeed(-1.0f);
	}
}

void MyGame::gameOver()
{
	if (getActiveScene() == getScenes()[0] && getScenes()[2] != nullptr)
	{
		setActiveScene(getScenes()[2]);

		Player* myPlayer = static_cast<Player*>(getScenes()[0]->getSolid(0));
		myPlayer->ModifySpeed(0.0f);
	}
}