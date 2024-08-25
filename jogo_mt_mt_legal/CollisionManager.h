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
	void testPlayerToEnemyCollision(Player* player);
	const bool isColliding(sf::FloatRect one, sf::FloatRect other);
	void testHit(const bool target, Hitbox* hitbox);
	float nearestCollidable(MyDrawable* relativeTo, float maxHeight) const;
};

