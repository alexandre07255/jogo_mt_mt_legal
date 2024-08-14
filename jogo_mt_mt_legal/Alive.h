#pragma once
#include "Entity.h"
class Alive : public Entity
{	
protected:
	int hp;
	bool isAlly;
	int state;
	int stun;
public:
	Alive(const bool ally, const int health);
	enum States
	{
		FREE,
		ATTACK,
		HITSTUN,
		ATKCANCEL
	};
	void setState(const int st);
	void setStun(const int st);
	const int getStun() const;
	const int getState() const;
	const bool getIsAlly() const;
	void dealDamage(const int dmg);
};

