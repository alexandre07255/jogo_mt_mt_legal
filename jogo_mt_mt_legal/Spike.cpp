#include "Spike.h"
#include "CollisionManager.h"
#include "LevelSave.h"
#include "ObstacleHitbox.h"
#include "SpriteManager.h"
using namespace Managers;
using namespace Entities::Hitboxes;
using namespace Entities::Obstacles;



Spike::Spike():
	firstStep(1),
	Obstacle()
{
	//sf::Texture* spikeText = new sf::Texture();
	//spikeText->loadFromFile("spritesheets/s_spike.png");

	//setTexture(spikeText);
	//getTexture
	if (pTexture)
		pTexture->setRepeated(1);
}

Spike::~Spike() { }

void Spike::execute()
{
	if (firstStep)
	{
		CollisionManager* cInstance = CollisionManager::getInstance();
		float floor = cInstance->nearestCollidable(this, 900.f);
		setPosition(left(), floor - getYSize());
		activate();

		SpriteManager* spInstance = SpriteManager::getInstance();
		spriteMatrixIndex = spInstance->getMatrixIndex("Spike");

		spInstance->getTexture(this, spriteMatrixIndex, 0, 0);

		pShape->setTextureRect(sf::IntRect(0, 0, (int)(width / height) * 16, 16));

		pTexture->setRepeated(1);

		firstStep = 0;
	}
}

void Spike::activate()
{
	isActive = 1;
	hitbox = new ObstacleHitbox(this);
	hitbox->setTarget(1);
	hitbox->setCooldown(40);
	hitbox->setSize(getXSize(), getYSize());
	hitbox->setHorLaunchStrength(0.f);
	hitbox->setVerLaunchStrength(-20.f);
	hitbox->setDamage(2);
	hitbox->setRelativePosition(sf::Vector2f(0.f, 0.f));
	hitbox->setPosition(getXPosition(), getYPosition());
	hitbox->adjustToRelativePosition();
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

void Spike::save(LevelSave* save){
	save->addSpike(this);
}