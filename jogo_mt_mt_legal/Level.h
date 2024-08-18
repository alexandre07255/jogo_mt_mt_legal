#pragma once
#include "Camera.h"
#include <list>
#include "Collidable.h"
#include "Scene.h"

class Level: public Scene
{
protected:
	 //So that other objects can call methods and modify the updatables and drawables lists //Colocar aliveList e collidables aqui também
	list<Collidable*>* collidables;
	list<Alive*>* aliveList;
public:
	Level();
	virtual ~Level();
	

	//void loadLevel1(bool isPlayer2);
	//void loadLevel2(bool isPlayer2);
	//void loadMenu();

	enum active {
		LEVEL_1,
		LEVEL_2,
		MENU
	};
};

