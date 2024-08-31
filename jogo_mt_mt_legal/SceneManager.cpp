#include "SceneManager.h"
#include <iostream>
using namespace std;
using namespace Managers;
using namespace Scenes;

SceneManager* SceneManager::instance(NULL);

SceneManager::SceneManager():
	scenes(),
	window(NULL)
{

}

SceneManager::~SceneManager()
{
	while (scenes.size() > 0)
	{
		Scene* sce = scenes.top();
		scenes.pop();
		if (sce)
			delete sce;
	}
}

SceneManager* SceneManager::getInstance()
{
	if (instance == NULL)
		instance = new SceneManager;
	return instance;
}

void SceneManager::setWindow(sf::RenderWindow* pW)
{
	window = pW;
}

void SceneManager::push(Scene* pS)
{
	scenes.push(pS);
}

void SceneManager::pop()
{
	if (scenes.size() == 0)
		return;
	Scene* del = scenes.top();
	scenes.pop();
	delete del;
}

Scene* SceneManager::top() const
{
	if (scenes.size() == 0)
		return NULL;
	return scenes.top();
}

void SceneManager::step()
{
	if (window == NULL)
	{
		cout << "No window set for SceneManager." << endl;
		return;
	}
	Scene* sceneActive = scenes.top();
	window->clear(sf::Color::Black);
	sceneActive->execute();
	if (scenes.top() == sceneActive)
		sceneActive->draw();
	window->display();
}

int SceneManager::size() {
	return scenes.size();
}

