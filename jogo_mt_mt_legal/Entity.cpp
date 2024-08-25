#include "Entity.h"

Entity::Entity(): Being(), onAir(1)
{ }

Entity::~Entity() { }

const bool Entity::getOnAir() const
{
	return onAir;
}

void Entity::setOnAir(const bool value)
{
	onAir = value;
}

const float Entity::GRAVITY(1.f);
