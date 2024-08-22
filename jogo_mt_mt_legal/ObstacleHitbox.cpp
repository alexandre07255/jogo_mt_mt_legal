#include "ObstacleHitbox.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include <iostream>
using namespace std;

ObstacleHitbox::ObstacleHitbox(Obstacle* obs):
	Hitbox(),
	obstacle(obs),
	cont(0),
	verLaunchStrength(-1),
	horLaunchStrength(-1),
	damage(0),
	hitList(),
	cooldown(0),
	isPermanent(0),
	onCooldown(0)
{

}

ObstacleHitbox::~ObstacleHitbox()
{
	obstacle = NULL;
}

void ObstacleHitbox::setVerLaunchStrength(const float ver)
{
	verLaunchStrength = ver;
}

void ObstacleHitbox::setHorLaunchStrength(const float hor)
{
	horLaunchStrength = hor;
}
void ObstacleHitbox::setDamage(const int dmg)
{
	damage = dmg;
}

void ObstacleHitbox::setCooldown(const int cd)
{
	cooldown = cd;
}

void ObstacleHitbox::setIsPermanent(const bool perm)
{
	isPermanent = perm;
}

const bool ObstacleHitbox::hasAlreadyHit(Hittable* pA)
{
	ListIterator<Hittable> it = hitList.begin();
	int size = hitList.size();
	for (int i = 0; i < size; i++)
	{
		if ((*it) == pA)
			return 1;
		it++;
	}
	return 0;
}

void ObstacleHitbox::movement()
{
	if (!obstacle->getIsActive())
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

	if (!onCooldown)
	{
		if (cont < duration)
			collisionInstance->testHit(target, this);
		else
		{
			onCooldown = 1;
			cont = -1;
		}
	}
	else
	{
		if (cont >= cooldown)
		{
			onCooldown = 0;
			cont = -1;
		}
	}
	cont++;
}

void ObstacleHitbox::hitSolution(Hittable* hit)
{
	if (hasAlreadyHit(hit)) { return; }

	hitList.push_back(hit);

	hit->dealDamage(damage);
	hit->setHorizontalVelocity(horLaunchStrength);
	hit->setVerticalVelocity(verLaunchStrength);
}
