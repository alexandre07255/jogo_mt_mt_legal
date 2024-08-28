#include "Platform.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "Level.h"
#include "ObstacleHitbox.h"
#include <math.h>
#include"iostream"
using namespace Managers;
using namespace Entities::Obstacles;
using namespace Entities::Characters;
using namespace Scenes;
using namespace Entities;
using namespace Entities::Hitboxes;



Platform::Platform(float xPosition, float yPosition, float xSize, float ySize) :Obstacle(), Collidable(), support(NULL),
firstStep(true), minimalHeight(50.f), mass(10.f), time(0),deformation(0),onTop(false), hitboxRight(NULL) {
	setPosition(xPosition, yPosition);
	setSize(sf::Vector2f(xSize, ySize));

	collidableId = getId();

	defaultY = yPosition;
	friction = 1.f;
}

sf::FloatRect Platform::getBounds() {
	return getGlobalBounds();
}

void Platform::execute() {
	CollisionManager* instance = CollisionManager::getInstance();
	
	if (firstStep) {
		CollisionManager* cinstance = CollisionManager::getInstance();
		Level* level = static_cast<Level*>(SceneManager::getInstance()->top());

		instance->testCollison(this);

		float height = cinstance->nearestCollidable(this, 600.f);
		if (height - bottom() > minimalHeight)
		{
			support = new Support(this, height - bottom());
			level->addSupport(support);
			level->addEntity(support);
			onAir = 0;
		}
		else
			onAir = 1;

		firstStep = false;
	}
	if (onAir) {
		support = NULL;
		move(0, 1);
		instance->testCollison(this);
		isActive = 1;
		if (!spawnedHitbox)
		{
			spawnedHitbox = 1;

			hitbox = new ObstacleHitbox(this);
			hitbox->setTarget(1);
			hitbox->setCooldown(20);
			hitbox->setSize(sf::Vector2f(getSize().x / 2, getSize().y / 2));
			hitbox->setHorLaunchStrength(-25.0);
			hitbox->setVerLaunchStrength(0.0);
			hitbox->setDamage(3);
			hitbox->setRelativePosition(sf::Vector2f(0.0, getSize().y));

			hitboxRight = new ObstacleHitbox(this);
			hitboxRight->setTarget(1);
			hitboxRight->setCooldown(40);
			hitboxRight->setSize(sf::Vector2f(getSize().x / 2, getSize().y / 2));
			hitboxRight->setHorLaunchStrength(25.0);
			hitboxRight->setVerLaunchStrength(0.0);
			hitboxRight->setDamage(3);
			hitboxRight->setRelativePosition(sf::Vector2f(getSize().x / 2, getSize().y));
		}
	}
	/*else if (support)
	{
		if (onTop) {
			deformation = getPosition().y - defaultY;
			//eu nao sei ta bom, eu so nao sei
			SceneManager* instance = SceneManager::getInstance();
			Level* curL = static_cast<Level*>(instance->top());
			list<Hittable*>* lista = curL->getHittableList();

			list<Hittable*>::Iterator it = lista->begin();
			bool flag = 1;
			for (int i = 0;i < lista->size();i++) {
				if ((*it)->bottom() == top() + 1.f) {
					flag = 0;
				}
				it++;
			}
			if (flag) {
				onTop = false;
			}
		}

		if (deformation && !onTop) {
			float yDislocation = HarmonicMovement(deformation + 10, mass, 5.f, 2.f, time);
			setPosition(getPosition().x, yDislocation + defaultY);
			time++;
		}
		else {
			time = 0;
		}
		isActive = 0;
	}*/
	else {
		isActive = 0;
	}
}

void Platform::toObstacle()
{
	if (isActive)
	{
		hitbox->setPosition(getPosition());
		hitbox->ajustToRelativePosition();

		hitboxRight->setPosition(getPosition());
		hitboxRight->ajustToRelativePosition();

		CollisionManager* collisionInstance = CollisionManager::getInstance();
		collisionInstance->testHit(1, hitbox);
		collisionInstance->testHit(1, hitboxRight);
	}
	else
	{
		hitbox = NULL;
		hitboxRight = NULL;
	}
}

Support* Platform::getSupport() {
	return support;
}

float Platform::HarmonicMovement(float range, float mass, float elasticity, float damping, float time) {
	float frequency = sqrt(elasticity / mass - ((damping * damping) / (4 * mass * mass)));
	float amplitude = range * exp((-damping * time) / (2.f * mass));

	return (amplitude * cos(frequency * time));

}

void Platform::collisionSolution(Entity* pE) {
	//if(!onTop)
	//	move(0, 1.f * pE->getVerticalSpeed());
	//onTop = true;
	pE->setFriction(friction);
}

