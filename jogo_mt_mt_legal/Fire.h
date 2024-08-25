#pragma once
#include "Obstacle.h"
#include "ObstacleHitbox.h"
class Fire : public Obstacle
{
private:
	bool firstStep;
	int lingeringTime;
public:
	Fire();
	void movement();
	void statusEffect(Hittable* hit);
	void setLingeringTime(const int time);
	void activate();
	void deactivate();
};

