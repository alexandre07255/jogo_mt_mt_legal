#include "Terrain.h"
using namespace Entities;


Terrain::Terrain(float frict) :Entity(), Collidable() {
	collidableId = getId();
	friction = frict;
}

void Terrain::execute() { }

sf::FloatRect Terrain::getBounds() {
	return getGlobalBounds();
}

void Terrain::collisionSolution(Entity* pE) {	
	pE->setFriction(friction);
}