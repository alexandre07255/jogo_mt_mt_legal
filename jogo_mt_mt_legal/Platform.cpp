#include "Platform.h"
#include "CollisionManager.h"
#include "Support.h"
#include "SceneManager.h"
#include "Level.h"

Platform::Platform(float xPosition, float yPosition, float xSize, float ySize):Obstacle(),Collidable(),support(NULL),firstStep(true) {
	setPosition(xPosition, yPosition);
	setSize(sf::Vector2f(xSize, ySize));

	collidableId = getId();
}

sf::FloatRect Platform::getBounds() {
	return getGlobalBounds();
}

void Platform::movement() {
	CollisionManager* instance = CollisionManager::getInstance();
	
	if (firstStep) {
		SceneManager* sinstance = SceneManager::getInstance();
		Level* level = static_cast<Level*>(sinstance->top());

		move(0,1);
		instance->testCollison(this);
		if (onAir) {
			support = new Support(this);
			level->addHittable(support);
			level->addDrawable(support);
			level->addUpdatable(support);
			setOnAir(false);
		}
		firstStep = false;
	}
	else if (onAir) {
		move(0, 1);
		instance->testCollison(this);
	}
}

Support* Platform::getSupport() {
	return support;
}