#pragma once
#include "Hitbox.h"
#include "Collidable.h"
#include <list>


class CollisionManager
{
private:
	static CollisionManager* instance;
	list<Collidable*>* collidables;
	list<Alive*>* aliveList;
	CollisionManager();
public:
	static CollisionManager* getInstance();
	~CollisionManager();
	void testCollison(Entity* pE);
	void setCollidables(list<Collidable*>* pC);
	const bool isColliding(sf::FloatRect one, sf::FloatRect other);
	void setAliveList(list<Alive*>* Alist);
	void testHit(const bool target, Hitbox* hitbox);
	list<Collidable*>* getCollidables();
	list<Alive*>* getAliveList();
};

