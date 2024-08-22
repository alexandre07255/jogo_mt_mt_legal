#include "Terrain.h"

Terrain::Terrain() :MyDrawable(), Collidable() {
	collidableId = getId();
}

sf::FloatRect Terrain::getBounds() {
	return getGlobalBounds();
}