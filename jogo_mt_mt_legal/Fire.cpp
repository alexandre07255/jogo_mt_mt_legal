#include "Fire.h"
#include "CollisionManager.h"
#include "LevelSave.h"
#include "ObstacleHitbox.h"
#include "SpriteManager.h"
using namespace Entities::Hitboxes;
using namespace Entities::Characters;
using namespace Managers;
using namespace Entities::Obstacles;


Fire::Fire() :
	Obstacle(),
	lingeringTime(5)
{

}

Fire::~Fire() { }

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
		setPosition(left(), floor - getYSize());
		activate();

		SpriteManager* spInstance = SpriteManager::getInstance();
		spriteMatrixIndex = spInstance->getMatrixIndex("Fire");

		srand(time(NULL));
		spriteX = rand() % 6;

		spInstance->getTexture(this, spriteMatrixIndex, spriteX, 0);

		pShape->setTextureRect(sf::IntRect(0, 0, (int)(width / height) * 16, 16));

		pTexture->setRepeated(1);

		spawnedHitbox = 1;
	}

	if (frameCont >= 6)
	{
		SpriteManager* spInstance = SpriteManager::getInstance();
		spInstance->next(this, spriteMatrixIndex, spriteX, spriteY);
		pTexture->setRepeated(1);
		frameCont = 0;
	}
	else
		frameCont++;
}

void Fire::activate()
{
	isActive = 1;
	hitbox = new ObstacleHitbox(this);
	hitbox->setTarget(1);
	hitbox->setCooldown(30);
	hitbox->setSize(getXSize(), getYSize());
	hitbox->setHorLaunchStrength(0.f);
	hitbox->setVerLaunchStrength(0.f);
	hitbox->setDamage(1);
	hitbox->setRelativePosition(sf::Vector2f(0.f, 0.f));
	hitbox->setPosition(getXPosition(), getYPosition());
	hitbox->adjustToRelativePosition();
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