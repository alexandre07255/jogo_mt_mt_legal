#include "EntityList.h"

EntityList::EntityList() :
	entities(),
	it(entities.begin())
{

}

EntityList::~EntityList()
{

}

void EntityList::start()
{
	it = entities.begin();
}

Entity* EntityList::getCurrent() const
{
	return (*it);
}

void EntityList::next()
{
	if (it != entities.end())
		it++;
}

const int EntityList::getSize() const
{
	return entities.size();
}

void EntityList::pushBack(Entity* pE)
{
	entities.push_back(pE);
}
