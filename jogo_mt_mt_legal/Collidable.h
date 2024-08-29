#pragma once
#include "Entity.h"

class Collidable
{
protected:
	float friction;
	int collidableId;
public:
	Collidable();
	int getCollidableId();
	virtual sf::FloatRect getBounds() = 0;//garante que nao seja usado, pois ainda precisa de um global bounds para funcionar nosso collision manager
	virtual void collisionSolution(Entities::Entity* pE) = 0;
};

