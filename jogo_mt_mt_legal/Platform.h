#pragma once
#include "Obstacle.h"
#include "Collidable.h"

class Support;

class Platform:public Obstacle, public Collidable
{
private:
	Support* support;
	bool firstStep;
	const float minimalHeight;
public:
	Platform(float xPosition, float yPosition, float xSize, float ySize);
	sf::FloatRect getBounds();
	void movement();
	Support* getSupport();
};

