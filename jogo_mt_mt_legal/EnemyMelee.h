#pragma once
#include "Enemy.h"
#include "Player.h"

class EnemyMelee : public Enemy
{
private:
	int walkingBuffer;
	int waitBuffer;
	bool direction;
	static const int JUMP_STRENGTH;
public:
	EnemyMelee();
	void movement();
	void movementFOLLOWING();
	void movementPATROLLING();
};

