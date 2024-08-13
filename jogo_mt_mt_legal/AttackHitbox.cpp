#include "AttackHitbox.h"

AttackHitbox::AttackHitbox(const bool tar, Alive* own, Entity* boundTo, sf::Vector2f rel, const int dur, sf::Vector2f _size) :
	Hitbox(tar, own, boundTo, rel, dur, _size),
	knockback(-1),
	launchDirection(),
	damage(-1),
	hitList(),
	hasHit(0)
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

void AttackHitbox::setHitstun(const int stun)
{
	hitstun = stun;
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
	if ( (duration <= 0 && !hasHit) || (hitstun <= 0 && hasHit) )
	{
		Level* activeLevel = Level::getActive();
		list<Updatable*>* upList = activeLevel->getUpdatables();
		upList->remove(this);
		owner->setState(Alive::FREE);
		delete this;
		return;
	}

	if (boundedTo != NULL)
	{
		setPosition(boundedTo->getPosition());
		move(relativePosition);
	}
	CollisionManager* collisionInstance = CollisionManager::getInstance();
	collisionInstance->testHit(target, this);
	
	duration--;
}

void AttackHitbox::hitSolution(Alive* hit)
{
	if (hasAlreadyHit(hit)) { return; }

	hitList.push_back(hit);

	
}