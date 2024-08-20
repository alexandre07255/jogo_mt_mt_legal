#pragma once
#include "Obstacle.h"
#include "Collidable.h"

class Platform:public Obstacle, public Collidable
{
public:
	sf::FloatRect getBounds();
};

