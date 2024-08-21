#pragma once
#include "Hitbox.h"
#include "Obstacle.h"

class ObstacleHitbox : public Hitbox
{
private:
	int launchStrength;
	int verKnockback;
	int horKnockback;
	int damage;
};

