#include "game.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

inline double getRand(double min, double max) {
	static const int PRECISION = 10000;
	double n = max - min;
	int ir = rand() % PRECISION;
	double r = min + (double)ir / PRECISION * n;
	return r;
}

inline double getRand(double max = 1) { return getRand(0, max); }

vector<string> split0(string line) {
	string word;
	vector<string> words;
	istringstream ss(line);
	while (cin >> word) {
		words.push_back(word);
	}
	return words;
}

vector<string> split(string line, char delim = ' ') {
	string word;
	vector<string> words;
	istringstream ss(line);
	while (getline(ss, word, delim)) {
		words.push_back(word);
	}
	return words;
}

class ExceptionGame :public exception {
public:
	virtual const char* what() const throw() {
		return "Customized ExceptionGame error";
	}
};

void Game::init() {
	srand(11);

	Scene* mainScene = new(nothrow) Scene();
	

	Light* light = new Light(Vector3D(1, 0, 0));
	mainScene->add(light);

	Text* pHola = new Text("Hola PA");
	pHola->setVel(Vector3D(0, 0.5, 0.5));
	mainScene->add(pHola);

	

	this->scenes.push_back(mainScene);
	

	//OUR LEVEL
	Scene* level1 = new(nothrow) Scene();
	//Camara
	level1->setSize(Vector3D(0, 5, 0));
	level1->setRot(Vector3D(20, 0, 0));

	Light* light2 = new Light(Vector3D(1, 0, 0));
	level1->add(light2);
	/*
	LoaderOBJ::setBasePath(".\\3dModels");
	LoaderOBJ lobj(6);
	lobj.loadModel("Bolt.obj");
	Player* player = new Player();
	player->setPlayerMesh(&(lobj.getModelMeshTriangles()));
	player->setPos(Vector3D(0, 2, -10));
	level1->add(player);
	*/

	Cube* floor1 = new Cube();
	floor1->setPos(Vector3D(5, 2, 20));
	floor1->setSize(0.5);
	floor1->setColor(Vector3D(1, 1, 0.3));

	level1->add(floor1);

	Cuboid* floor = new Cuboid();
	floor->setPos(Vector3D(5, 0, 5));
	floor->setColor(Vector3D(0.1, 0.5, 0.3));
	floor->setHeight(0.1);
	floor->setLength(10);
	floor->setWidth(100);
	//level1->add(floor);

	this->scenes.push_back(level1);
	this->activeScene = level1;
}

void Game::init(const string& file)
{
	LoaderOBJ::setBasePath(".\\3dModels");

	ifstream inputFileStream(file);
	json jsonInfo;
	if (inputFileStream.is_open() && inputFileStream.good())
	{
		inputFileStream >> jsonInfo;

		cout << jsonInfo << endl;

		for (int idx = 0; idx < jsonInfo.at("scenes").size(); idx++)
		{
			json currentScene = jsonInfo.at("scenes").at(idx);

			Scene* scene = new Scene();
			scene->setSize(Vector3D(currentScene.at("size").at("x"), currentScene.at("size").at("y"), currentScene.at("size").at("z")));
			
			for (int idx2 = 0; idx2 < currentScene.at("objects").size(); idx2++)
			{
				json currentObject = currentScene.at("objects").at(idx2);
				if (currentObject.at("type") == "light")
				{
					Light* light = new Light();
					light->setPos(Vector3D(currentObject.at("position").at("x"), currentObject.at("position").at("y"), currentObject.at("position").at("z")));
					scene->add(light);
				}
				else if (currentObject.at("type") == "cube")
				{
					Cube* cube = new Cube();
					cube->setPos(Vector3D(currentObject.at("position").at("x"), currentObject.at("position").at("y"), currentObject.at("position").at("z")));
					cube->setVel(Vector3D(currentObject.at("speed").at("x"), currentObject.at("speed").at("y"), currentObject.at("speed").at("z")));
					cube->setColor(Vector3D(currentObject.at("color").at("x"), currentObject.at("color").at("y"), currentObject.at("color").at("z")));
					cube->setRot(Vector3D(currentObject.at("rotation").at("x"), currentObject.at("rotation").at("y"), currentObject.at("rotation").at("z")));
					cube->setRotVel(Vector3D(currentObject.at("rotationSpeed").at("x"), currentObject.at("rotationSpeed").at("y"), currentObject.at("rotationSpeed").at("z")));
					cube->setSize(currentObject.at("size"));
					scene->add(cube);
				}
				else if (currentObject.at("type") == "sphere")
				{
					Sphere* sphere = new Sphere();
					sphere->setPos(Vector3D(currentObject.at("position").at("x"), currentObject.at("position").at("y"), currentObject.at("position").at("z")));
					sphere->setVel(Vector3D(currentObject.at("speed").at("x"), currentObject.at("speed").at("y"), currentObject.at("speed").at("z")));
					sphere->setColor(Vector3D(currentObject.at("color").at("x"), currentObject.at("color").at("y"), currentObject.at("color").at("z")));
					sphere->setSize(currentObject.at("size"));
					scene->add(sphere);
				}
				else if (currentObject.at("type") == "model")
				{
					LoaderOBJ lobj(currentObject.at("scale"));
					ModelMeshTriangles* model = new ModelMeshTriangles();
					lobj.loadModel(currentObject.at("file"));
					*model = lobj.getModelMeshTriangles();
					model->setPos(Vector3D(currentObject.at("position").at("x"), currentObject.at("position").at("y"), currentObject.at("position").at("z")));
					model->setVel(Vector3D(currentObject.at("speed").at("x"), currentObject.at("speed").at("y"), currentObject.at("speed").at("z")));
					model->setColor(Vector3D(currentObject.at("color").at("x"), currentObject.at("color").at("y"), currentObject.at("color").at("z")));
					model->setRot(Vector3D(currentObject.at("rotation").at("x"), currentObject.at("rotation").at("y"), currentObject.at("rotation").at("z")));
					model->setRotVel(Vector3D(currentObject.at("rotationSpeed").at("x"), currentObject.at("rotationSpeed").at("y"), currentObject.at("rotationSpeed").at("z")));
					scene->add(model);
				}
			}
			this->scenes.push_back(scene);
		}
		this->activeScene = this->scenes[0];
	}
	else
	{
		cout << "Error leyendo archivo: " << file << endl;
	}
}

void Game::render() {
	this->activeScene->render();
}

void Game::update() {

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->activeScene->update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

}

void Game::processKeyPressed(unsigned char key, int x, int y) {
	switch (key)
	{
	case '1':
		if (this->scenes[0] != nullptr)
		{
			this->activeScene = this->scenes[0];
		}
		break;
	case '2':
		if (this->scenes[1] != nullptr)
		{
			this->activeScene = this->scenes[1];
		}
		break;
	}
	this->activeScene->processKeyPressed(key, x, y);
}

void Game::processMouseMovement(int x, int y) {
	this->activeScene->processMouseMovement(x, y);
}

void Game::processMouseClick(int button, int state, int x, int y) {
	this->activeScene->processMouseClick(button, state, x, y);
}

