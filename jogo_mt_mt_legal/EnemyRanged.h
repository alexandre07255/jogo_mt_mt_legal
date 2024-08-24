#pragma once
#include "Enemy.h"
class EnemyRanged : public Enemy
{
private:
	int walkingBuffer;
	int waitBuffer;
	bool direction;

	const int attackStartup;
	const int attackEndLag;
	const float heightStrip;
	const float idealHeight;
	const float attackTriggerRange;
	const float attackTriggerYRange;


	static const float MAX_HEIGHT;
	static const float FLY_STRENGTH;
	static const float FOLLOW_MAX_HORIZONTAL_SPEED;
	static const float FOLLOW_ACCELARATION;
	static const float WALK_ACCELARATION;
	static const float WALK_MAX_HORIZONTAL_SPEED;
public:
	EnemyRanged();
	void movement();
private:
	void movementFOLLOWING();
	void movementPATROLLING();
	void movementATKCANCEL();
};

