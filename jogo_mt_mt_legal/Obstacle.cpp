#include "Obstacle.h"
#include "ObstacleHitbox.h"
using namespace Entities::Obstacles;
using namespace Entities::Characters;

Obstacle::Obstacle() :
	Entity(),
	isActive(0),
	spawnedHitbox(0),
	hitbox(NULL)
{

}

Obstacle::~Obstacle()
{
	hitbox = NULL;
}

const bool Obstacle::getIsActive() const
{
	return isActive;
}

void Obstacle::statusEffect(Hittable* hit)
{

}

void Obstacle::setIsActive(const bool active)
{
	isActive = active;
}

void Obstacle::setSpawnedHitbox(const bool spa)
{
	spawnedHitbox = spa;
}