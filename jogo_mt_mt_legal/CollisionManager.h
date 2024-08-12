#pragma once
#include "EntityList.h"
#include "Hitbox.h"

class CollisionManager
{
private:
	static CollisionManager* instance;
	EntityList* collidables;
	list<Alive*>* aliveList;
	CollisionManager();
public:
	static CollisionManager* getInstance();
	~CollisionManager();
	void testCollison(Entity* pE);
	void setCollidables(EntityList* pC);
	const bool isColliding(sf::FloatRect one, sf::FloatRect other);
	void setAliveList(list<Alive*>* Alist);
	void testHit(const bool target, Hitbox* hitbox);
};

