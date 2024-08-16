#pragma once
#include "Camera.h"
#include <list>

class Level
{
private:
	static Level* active; //So that other objects can call methods and modify the updatables and drawables lists
	list<MyDrawable*>* drawables;
	list<Updatable*>* updatables; //Colocar aliveList e collidables aqui tamb�m
	list<Collidable*>* collidables;
	list<Alive*>* aliveList;
public:
	Level(bool isPlayer2, int activeCase);
	~Level();
	static Level* getActive();
	static void setActive(Level* pL);
	void setDrawables(list<MyDrawable*>* drawlist);
	list<MyDrawable*>* getDrawables() const;
	void setUpdatables(list<Updatable*>* updatelist);
	list<Updatable*>* getUpdatables() const;
	void addUpdatable(Updatable* pU);
	void draw(sf::RenderWindow* window);
	void update ();
	void addDrawable(Entity* pD);

	void loadLevel1(bool isPlayer2);
	void loadLevel2(bool isPlayer2);
	void loadMenu();

	enum active {
		LEVEL_1,
		LEVEL_2,
		MENU
	};
};

