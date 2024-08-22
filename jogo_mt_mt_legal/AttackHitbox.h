#pragma once
#include "Hitbox.h"
#include "CollisionManager.h"
#include "List.h"
#include "Level.h"

class AttackHitbox : public Hitbox
{
private:
	float verKnockback;
	float horKnockback;
	int damage;
	int hitstun;
	List<Hittable> hitList;
	bool hasHit;
	const bool hasAlreadyHit(Hittable* pA);
public:
	AttackHitbox();
	void setHorKnockback(const float horKnock);
	void setVerKnockback(const float verKnock);
	void setDamage(const int dmg);
	void setHitstun(const int stun);
	void movement();
	void hitSolution(Hittable* hit);
};

