#include "Scene.h"

Scene::Scene(): drawables(NULL), updatables(NULL) {
	drawables = new list<MyDrawable*>;
	updatables = new list<Updatable*>;
}

void Scene::setDrawables(list<MyDrawable*>* drawlist) {
	drawables = drawlist;
}

list<MyDrawable*>* Scene::getDrawables() const
{
	return drawables;
}

void Scene::setUpdatables(list<Updatable*>* updatelist) {
	updatables = updatelist;
}

list<Updatable*>* Scene::getUpdatables() const
{
	return updatables;
}

void Scene::draw(sf::RenderWindow* window) {
	list<MyDrawable*>::iterator itCurrent = drawables->begin();
	if (drawables->size() > 0)
	{
		list<MyDrawable*>::iterator itNext = itCurrent;
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
	list<Updatable*>::iterator itCurrent = updatables->begin();
	if (updatables->size() > 1)
	{
		list<Updatable*>::iterator itNext = itCurrent;
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