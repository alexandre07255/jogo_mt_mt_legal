#pragma once
#include "Hittable.h"
#include "Platform.h"

class Support : public Hittable
{
private:
	Platform* boundedTo;
	static int MAXHEALTH;
public:
	Support(Platform* plat);
	void setPlatform(Platform* plat);
	void movement();
};

