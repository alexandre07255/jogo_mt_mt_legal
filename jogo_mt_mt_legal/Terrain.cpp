#include "Terrain.h"
using namespace Entities;


Terrain::Terrain(float frict) :MyDrawable(), Collidable() {
	collidableId = getId();
	friction = frict;
}

sf::FloatRect Terrain::getBounds() {
	return getGlobalBounds();
}

void Terrain::collisionSolution(Entity* pE) {	
	pE->setFriction(friction);
}