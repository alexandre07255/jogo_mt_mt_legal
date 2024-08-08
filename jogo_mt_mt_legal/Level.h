#pragma once
#include "EntityList.h"

class Level
{
private:
	EntityList* drawables;
	EntityList* updatables;
public:
	Level();
	void setDrawables(EntityList* )
};

