#include "Entity.h"
using namespace Entities;


Entity::Entity(): Being(), onAir(1), frictionFelt(1)
{
	pShape = new sf::RectangleShape();
}

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

void Entity::setFriction(float fric){
	frictionFelt = fric;
}

void Entity::setSizeEntity(float x, float y) {
	pShape->setSize(sf::Vector2f(x, y));
}

sf::Vector2f Entity::getSize() const{
	return (sf::Vector2f(height, width));
}

void Entity::setPositionEntity(float x, float y) {
	pShape->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Entity::getPosition()const {
	return (sf::Vector2f(xPos, yPos));
}