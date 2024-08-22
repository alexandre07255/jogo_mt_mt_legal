#pragma once
#include "Hitbox.h"
#include "Collidable.h"
#include "List.h"


class CollisionManager
{
private:
	static CollisionManager* instance;
	CollisionManager();
public:
	static CollisionManager* getInstance();
	~CollisionManager();
	void testCollison(Entity* pE);
	const bool isColliding(sf::FloatRect one, sf::FloatRect other);
	void testHit(const bool target, Hitbox* hitbox);
};

