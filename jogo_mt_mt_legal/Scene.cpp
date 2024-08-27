#include "Scene.h"
#include <iostream>
using namespace Scenes;

Scene::Scene() {
	entityList = new EntityList;
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
