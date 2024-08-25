#include "Spike.h"
#include "CollisionManager.h"
#include "ObstacleHitbox.h"

Spike::Spike():
	firstStep(1),
	Obstacle()
{

}

void Spike::movement()
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

void Spike::activate()
{
	isActive = 1;
	ObstacleHitbox* hitbox = new ObstacleHitbox(this);
	hitbox->setTarget(1);
	hitbox->setBoundedTo(this);
	hitbox->setCooldown(40);
	hitbox->setSize(getSize());
	hitbox->setHorLaunchStrength(0.f);
	hitbox->setVerLaunchStrength(-40.f);
	hitbox->setDamage(3);
	hitbox->setRelativePosition(sf::Vector2f(0.f, 0.f));
}

void Spike::deactivate()
{
	isActive = 0;
}