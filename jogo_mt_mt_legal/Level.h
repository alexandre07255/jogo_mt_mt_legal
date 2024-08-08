#pragma once
#include "EntityList.h"

class Level
{
private:
	EntityList* drawables;
	EntityList* updatables;
public:
	Level();
	~Level();
	void setDrawables(EntityList* drawlist);
	void setUpdatables(EntityList* updatelist);
	void draw(sf::RenderWindow* window);
	void update ();
};

