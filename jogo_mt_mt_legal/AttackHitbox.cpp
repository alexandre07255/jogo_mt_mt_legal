#include "AttackHitbox.h"
#include "SceneManager.h"
#include <iostream>
using namespace std;

AttackHitbox::AttackHitbox() :
	Hitbox(),
	horKnockback(-1),
	verKnockback(-1),
	damage(-1),
	hitList(),
	hasHit(0),
	hitstun(0)
{
	hitList.clear();
}

void AttackHitbox::setHorKnockback(const int horKnock)
{
	horKnockback = horKnock;
}

void AttackHitbox::setVerKnockback(const int verKnock)
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
	if ( (duration <= 0 && !hasHit) || (hasHit && ( hitstun <= 0 || owner->getState() != Alive::ATKCANCEL ) ) )
	{
		Scene* activeScene = SceneManager::getInstance()->top();
		list<Updatable*>* upList = activeScene->getUpdatables();
		upList->remove(this);
		list<MyDrawable*>* drawList = activeScene->getDrawables();
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
	duration--;
}

void AttackHitbox::hitSolution(Alive* hit)
{
	if (hasAlreadyHit(hit)) { return; }

	hitList.push_back(hit);

	if (!hasHit)
	{
		hasHit = 1;
		owner->setState(Alive::ATKCANCEL);
		owner->setStun(hitstun);
	}

	hit->setState(Alive::HITSTUN);
	hit->setStun(hitstun);
	hit->dealDamage(damage);
	hit->setHorizontalVelocity(horKnockback);
	hit->setVerticalVelocity(verKnockback);
}