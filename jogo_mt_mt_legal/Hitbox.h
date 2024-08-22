#pragma once
#include "Hittable.h"

class Hitbox : public Being
{
protected:
	bool target;
	Hittable* owner;
	Entity* boundedTo;
	sf::Vector2f relativePosition;
	int duration;
public:
	Hitbox();
	void setTarget(const bool tar);
	void setOwner(Hittable* own);
	Hittable* getOwner();
	void setBoundedTo(Entity* boundTo);
	void setRelativePosition(sf::Vector2f rel);
	void setDuration(const int dur);
	virtual void hitSolution(Hittable* hit) = 0;
};

