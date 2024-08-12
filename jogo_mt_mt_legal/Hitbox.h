#pragma once
#include "Alive.h"

class Hitbox : public Entity
{
private:
	bool target;
	Entity* owner;
	bool isBounded;
	//sf::Vector2f relativePosition;
public:
	Hitbox(const bool tar, Entity* own, const bool isBo);
	virtual void hitSolution(Alive* hit);
	virtual void movement();
};

