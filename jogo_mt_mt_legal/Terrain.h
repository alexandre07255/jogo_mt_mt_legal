#pragma once
#include "Collidable.h"
class Terrain : public Collidable, public MyDrawable
{
public:
	Terrain();
	virtual sf::FloatRect getBounds();
};

