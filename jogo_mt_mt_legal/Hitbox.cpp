#include "Hitbox.h"
//#include "Level.h"
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
	activeScene->addEntity(this);

	setFillColor(sf::Color::Yellow);
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

void Hitbox::save() { }

void Hitbox::setRelativePosition(sf::Vector2f rel)
{
	relativePosition = rel;
}

void Hitbox::setDuration(const int dur)
{
	duration = dur;
}
