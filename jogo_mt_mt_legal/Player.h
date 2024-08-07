#pragma once
#include "Alive.h"
class Player : public Alive
{
private:
	bool player2;
	static float MAX_HORIZONTAL_SPEED;
	static float MAX_VERTICAL_SPEED;
	static float ACCELARATION;
public:
	void movement();
};

