#include "Obstacle.h"

Obstacle::Obstacle() :
	Entity(),
	isActive(0),
	spawnedHitbox(0)
{

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