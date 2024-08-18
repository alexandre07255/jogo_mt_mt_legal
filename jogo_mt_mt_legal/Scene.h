#pragma once
#include <list>
#include "MyDrawable.h"
#include "Updatable.h"

class Scene
{
protected:
	static Scene* active;
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
	void addDrawable(MyDrawable* pD);
	static Scene* getActive();
	static void setActive(Scene* pL);
};

