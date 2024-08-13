#include "AttackHitbox.h"

AttackHitbox::AttackHitbox(const bool tar, Alive* own, Entity* boundTo, sf::Vector2f rel, const int dur, sf::Vector2f _size) :
	Hitbox(tar, own, boundTo, rel, dur, _size),
	knockback(-1),
	launchDirection(),
	damage(-1),
	hitList()
{
	hitList.clear();
}

void AttackHitbox::setKnockback(const int knock)
{
	knockback = knock;
}

void AttackHitbox::setLaunchDirection(sf::Vector2f launch)
{
	launchDirection = launch;
}

void AttackHitbox::setDamage(const int dmg)
{
	damage = dmg;
}

const bool AttackHitbox::hasAlreadyHit(Alive* pA)
{
	list<Alive*>::iterator it = hitList.begin();
	int size = hitList.size();
	for (int i = 0; i < size; i++)
	{
		if ((*it) == pA)
			return 1;
		it++;
	}
	return 0;
}

void AttackHitbox::movement()
{
	if (boundedTo != NULL)
	{
		setPosition(boundedTo->getPosition());
		move(relativePosition);
	}
	CollisionManager* collisionInstance = CollisionManager::getInstance();
	collisionInstance->testHit(target, this);
}

void AttackHitbox::hitSolution(Alive* hit)
{
	if (hasAlreadyHit(hit)) { return; }

	
}