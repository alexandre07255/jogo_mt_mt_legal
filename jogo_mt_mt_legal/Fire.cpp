#include "Fire.h"
#include "CollisionManager.h"
#include "LevelSave.h"
#include "ObstacleHitbox.h"
using namespace Entities::Hitboxes;
using namespace Entities::Characters;
using namespace Managers;
using namespace Entities::Obstacles;


Fire::Fire() :
	Obstacle(),
	lingeringTime(12)
{

}

void Fire::statusEffect(Hittable* hit)
{
	hit->setFireRemaining(lingeringTime);
}

void Fire::setLingeringTime(const int time)
{
	lingeringTime = time;
}

void Fire::execute()
{
	if (!spawnedHitbox)
	{
		CollisionManager* cInstance = CollisionManager::getInstance();
		float floor = cInstance->nearestCollidable(this, 900.f);
		setPosition(left(), floor - getSize().y);
		activate();
		spawnedHitbox = 1;
	}
}

void Fire::activate()
{
	isActive = 1;
	ObstacleHitbox* hitbox = new ObstacleHitbox(this);
	hitbox->setTarget(1);
	hitbox->setCooldown(30);
	hitbox->setSize(getSize());
	hitbox->setHorLaunchStrength(0.f);
	hitbox->setVerLaunchStrength(0.f);
	hitbox->setDamage(1);
	hitbox->setRelativePosition(sf::Vector2f(0.f, 0.f));
	hitbox->setPosition(getPosition());
	hitbox->ajustToRelativePosition();
}

void Fire::deactivate()
{
	isActive = 0;
}

void Fire::toObstacle()
{
	if (isActive)
	{
		CollisionManager* collisionInstance = CollisionManager::getInstance();
		collisionInstance->testHit(1, hitbox);
	}
	else
	{
		hitbox = NULL;
	}
}

void Fire::save(LevelSave* save) {
	save->addFire(this);
}