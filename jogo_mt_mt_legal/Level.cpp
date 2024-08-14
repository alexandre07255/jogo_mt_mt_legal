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
	list<Updatable*>::iterator it = updatables->begin();
	int size = updatables->size();
	for (int i = 0; i < size; i++)
	{
		(*it)->movement();
		it++;
	}
}

Level* Level::getActive()
{
	return active;
}

void Level::setActive(Level* pL) //Usar em algum outro lugar (tipo gerenciador/pilha de states)
{
	active = pL;
}

void Level::addDrawable(Entity* pD) {
	drawables->pushBack(pD);
}