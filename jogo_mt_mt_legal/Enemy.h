#pragma once
#include "Hittable.h"
#include "Player.h"

class Enemy : public Hittable
{
protected:
	int sightSize;
	int timer;
	Player* followingPlayer;

	double upperLimitMultR;
	double lesserLimitMultR;
	double upperLimitMultL;
	double lesserLimitMultL;
public:
	Enemy();
protected:
	void movementHITSTUN();
	Player* searchPlayer() const;
};

