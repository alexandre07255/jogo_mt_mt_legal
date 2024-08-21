#include "Terrain.h"

Terrain::Terrain() :MyDrawable(), Collidable() {
}

sf::FloatRect Terrain::getBounds() {
	return getGlobalBounds();
}