#pragma once
#include "Entity.h"
class Hittable : public Entity
{	
protected:
	int hp;
	bool isAlly;
	int state;
	int stun;
	bool facingRight;
	int points;
public:
	Hittable(const bool ally, const int health);
	enum States
	{
		FREE,
		ATTACK,
		HITSTUN,
		ATKCANCEL,
		PATROLLING, //usar apenas com inimigo
		FOLLOWING //usar apenas com inimigo
	};
	void setState(const int st);
	void setStun(const int st);
	const int getStun() const;
	const int getState() const;
	const bool getIsAlly() const;
	void dealDamage(const int dmg);
	int getHp();
	int getPoints();
	void setPoints(int p);
};

