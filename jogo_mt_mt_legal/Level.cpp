#include "Level.h"
#include "graphics.h"
#include "MyDrawable.h"
#include "Player.h"
#include "inputManager.h"
#include "Collidable.h"
#include "CollisionManager.h"

Level::Level(): drawables(), updatables()
{
}

void Level::setDrawables(EntityList* drawlist) {
	drawables = drawlist;
}

void Level::setUpdatables(list<Updatable*>* updatelist) {
	updatables = updatelist;
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