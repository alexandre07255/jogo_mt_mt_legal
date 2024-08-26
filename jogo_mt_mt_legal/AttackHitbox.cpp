#include "AttackHitbox.h"
#include "SceneManager.h"
#include <iostream>
using namespace std;

AttackHitbox::AttackHitbox() :
	Hitbox(),
	horKnockback(-1.0),
	verKnockback(-1.0),
	damage(-1),
	hitList(),
	hasHit(0),
	hitstun(0),
	isInfinite(0),
	doesATKCANCEL(1)
{
	hitList.clear();
}

void AttackHitbox::setHorKnockback(const float horKnock)
{
	horKnockback = horKnock;
}

void AttackHitbox::setVerKnockback(const float verKnock)
{
	verKnockback = verKnock;
}

void AttackHitbox::setDamage(const int dmg)
{
	damage = dmg;
}

void AttackHitbox::setHitstun(const int stun)
{
	hitstun = stun;
}

void AttackHitbox::setIsInfinite(const bool inf)
{
	isInfinite = inf;
}

void AttackHitbox::setDoesATKCANCEL(const bool dAC)
{
	doesATKCANCEL = dAC;
}

const bool AttackHitbox::getHasHit() const
{
	return hasHit;
}

const bool AttackHitbox::hasAlreadyHit(Hittable* pA)
{
	List<Hittable>::Iterator it = hitList.begin();
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
	if ( (duration <= 0 && !hasHit) || (hasHit && ( hitstun <= 0 || (doesATKCANCEL && owner->getState() != Hittable::ATKCANCEL) ) ) )
	{
		Scene* activeScene = SceneManager::getInstance()->top();
		List<Updatable>* upList = activeScene->getUpdatables();
		upList->remove(this);
		List<MyDrawable>* drawList = activeScene->getDrawables();
		drawList->remove(this);
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
	
	if (hasHit) { hitstun--; }
	if (!isInfinite)
		duration--;
}

void AttackHitbox::hitSolution(Hittable* hit)
{
	if (hasAlreadyHit(hit)) { return; }

	hitList.push_back(hit);

	if (!hasHit)
	{
		hasHit = 1;
		if (doesATKCANCEL)
		{
			owner->setState(Hittable::ATKCANCEL);
			owner->setStun(hitstun);
		}
	}

	hit->setState(Hittable::HITSTUN);
	hit->setStun(hitstun);
	hit->dealDamage(damage);
	if (hit->getHp() <= 0) {
		owner->setPoints(owner->getPoints() + hit->getPoints());
	}
	hit->setHorizontalVelocity(horKnockback);
	hit->setVerticalVelocity(verKnockback);
}