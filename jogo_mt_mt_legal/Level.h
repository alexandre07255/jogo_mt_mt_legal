#pragma once
#include "Camera.h"
#include "List.h"
#include "Collidable.h"
#include "Scene.h"

class Level: public Scene
{
protected:
	 //So that other objects can call methods and modify the updatables and drawables lists //Colocar HittableList e collidables aqui tamb�m
	List<Collidable>* collidables;
	List<Hittable>* hittableList;
	Player* pPlayer1;
	Player* pPlayer2;
	bool endingOnRight;
	float endX;
	virtual void levelCompleteHandler() = 0;
public:
	Level();
	virtual ~Level();
	void update();
	List<Collidable>* getCollidable();
	void addHittable(Hittable* pH);
	List<Hittable>* getHittableList();
	void removeHittable(Hittable* pH);
	void removeCollidable(Collidable* pC);

	//void loadLevel1(bool isPlayer2);
	//void loadLevel2(bool isPlayer2);
	//void loadMenu();

	enum active {
		LEVEL_1,
		LEVEL_2,
		MENU
	};
};

