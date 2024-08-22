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
	bool isPermanent;
	int cooldown;
	bool onCooldown;
	Obstacle* obstacle;
	const bool hasAlreadyHit(Hittable* pA);
public:
	ObstacleHitbox(Obstacle* obs);
	~ObstacleHitbox();
	void setVerLaunchStrength(const float ver);
	void setHorLaunchStrength(const float hor);
	void setDamage(const int dmg);
	void setCooldown(const int cd);
	void setIsPermanent(const bool perm);
	void movement();
	void hitSolution(Hittable* hit);
};

