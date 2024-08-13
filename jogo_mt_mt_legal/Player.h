#pragma once
#include "Alive.h"

class Player : public Alive
{
private:
	bool player2;
	static const int MAX_HP;
	static const int MAX_HORIZONTAL_SPEED;
	static const int MAX_VERTICAL_SPEED;
	static const int ACCELARATION;
	static const int MAX_JUMP_BUFFER;
	static const int JUMP_STREGTH;
	static const int MAX_ATTACK_BUFFER;
	int jumpBuffer;
	int attackBuffer;
public:
	Player(const bool isPlayer2, const bool ally, const int health);
	void movement();
};

