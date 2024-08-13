#pragma once
#include "Hitbox.h"
#include "CollisionManager.h"
#include <list>
#include "Level.h"

class AttackHitbox : public Hitbox
{
private:
	int knockback;
	sf::Vector2f launchDirection;
	int damage;
	int hitstun;
	list<Alive*> hitList;
	bool hasHit;
	const bool hasAlreadyHit(Alive* pA);
public:
	AttackHitbox(const bool tar, Alive* own, Entity* boundTo,
		         sf::Vector2f rel, const int dur, sf::Vector2f _size);
	void setKnockback(const int knock);
	void setLaunchDirection(sf::Vector2f launch);
	void setDamage(const int dmg);
	void setHitstun(const int stun);
	void movement();
	void hitSolution(Alive* hit);
};

