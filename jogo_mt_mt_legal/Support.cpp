#include "Support.h"
#include "CollisionManager.h"
#include "Level.h"
#include "SceneManager.h"
#include <iostream>
#include "LevelSave.h"
#include <list>
#include "Platform.h"
using namespace Managers;
using namespace Scenes;
using namespace Entities;
//using namespace Entities::Characters;


Support::Support(Obstacles::Platform* plat, const float sHeight):Hittable(false,MAXHEALTH),boundedTo(NULL) {
	boundedTo = plat;
	canBeCollided = 0;

	if (boundedTo) {
		SceneManager* instance = SceneManager::getInstance();
		
		Level* active = static_cast<Level*>(instance->top());
		list<Collidable*>* collidables = active->getCollidables();

		float positionY = boundedTo->bottom();
		float positionX = boundedTo->xMid() - 5.f;
		setPosition(positionX, positionY);

		
		setSize(sf::Vector2f(10.0, sHeight));
	}
}

void Support::setPlatform(Obstacles::Platform* plat) {
	boundedTo = plat;
}

void Support::execute() {
	if (hp <= 0) {
		//remover coisas hehehe
		boundedTo->setOnAir(true);
		SceneManager* sinstance = SceneManager::getInstance();
		Level* level = static_cast<Level*>(sinstance->top());

		level->removeEntity(this);
		level->removeSupport(this);
		delete this;
	}
	//std::cout << hp << endl;
}

void Support::save(LevelSave* save)
{

}

int Support::MAXHEALTH(10);