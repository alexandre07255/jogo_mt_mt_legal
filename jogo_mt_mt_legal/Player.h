#pragma once
#include "Alive.h"

class Player : public Alive
{
private:

	static const int MAX_HP;
	static const int MAX_HORIZONTAL_SPEED;
	static const int MAX_VERTICAL_SPEED;
	static const int ACCELARATION;
	static const int MAX_JUMP_BUFFER;
	static const int JUMP_STREGTH;
	static const int MAX_ATTACK_BUFFER;

	const int ATTACK1_STARTUP;
	const int ATTACK2_STARTUP;
	const int ATTACK3_STARTUP;

	bool player2;
	int jumpBuffer;
	int attackBuffer;
	int attackCounter;
	bool wasAttackPressed;
	int friction;
public:
	Player(const bool isPlayer2, const bool ally, const int health);
	void movement();
	void movementFREE();
	void movementATKCANCEL();
	void attack();
};

