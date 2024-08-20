#include "Obstacle.h"

Obstacle::Obstacle() :
	Entity(),
	isActive(0)
{

}

const bool Obstacle::getIsActive() const
{
	return isActive;
}

void Obstacle::setIsActive(const bool active)
{
	isActive = active;
}