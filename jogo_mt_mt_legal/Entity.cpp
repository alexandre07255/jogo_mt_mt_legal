#include "Entity.h"

Entity::Entity(): MyDrawable(), Updatable(), horizontalSpeed(0), verticalSpeed(0), onAir(1)
{ deslocamento.x = 0; deslocamento.y = 0; }

Entity::~Entity() { }

float Entity::getNormaDeslocamento()
{
	return sqrt(deslocamento.x * deslocamento.x + deslocamento.y * deslocamento.y);
}

sf::Vector2f Entity::getDeslocamento() { return deslocamento; }

void Entity::setDeslocamento(sf::Vector2f vetor) { deslocamento = vetor; }

void Entity::setHorizontalVelocity(float vel) { horizontalSpeed = vel; }

void Entity::setVerticalVelocity(float vel) { verticalSpeed = vel; }

const bool Entity::getOnAir() const
{
	return onAir;
}

void Entity::setOnAir(const bool value)
{
	onAir = value;
}