#include "Entity.h"

Entity::Entity(): MyDrawable(), horizontalSpeed(1), verticalSpeed(1) { deslocamento.x = 0; deslocamento.y = 0; }

Entity::~Entity() { }

int Entity::getNormaDeslocamento()
{
	return sqrt(deslocamento.x * deslocamento.x + deslocamento.y * deslocamento.y);
}

sf::Vector2f Entity::getDeslocamento() { return deslocamento; }

void Entity::setDeslocamento(sf::Vector2f vetor) { deslocamento = vetor; }