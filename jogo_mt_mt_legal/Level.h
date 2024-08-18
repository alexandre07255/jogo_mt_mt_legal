#pragma once
#include "Camera.h"
#include <list>
#include "Collidable.h"
#include "Scene.h"

class Level: public Scene
{
protected:
	static Level* active; //So that other objects can call methods and modify the updatables and drawables lists //Colocar aliveList e collidables aqui tamb�m
	list<Collidable*>* collidables;
	list<Alive*>* aliveList;
	Player* pPlayer1;
	Player* pPlayer2;
	bool endingOnRight;
	float endX;
	virtual void levelCompleteHandler() = 0;
public:
	Level();
	virtual ~Level();
	static Level* getActive();
	static void setActive(Level* pL);

	//void loadLevel1(bool isPlayer2);
	//void loadLevel2(bool isPlayer2);
	//void loadMenu();

	enum active {
		LEVEL_1,
		LEVEL_2,
		MENU
	};
};

