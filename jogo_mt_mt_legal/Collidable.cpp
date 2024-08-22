#include "Collidable.h"

Collidable::Collidable():friction(0){}

int Collidable::getCollidableId() {
	return collidableId;
}