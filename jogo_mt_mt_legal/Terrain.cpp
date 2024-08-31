#include "Terrain.h"
#include "LevelSave.h"
using namespace Entities;


Terrain::Terrain(float frict) :Entity(), Collidable() {
	collidableId = getId();
	friction = frict;

	setFillColor(sf::Color::Transparent);
}

Terrain::~Terrain()
{

}

void Terrain::execute() { }

sf::FloatRect Terrain::getBounds() {
	return getGlobalBounds();
}

void Terrain::collisionSolution(Entity* pE) {	
	pE->setFriction(friction);
}

void Terrain::save(LevelSave* save) { }