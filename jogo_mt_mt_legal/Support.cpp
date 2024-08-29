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


Support::Support(Obstacles::Platform* plat, const float height):Hittable(false,MAXHEALTH),boundedTo(NULL) {
	boundedTo = plat;
	canBeCollided = 0;

	if (boundedTo) {
		SceneManager* instance = SceneManager::getInstance();
		
		Level* active = static_cast<Level*>(instance->top());
		list<Collidable*>* collidables = active->getCollidables();

		float positionY = boundedTo->getPosition().y + boundedTo->getSize().y;
		float positionX = boundedTo->getPosition().x + boundedTo->getSize().x / 2 - 5.f;
		setPosition(positionX, positionY);

		
		setSize(sf::Vector2f(10.0, height));
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