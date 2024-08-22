#include "Scene.h"

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
	ListIterator<MyDrawable> itCurrent = drawables->begin();
	if (drawables->size() > 0)
	{
		ListIterator<MyDrawable> itNext = itCurrent;
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
	ListIterator<Updatable> itCurrent = updatables->begin();
	if (updatables->size() > 1)
	{
		ListIterator<Updatable> itNext = itCurrent;
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