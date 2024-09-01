#include "Support.h"
#include "CollisionManager.h"
#include "Level.h"
#include "SceneManager.h"
#include <iostream>
#include "LevelSave.h"
#include <list>
#include "Platform.h"
#include "SpriteManager.h"
using namespace Managers;
using namespace Scenes;
using namespace Entities;
//using namespace Entities::Characters;


Support::Support(Obstacles::Platform* plat, const float sHeight):Hittable(false,MAXHEALTH),boundedTo(NULL) {
	boundedTo = plat;

	if (boundedTo) {
		SceneManager* instance = SceneManager::getInstance();
		
		Level* active = static_cast<Level*>(instance->top());
		list<Collidable*>* collidables = active->getCollidables();

		float positionY = boundedTo->bottom();
		float positionX = boundedTo->xMid() - 16.f * 3 / 2;
		setPosition(positionX, positionY);

		
		setSize(sf::Vector2f(16.0 * 3, sHeight));

		SpriteManager* spInstance = SpriteManager::getInstance();
		spriteMatrixIndex = spInstance->getMatrixIndex("Support");

		spInstance->getTexture(this, spriteMatrixIndex, 0, 0);

		pShape->setTextureRect(sf::IntRect(0, 0, 16, (int)(width / height) * 16));

		pTexture->setRepeated(1);
	}
}

Support::~Support()
{
	boundedTo = NULL;
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

int Support::MAXHEALTH(3);