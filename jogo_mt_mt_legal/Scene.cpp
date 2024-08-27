#include "Scene.h"
#include <iostream>
using namespace Scenes;

Scene::Scene(): drawables(NULL), updatables(NULL) {
	drawables = new List<MyDrawable>;
	updatables = new List<Updatable>;
}

void Scene::setDrawables(List<MyDrawable>* drawlist) {
	drawables = drawlist;
}

List<MyDrawable>* Scene::getDrawables() const
{
	return drawables;
}

void Scene::setUpdatables(List<Updatable>* updatelist) {
	updatables = updatelist;
}

List<Updatable>* Scene::getUpdatables() const
{
	return updatables;
}

void Scene::draw(sf::RenderWindow* window) {
	List<MyDrawable>::Iterator itCurrent = drawables->begin();
	if (drawables->size() > 0)
	{
		List<MyDrawable>::Iterator itNext = itCurrent;
		itNext++;
		while (itNext != drawables->end())
		{
			window->draw(*(*itCurrent));
			itCurrent = itNext;
			itNext++;
		}
		window->draw(*(*itCurrent));
	}
}

void Scene::update()
{
	List<Updatable>::Iterator itCurrent = updatables->begin();
	if (updatables->size() > 1)
	{
		List<Updatable>::Iterator itNext = itCurrent;
		itNext++;
		while (itNext != updatables->end())
		{
			(*itCurrent)->movement();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->movement();
	}
	else if (updatables->size() == 1)
		(*itCurrent)->movement();
}

void Scene::addUpdatable(Updatable* pU)
{
	updatables->push_back(pU);
}

void Scene::addDrawable(MyDrawable* pD) {
	drawables->push_back(pD);
}

void Scene::removeDrawable(MyDrawable* pD) {
	drawables->remove(pD);
}

void Scene::removeUpdatable(Updatable* pU) {
	updatables->remove(pU);
}