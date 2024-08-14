#pragma once
#include "Hitbox.h"
#include "CollisionManager.h"
#include <list>
#include "Level.h"

class AttackHitbox : public Hitbox
{
private:
	int verKnockback;
	int horKnockback;
	int damage;
	int hitstun;
	list<Alive*> hitList;
	bool hasHit;
	const bool hasAlreadyHit(Alive* pA);
public:
	AttackHitbox();
	void setHorKnockback(const int horKnock);
	void setVerKnockback(const int verKnock);
	void setDamage(const int dmg);
	void setHitstun(const int stun);
	void movement();
	void hitSolution(Alive* hit);
};

