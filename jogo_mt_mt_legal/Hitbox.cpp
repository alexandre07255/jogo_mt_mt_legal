#include "Hitbox.h"
#include "Level.h"

Hitbox::Hitbox(const bool tar, Alive* own, Entity* boundTo, sf::Vector2f rel, const int dur, sf::Vector2f _size):
	target(0),
	owner(NULL),
	boundedTo(NULL),
	relativePosition(),
	duration(0)
{
	if (own != NULL)
	{
		setPosition(boundTo->getPosition());
		move(rel);
	}

	Level* activeInstance = Level::getActive();
	activeInstance->addUpdatable(this);
}

setSize(_size);