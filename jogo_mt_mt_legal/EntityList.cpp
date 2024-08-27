#include "EntityList.h"

EntityList::EntityList() {
}

EntityList::~EntityList(){
	List<Entities::Entity>::Iterator it;

	it = listEntities.begin();

	while (it != listEntities.end()) {
		delete* it;
	}

	listEntities.clear();
}

void EntityList::push_back(Entities::Entity* pE) {
	listEntities.push_back(pE);
}

void EntityList::traverse() {
	List<Entities::Entity>::Iterator itCurrent = listEntities.begin();
	if (listEntities.size() > 0)
	{
		List<Entities::Entity>::Iterator itNext = itCurrent;
		itNext++;
		while (itNext != listEntities.end())
		{
			(*itCurrent)->execute();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->execute();
	}
}

void EntityList::drawAll() {
	List<Entities::Entity>::Iterator itCurrent = listEntities.begin();
	if (listEntities.size() > 0)
	{
		List<Entities::Entity>::Iterator itNext = itCurrent;
		itNext++;
		while (itNext != listEntities.end())
		{
			(*itCurrent)->draw();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->draw();
	}
}

void EntityList::removeEntity(Entities::Entity* pE) {
	listEntities.remove(pE);
}