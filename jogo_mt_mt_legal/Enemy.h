#pragma once
#include "Hittable.h"
#include "Player.h"

class Enemy : public Hittable
{
protected:
	int isWorth;
	int sightSize;
	int timer;
	Player* followingPlayer;
	static const float MAX_HORIZONTAL_SPEED;
	static const float ACCELARATION;
public:
	Enemy();
	virtual void movement();
	virtual void movementPATROLLING();
	void movementHITSTUN();
	virtual void movementFOLLOWING();
	Player* searchPlayer() const;
};

