#pragma once
#include "Alive.h"

class Hitbox : public Entity
{
protected:
	bool target;
	Alive* owner;
	Entity* boundedTo;
	sf::Vector2f relativePosition;
	int duration;
public:
	Hitbox(const bool tar, Alive* own, Entity* boundTo, sf::Vector2f rel, const int dur, sf::Vector2f _size);
	virtual void hitSolution(Alive* hit) = 0;
};

