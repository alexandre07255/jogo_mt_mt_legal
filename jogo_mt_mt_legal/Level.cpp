#include "Level.h"
#include "graphics.h"
#include "MyDrawable.h"
#include "Player.h"
#include "inputManager.h"
#include "Collidable.h"
#include "CollisionManager.h"

Level* Level::active(NULL);

Level::Level(): drawables(), updatables()
{
}

Level::~Level() //TODO
{

}

void Level::setDrawables(EntityList* drawlist) {
	drawables = drawlist;
}

EntityList* Level::getDrawables() const
{
	return drawables;
}

void Level::setUpdatables(list<Updatable*>* updatelist) {
	updatables = updatelist;
}

list<Updatable*>* Level::getUpdatables() const
{
	return updatables;
}

void Level::draw(sf::RenderWindow* window) {
	drawables->start();
	int size = drawables->getSize();
	for (int i = 0; i < size; i++)
	{
		window->draw(*(drawables->getCurrent()));
		drawables->next();
	}
}

void Level::update()
{
	list<Updatable*>::iterator itCurrent = updatables->begin();
	if (updatables->size() > 1)
	{
		list<Updatable*>::iterator itNext = itCurrent++;
		while (itNext != updatables->end())
		{
			(*itCurrent)->movement();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->movement();
	}
	else
		(*itCurrent)->movement();
}

Level* Level::getActive()
{
	return active;
}

void Level::setActive(Level* pL) //Usar em algum outro lugar (tipo gerenciador/pilha de states)
{
	active = pL;
}

void Level::addUpdatable(Updatable* pU)
{
	updatables->push_back(pU);
}
