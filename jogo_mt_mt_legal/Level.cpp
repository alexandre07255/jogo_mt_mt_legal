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
	
}