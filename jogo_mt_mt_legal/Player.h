#pragma once
#include "Alive.h"

class Player : public Alive
{
private:

	static const int MAX_HP;
	static const float MAX_HORIZONTAL_SPEED;
	static const float MAX_VERTICAL_SPEED;
	static const float ACCELARATION;
	static const int MAX_JUMP_BUFFER;
	static const float JUMP_STRENGTH;
	static const int MAX_JUMP_PERIOD;
	static const int MAX_ATTACK_BUFFER;

	const int attackStartup[3];
	const int attackHitboxDuration[3];
	const int attackEndLag[3];

	bool player2;
	int jumpBuffer;
	bool isStillJumping;
	int jumpLength;
	int attackBuffer;
	int attackCounter;
	bool hasAttacked;
	bool wasAttackPressed;
	float friction;
public:
	Player(const bool isPlayer2, const bool ally, const int health);
	void movement();
	void movementFREE();
	void movementATKCANCEL();
	void movementATTACK();
	void attack();
};

