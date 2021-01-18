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
			myPlayer->getContador()->getDamaged();
			if (myPlayer->getContador()->getLifesLeft() == 0)
			{
				gameOver();
			}

			cout << myPlayer->getContador()->getLifesLeft() << endl;
		}
	}

	if (myPlayer->getPos().getZ() < -100 && getActiveScene() == getScenes()[0])
	{
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
			this->clearScenes();
			init();
		}
		break;
	case '1':
		GameScene * currentGameScene = static_cast<GameScene*>(getActiveScene());
		if (currentGameScene->getHasPlayer())
		{
			currentGameScene->setCameraIsChange();
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
		ranking->sortRanking();
		ranking->escrituraEnRanking("ranking.txt");

		//TEXTO RANKING
		string a = ranking->getRow(0)->getPlayerName();
		string b = to_string(ranking->getRankingPoints(0));
		string rankingInfo = "1 " + a + " " + b;
		Text* primero = new Text(rankingInfo);
		primero->setPos(Vector3D(2.5, 8, 0));
		getScenes()[2]->add(primero);

		a = ranking->getRow(1)->getPlayerName();
		b = to_string(ranking->getRankingPoints(1));
		rankingInfo = "2 " + a + " " + b;
		Text* segundo = new Text(rankingInfo);
		segundo->setPos(Vector3D(2.5, 7, 0));
		getScenes()[2]->add(segundo);

		a = ranking->getRow(2)->getPlayerName();
		b = to_string(ranking->getRankingPoints(2));
		rankingInfo = "3 " + a + " " + b;
		Text* tercero = new Text(rankingInfo);
		tercero->setPos(Vector3D(2.5, 6, 0));
		getScenes()[2]->add(tercero);

		a = ranking->getRow(3)->getPlayerName();
		b = to_string(ranking->getRankingPoints(3));
		rankingInfo = "4 " + a + " " + b;
		Text* cuarto = new Text(rankingInfo);
		cuarto->setPos(Vector3D(2.5, 5, 0));
		getScenes()[2]->add(cuarto);

		a = ranking->getRow(4)->getPlayerName();
		b = to_string(ranking->getRankingPoints(4));
		rankingInfo = "5 " + a + " " + b;
		Text* quinto = new Text(rankingInfo);
		quinto->setPos(Vector3D(2.5, 4, 0));
		getScenes()[2]->add(quinto);

		setActiveScene(getScenes()[2]);

		Player* myPlayer = static_cast<Player*>(getScenes()[0]->getSolid(0));
		myPlayer->ModifySpeed(0.0f);
		myPlayer->SideMovement(0.0f);
	}
}