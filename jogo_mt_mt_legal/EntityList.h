#pragma once
#include "Entity.h"

#include <list>

class EntityList
{
private:
	list<Entity*> entities;
	list<Entity*>::iterator it;
public:
	EntityList();
	~EntityList();
	void start();
	Entity* getCurrent() const;
	void next();
	const int getSize() const;
	void pushBack(Entity* pE);
};

