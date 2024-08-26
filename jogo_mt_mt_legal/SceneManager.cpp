#include "SceneManager.h"
#include <iostream>
using namespace std;

SceneManager* SceneManager::instance(NULL);

SceneManager::SceneManager():
	scenes(),
	window(NULL)
{

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
	return scenes.pop();
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
	sceneActive->update();
	window->clear(sf::Color::Black);
	if (sceneActive == scenes.top())
		sceneActive->draw(window);
	window->display();
}

int SceneManager::size() {
	return scenes.size();
}