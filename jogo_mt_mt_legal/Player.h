#pragma once
#include "Alive.h"

class Player : public Alive
{
private:
	bool player2;
	static const int MAX_HORIZONTAL_SPEED;
	static const int MAX_VERTICAL_SPEED;
	static const int ACCELARATION;
	static const int MAX_JUMP_BUFFER;
	static const int JUMP_STREGTH;
	int jumpBuffer;
public:
	Player(const bool isPlayer2);
	void movement();
};

