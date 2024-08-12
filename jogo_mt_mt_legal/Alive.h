#pragma once
#include "Entity.h"
class Alive : public Entity
{	
protected:
	int hp;
	bool isAlly;
public:
	Alive(const bool ally, const int health);
	const bool getIsAlly() const;
};

