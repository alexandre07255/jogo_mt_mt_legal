#pragma once
#include "Hitbox.h"
#include "Obstacle.h"
#include "List.h"

class ObstacleHitbox : public Hitbox
{
private:
	float verLaunchStrength;
	float horLaunchStrength;
	int damage;
	List<Hittable> hitList;

};

