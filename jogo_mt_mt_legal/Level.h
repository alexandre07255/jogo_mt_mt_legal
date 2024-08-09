#pragma once
#include "EntityList.h"

class Level
{
private:
	EntityList* drawables;
	list<Updatable*>* updatables;
public:
	Level();
	~Level();
	void setDrawables(EntityList* drawlist);
	void setUpdatables(list<Updatable*>* updatelist);
	void draw(sf::RenderWindow* window);
	void update ();
};

