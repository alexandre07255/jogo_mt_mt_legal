#pragma once
#include "Hitbox.h"
#include <set>

class AttackHitbox : public Hitbox
{
private:
	int knockback;
	sf::Vector2f launchDirection;
	int damage;
	set<Alive*> hitList;
public:
	AttackHitbox(const bool tar, Alive* own, Entity* boundTo,
		         sf::Vector2f rel, const int dur, sf::Vector2f _size);
	void setKnockback(const int knock);
	void setLaunchDirection(sf::Vector2f launch);
	void setDamage(const int dmg);
	void hitSolution(Alive* hit);
};

