#pragma once
#include "Entity.h"

class Collidable
{
protected:
	float friction;
public:
	Collidable();
	
	virtual sf::FloatRect getBounds() = 0; //garante que nao seja usado, pois ainda precisa de um global bounds para funcionar nosso collision manager
};

