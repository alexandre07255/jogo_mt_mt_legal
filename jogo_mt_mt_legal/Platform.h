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
	float mass;
	int time;
	float defaultY;
	float deformation;
	bool onTop;
public:
	Platform(float xPosition, float yPosition, float xSize, float ySize);
	sf::FloatRect getBounds();
	void movement();
	Support* getSupport();
	void collisionSolution(Entity* pE);
};

float HarmonicMovement(float range, float mass, float elasticity, float damping, float time);

