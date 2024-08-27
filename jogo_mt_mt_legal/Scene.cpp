#include "Scene.h"
#include <iostream>
using namespace Scenes;
using namespace Lists;

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

void Scene::update() {
	escResolver();
	entityList->traverse();
}

void Scene::setEntityList(EntityList* list) {
	entityList = list;
}
