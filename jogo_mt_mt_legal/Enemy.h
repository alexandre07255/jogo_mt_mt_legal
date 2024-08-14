#pragma once
#include "Alive.h"
class Enemy : public Alive
{
private:
	int isWorth;
public:
	Enemy();
	void movement();
	void movementFREE();
	void movementHITSTUN();
	void raycasting();
};

