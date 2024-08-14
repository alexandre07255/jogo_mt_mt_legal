#pragma once
#include "Alive.h"
class Enemy : public Alive
{
private:
	int isWorth;
	int sightSize;
public:
	Enemy();
	void movement();
	void movementFREE();
	void movementHITSTUN();
	const bool searchPlayer();
};

