#include "Hitbox.h"
#include "Level.h"

Hitbox::Hitbox(const bool tar, Alive* own, Entity* boundTo, sf::Vector2f rel, const int dur, sf::Vector2f _size):
	target(0),
	owner(NULL),
	boundedTo(NULL),
	relativePosition(),
	duration(0)
{
	Level* activeInstance = Level::getActive();
	activeInstance->addUpdatable(this);
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
