#include "Hitbox.h"
#include "Level.h"

Hitbox::Hitbox():
	target(0),
	owner(NULL),
	boundedTo(NULL),
	relativePosition(),
	duration(0)
{
	Level* activeInstance = static_cast<Level*>(Scene::getActive());
	activeInstance->addUpdatable(this);

	setFillColor(sf::Color::Yellow);
	activeInstance->addDrawable(this);
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
