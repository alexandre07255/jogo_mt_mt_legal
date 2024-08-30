#include "Collidable.h"

Collidable::Collidable():friction(0){}

Collidable::~Collidable()
{
	friction = -1;
}

int Collidable::getCollidableId() {
	return collidableId;
}