#pragma once
#include "Alive.h"

class Hitbox : public Being
{
protected:
	bool target;
	Alive* owner;
	Entity* boundedTo;
	sf::Vector2f relativePosition;
	int duration;
public:
	Hitbox();
	void setTarget(const bool tar);
	void setOwner(Alive* own);
	void setBoundedTo(Entity* boundTo);
	void setRelativePosition(sf::Vector2f rel);
	void setDuration(const int dur);
	virtual void hitSolution(Alive* hit) = 0;
};

