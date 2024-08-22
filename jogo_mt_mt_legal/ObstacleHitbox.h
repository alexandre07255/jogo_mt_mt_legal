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
	int cont;
	int cooldown;
	Obstacle* obstacle;
	const bool hasAlreadyHit(Hittable* pA);
public:
	ObstacleHitbox(Obstacle* obs);
	~ObstacleHitbox();
	void setVerLaunchStrength(const float ver);
	void setHorLaunchStrength(const float hor);
	void setDamage(const int dmg);
	void setCooldown(const int cd);
	void movement();
	void hitSolution(Hittable* hit);
};

