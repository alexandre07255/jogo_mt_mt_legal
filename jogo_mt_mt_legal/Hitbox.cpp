#include "Hitbox.h"
#include "Level.h"

Hitbox::Hitbox(const bool tar, Alive* own, Entity* boundTo, sf::Vector2f rel, const int dur, sf::Vector2f _size):
	target(tar),
	owner(own),
	boundedTo(boundTo),
	relativePosition(rel),
	duration(dur)
{
	setSize(_size);
	if (own != NULL)
	{
		setPosition(boundTo->getPosition());
		move(rel);
	}

	Level* activeInstance = Level::getActive();
	activeInstance->addUpdatable(this);
}
