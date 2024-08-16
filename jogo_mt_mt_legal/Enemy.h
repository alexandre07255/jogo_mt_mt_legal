#pragma once
#include "Alive.h"
#include "Player.h"

class Enemy : public Alive
{
protected:
	int isWorth;
	int sightSize;
	int timer;
	Player* followingPlayer;
	static const int MAX_HORIZONTAL_SPEED;
	static const int ACCELARATION;
public:
	Enemy();
	virtual void movement();
	virtual void movementPATROLLING();
	void movementHITSTUN();
	virtual void movementFOLLOWING();
	Player* searchPlayer();
};

