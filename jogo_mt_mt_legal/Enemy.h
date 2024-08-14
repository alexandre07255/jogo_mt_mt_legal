#pragma once
#include "Alive.h"
#include "Player.h"

class Enemy : public Alive
{
private:
	int isWorth;
	int sightSize;
	Player* followingPlayer;
public:
	Enemy();
	void movement();
	void movementFREE();
	void movementHITSTUN();
	Player* searchPlayer();
};

