#pragma once
#include "MyDrawable.h"

class Entity: public MyDrawable
{
protected:
	float horizontalSpeed;
	float verticalSpeed;
	sf::Vector2f deslocamento;
public:
	Entity();
	virtual ~Entity();
	int getNormaDeslocamento();

	sf::Vector2f getDeslocamento();

	void setDeslocamento(sf::Vector2f vetor);
};

