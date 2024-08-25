#pragma once
#include "Being.h"

class Entity : public Being
{
protected:
	bool onAir;
	static const float GRAVITY;
public:
	Entity();
	virtual ~Entity();

	const bool getOnAir() const;

	void setOnAir(const bool value);
};

