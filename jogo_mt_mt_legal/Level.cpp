#include "Level.h"
#include "graphics.h"
#include "MyDrawable.h"
#include "Player.h"
#include "inputManager.h"
#include "Collidable.h"
#include "CollisionManager.h"

Level::Level() {
}

void Level::setDrawables(EntityList* drawlist) {
	drawables = drawlist;
}

void Level::setUpdatables(EntityList* updatelist) {
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
	updatables->start();
	Entity* current;
	int size = updatables->getSize();
	for (int i = 0; i < size; i++)
	{
		current = updatables->getCurrent();
		current->movement();
		updatables->next();
	}
}