#pragma once
#include "MyDrawable.h"
#include "Updatable.h"

class Being : public MyDrawable, public Updatable
{
protected:
	float horizontalSpeed;
	float verticalSpeed;
public:
	Being();

	void setHorizontalVelocity(float vel);

	void setVerticalVelocity(float vel);
};

