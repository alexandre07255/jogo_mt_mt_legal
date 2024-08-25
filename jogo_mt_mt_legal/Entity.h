#pragma once
#include "Being.h"

class Entity : public Being
{
protected:
	bool onAir;
	float frictionFelt;
public:
	Entity();
	virtual ~Entity();

	const bool getOnAir() const;

	void setOnAir(const bool value);

	void setFriction(float fric);
};

