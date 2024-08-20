#pragma once
#include "Entity.h"
class Obstacle : public Entity
{
protected:
	bool isActive;
public:
	Obstacle();
	const bool getIsActive() const;
	void setIsActive(const bool active);
};

