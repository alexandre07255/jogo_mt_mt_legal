#pragma once
#include "Being.h"

class Entity : public Being
{
protected:
	bool onAir;
	float frictionFelt;
	static const float GRAVITY;
	float xPos;
	float yPos;
	float height;
	float width;
public:
	Entity();
	virtual ~Entity();

	const bool getOnAir() const;
	void setOnAir(const bool value);
	void setFriction(float fric);

	void setSizeEntity(float x, float y);
	sf::Vector2f getSize() const;

	void setPositionEntity(float x, float y);
	sf::Vector2f getPosition() const;

	virtual void save() = 0;
	virtual void execute() = 0;
};

