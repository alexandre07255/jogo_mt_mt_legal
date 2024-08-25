#pragma once
#include "Obstacle.h"
class Spike : public Obstacle
{
private:
	bool firstStep;
public:
	Spike();
	void movement();
	void activate();
	void deactivate();
};

