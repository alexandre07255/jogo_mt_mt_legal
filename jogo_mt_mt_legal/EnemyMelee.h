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

	bool attacking;
	const int attackStartup;
	const int attackHitboxDuration;
	const int attackEndLag;
	const float attackTriggerRange;
	const float attackTriggerYRange;

	static const float FOLLOW_MAX_HORIZONTAL_SPEED;
	static const float FOLLOW_ACCELARATION;
	static const float WALK_ACCELARATION;
	static const float WALK_MAX_HORIZONTAL_SPEED;
public:
	EnemyMelee();
	void movement();
	void movementFOLLOWING();
	void movementPATROLLING();
	void movementATKCANCEL();
	const bool checkOnLedge() const;
};

