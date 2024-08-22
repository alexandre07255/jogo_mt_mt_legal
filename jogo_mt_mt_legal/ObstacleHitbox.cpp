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
	cooldown(0)
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
		obstacle->setSpawnedHitbox(0);
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


	if (cont < cooldown)
		cont++;
	else
	{
		cont = 0;
		hitList.clear();
	}
}

void ObstacleHitbox::hitSolution(Hittable* hit)
{
	if (hasAlreadyHit(hit)) { return; }

	hitList.push_back(hit);

	cont = 0;
	hit->dealDamage(damage);
	hit->setHorizontalVelocity(horLaunchStrength);
	hit->setVerticalVelocity(verLaunchStrength);
}
