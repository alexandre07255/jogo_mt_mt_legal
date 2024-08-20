#include "Being.h"

Being::Being() :
	MyDrawable(),
	Updatable(),
	horizontalSpeed(0),
	verticalSpeed(0)
{

}

void Being::setHorizontalVelocity(float vel) { horizontalSpeed = vel; }

void Being::setVerticalVelocity(float vel) { verticalSpeed = vel; }