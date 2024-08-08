#include "CollisionManager.h"

CollisionManager* CollisionManager::instance(NULL);

CollisionManager::CollisionManager():
	collidables(NULL)
{

}

CollisionManager::~CollisionManager()
{

}

CollisionManager* CollisionManager::getInstance()
{
	if (instance == NULL)
		instance = new CollisionManager;
	return instance;
}

void CollisionManager::testCollison(Entity* pE)
{
	if (collidables == NULL)
		return;

	int size = collidables->getSize();
	collidables->start();
	Entity* current = NULL;
	for (int i = 0; i < size; i++)
	{
		cu
	}
}

void CollisionManager::setCollidables(EntityList* pC)
{
	collidables = pC;
}
