#pragma once
#include "Alive.h"
#include "Player.h"

class Enemy : public Alive
{
private:
	int isWorth;
	int sightSize;
	int timer;
	Player* followingPlayer;
	static const int MAX_HORIZONTAL_SPEED;
	static const int ACCELARATION;
public:
	Enemy();
	void movement();
	void movementFREE();
	void movementHITSTUN();
	void movementFOLLOWING();
	Player* searchPlayer();
};

