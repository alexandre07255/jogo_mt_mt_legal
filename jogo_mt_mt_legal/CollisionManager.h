#pragma once
#include "EntityList.h"

class CollisionManager
{
private:
	static CollisionManager* instance;
	EntityList* collidables;
	CollisionManager();
public:
	static CollisionManager* getInstance();
	~CollisionManager();
	void testCollison(Entity* pE);
	void setCollidables(EntityList* pC);
	const bool isColliding(sf::FloatRect one, sf::FloatRect other);
};

