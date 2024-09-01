#include "ObstacleHitbox.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include <iostream>
#include <list>
using namespace Managers;
using namespace std;
using namespace Entities::Obstacles;
using namespace Scenes;
using namespace Entities::Hitboxes;
using namespace Entities::Characters;



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
	list<Hittable*>::iterator it = hitList.begin();
	int size = hitList.size();
	for (int i = 0; i < size; i++)
	{
		if ((*it) == pA)
			return 1;
		it++;
	}
	return 0;
}

void ObstacleHitbox::execute()
{
	if (!obstacle->getIsActive())
	{
		Scene* activeScene = SceneManager::getInstance()->top();
		obstacle->setSpawnedHitbox(0);
		activeScene->removeEntity(this);
		delete this;
		return;
	}


	if (cont < cooldown)
		cont++;
	else
	{
		cont = 0;
		hitList.clear();
	}
}

void ObstacleHitbox::adjustToRelativePosition()
{
	move(relativePosition);
}

void ObstacleHitbox::hitSolution(Hittable* hit)
{
	if (hasAlreadyHit(hit)) { return; }

	hitList.push_back(hit);

	obstacle->statusEffect(hit);

	if (hit->getState() == Hittable::ATKCANCEL)
		hit->setState(Hittable::FREE);

	cont = 0;
	hit->dealDamage(damage);
	if (horLaunchStrength)
		hit->setHorizontalVelocity(horLaunchStrength);
	if (verLaunchStrength)
		hit->setVerticalVelocity(verLaunchStrength);
}
