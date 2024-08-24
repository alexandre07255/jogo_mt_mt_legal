#include "Support.h"
#include "CollisionManager.h"
#include "Level.h"
#include "SceneManager.h"
#include <iostream>

Support::Support(Platform* plat, const float height):Hittable(false,MAXHEALTH),boundedTo(NULL) {
	boundedTo = plat;

	if (boundedTo) {
		SceneManager* instance = SceneManager::getInstance();
		
		Level* active = static_cast<Level*>(instance->top());
		List<Collidable>* collidables = active->getCollidable();

		float positionY = boundedTo->getPosition().y + boundedTo->getSize().y;
		float positionX = boundedTo->getPosition().x + boundedTo->getSize().x / 2 - 5.f;
		setPosition(positionX, positionY);

		
		setSize(sf::Vector2f(10.0, height));
	}
}

void Support::setPlatform(Platform* plat) {
	boundedTo = plat;
}

void Support::movement() {
	if (hp <= 0) {
		//remover coisas hehehe
		boundedTo->setOnAir(true);
		SceneManager* sinstance = SceneManager::getInstance();
		Level* level = static_cast<Level*>(sinstance->top());

		level->removeDrawable(this);
		level->removeHittable(this);
		level->removeUpdatable(this);

		delete this;
	}
	//std::cout << hp << endl;
}

int Support::MAXHEALTH(10);