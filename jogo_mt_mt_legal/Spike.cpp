#include "Spike.h"
#include "CollisionManager.h"
#include "ObstacleHitbox.h"
using namespace Managers;
using namespace Entities::Hitboxes;
using namespace Entities::Obstacles;



Spike::Spike():
	firstStep(1),
	Obstacle()
{
	sf::Texture* spikeText = new sf::Texture();
	spikeText->loadFromFile("spritesheets/s_spike.png");

	setTexture(spikeText);
	//getTexture
	if (pTexture)
		pTexture->setRepeated(1);
}

void Spike::execute()
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
	hitbox = new ObstacleHitbox(this);
	hitbox->setTarget(1);
	hitbox->setCooldown(40);
	hitbox->setSize(getSize());
	hitbox->setHorLaunchStrength(0.f);
	hitbox->setVerLaunchStrength(-40.f);
	hitbox->setDamage(3);
	hitbox->setRelativePosition(sf::Vector2f(0.f, 0.f));
	hitbox->setPosition(getPosition());
	hitbox->ajustToRelativePosition();
}

void Spike::deactivate()
{
	isActive = 0;
}

void Spike::toObstacle()
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