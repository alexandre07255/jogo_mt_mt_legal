#include "Hitbox.h"
//#include "Level.h"
#include "LevelSave.h"
#include "SceneManager.h"
using namespace Entities::Hitboxes;
using namespace Entities::Characters;
using namespace Scenes;
using namespace Managers;


Hitbox::Hitbox():
	Entity(),
	target(0),
	owner(NULL),
	relativePosition(0.f,0.f),
	duration(1)
{
	Scene* activeScene = SceneManager::getInstance()->top();

	setFillColor(sf::Color::Yellow);
	//setFillColor(sf::Color::Transparent);
	activeScene->addEntity(this);
}

Hitbox::~Hitbox()
{
	Scene* activeScene = SceneManager::getInstance()->top();
	activeScene->removeEntity(this);
}

void Hitbox::setTarget(const bool tar)
{
	target = tar;
}

void Hitbox::setOwner(Hittable* own)
{
	owner = own;
}

Hittable* Hitbox::getOwner()
{
	return owner;
}

void Hitbox::setRelativePosition(sf::Vector2f rel)
{
	relativePosition = rel;
}

void Hitbox::setDuration(const int dur)
{
	duration = dur;
}

void Hitbox::save(LevelSave* save){}