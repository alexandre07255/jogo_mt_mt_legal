#pragma once
#include "MyDrawable.h"
#include "Updatable.h"

class Entity : public MyDrawable, public Updatable
{
protected:
	float horizontalSpeed;
	float verticalSpeed;
	sf::Vector2f deslocamento;
	bool onAir;
public:
	Entity();
	virtual ~Entity();
	float getNormaDeslocamento();

	sf::Vector2f getDeslocamento();

	void setDeslocamento(sf::Vector2f vetor);

	void setHorizontalVelocity(float vel);

	void setVerticalVelocity(float vel);

	const bool getOnAir() const;

	void setOnAir(const bool value);
};

