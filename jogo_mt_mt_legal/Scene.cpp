#include "Scene.h"
#include <iostream>
#include "inputManager.h"
using namespace Scenes;
using namespace Lists;
using namespace Managers;

Scene::Scene() {
	entityList = new EntityList;
}

Scene::~Scene()
{
	delete entityList;
}

void Scene::draw() {
	entityList->drawAll();
}

void Scene::addEntity(Entities::Entity* pU) {
	entityList->push_back(pU);
}

void Scene::removeEntity(Entities::Entity* pU) {
	entityList->removeEntity(pU);
}

void Scene::execute() {
	entityList->traverse();
	escChecker();
}

void Scene::setEntityList(EntityList* list) {
	entityList = list;
}

void Scene::escChecker()
{
	InputManager* iInstance = InputManager::getInstance();
	if (iInstance->isPausePressed())
	{
		if (!iInstance->getWasEscPressed())
			escResolver();
		iInstance->setWasEscPressed(1);
	}
	else
		iInstance->setWasEscPressed(0);
}