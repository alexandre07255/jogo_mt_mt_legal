#include "Hitbox.h"
//#include "Level.h"
#include "SceneManager.h"

Hitbox::Hitbox():
	Being(),
	target(0),
	owner(NULL),
	boundedTo(NULL),
	relativePosition(),
	duration(0)
{
	Scene* activeScene = SceneManager::getInstance()->top();
	activeScene->addUpdatable(this);

	setFillColor(sf::Color::Yellow);
	activeScene->addDrawable(this);
}

void Hitbox::setTarget(const bool tar)
{
	target = tar;
}

void Hitbox::setOwner(Alive* own)
{
	owner = own;
}

void Hitbox::setBoundedTo(Entity* boundTo)
{
	boundedTo = boundTo;
}

void Hitbox::setRelativePosition(sf::Vector2f rel)
{
	relativePosition = rel;
}

void Hitbox::setDuration(const int dur)
{
	duration = dur;
}
