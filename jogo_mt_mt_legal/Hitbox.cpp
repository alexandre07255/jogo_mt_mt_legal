#include "Hitbox.h"

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
		int _x = own->getPosition().x + rel.x;
		int _y = own->getPosition().y + rel.y;
		setPosition(sf::Vector2f(_x, _y));
	}
}

