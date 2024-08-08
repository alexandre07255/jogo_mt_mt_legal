#pragma once
#include "MyDrawable.h"

class Entity : public MyDrawable
{
protected:
	float horizontalSpeed;
	float verticalSpeed;
	sf::Vector2f deslocamento;
	bool onAir;
public:
	Entity();
	virtual ~Entity();
	int getNormaDeslocamento();

	sf::Vector2f getDeslocamento();

	void setDeslocamento(sf::Vector2f vetor);

	void setHorizontalVelocity(float vel);

	void setVerticalVelocity(float vel);

	const bool getOnAir() const;

	void setOnAir(const bool value);
};

