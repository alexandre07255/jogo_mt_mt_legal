#include "Fire.h"
#include "CollisionManager.h"
#include "ObstacleHitbox.h"

Fire::Fire() :
	firstStep(1),
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

void Fire::movement()
{
	if (firstStep)
	{
		CollisionManager* cInstance = CollisionManager::getInstance();
		float floor = cInstance->nearestCollidable(this, 900.f);
		setPosition(left(), floor - getSize().y);
		activate();
		firstStep = 0;
	}
}

void Fire::activate()
{
	isActive = 1;
	ObstacleHitbox* hitbox = new ObstacleHitbox(this);
	hitbox->setTarget(1);
	hitbox->setBoundedTo(this);
	hitbox->setCooldown(30);
	hitbox->setSize(getSize());
	hitbox->setHorLaunchStrength(0.f);
	hitbox->setVerLaunchStrength(0.f);
	hitbox->setDamage(1);
	hitbox->setRelativePosition(sf::Vector2f(0.f, 0.f));
}

void Fire::deactivate()
{
	isActive = 0;
}