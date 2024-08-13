#pragma once
#include "EntityList.h"
#include "Camera.h"

class Level
{
private:
	static Level* active; //So that other objects can call methods and modify the updatables and drawables lists
	EntityList* drawables;
	list<Updatable*>* updatables; //Colocar aliveList e collidables aqui também
public:
	Level();
	~Level();
	static Level* getActive();
	static void setActive(Level* pL);
	void setDrawables(EntityList* drawlist);
	EntityList* getDrawables() const;
	void setUpdatables(list<Updatable*>* updatelist);
	list<Updatable*>* getUpdatables() const;
	void addUpdatable(Updatable* pU);
	void draw(sf::RenderWindow* window);
	void update ();
};

