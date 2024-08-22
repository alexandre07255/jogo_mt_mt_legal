#pragma once
#include "Entity.h"
class Obstacle : public Entity
{
protected:
	bool isActive;
	bool spawnedHitbox;
public:
	Obstacle();
	const bool getIsActive() const;
	void setIsActive(const bool active);
	void setSpawnedHitbox(const bool spa);
};

