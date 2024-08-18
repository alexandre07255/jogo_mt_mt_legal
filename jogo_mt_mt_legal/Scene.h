#pragma once
#include <list>
#include "Entity.h"

class Scene
{
protected:
	list<MyDrawable*>* drawables;
	list<Updatable*>* updatables;
public:
	Scene();
	void draw(sf::RenderWindow* window);
	virtual void update();
	void setDrawables(list<MyDrawable*>* drawlist);
	list<MyDrawable*>* getDrawables() const;
	void setUpdatables(list<Updatable*>* updatelist);
	list<Updatable*>* getUpdatables() const;
	void addUpdatable(Updatable* pU);
	void addDrawable(Entity* pD);
};

