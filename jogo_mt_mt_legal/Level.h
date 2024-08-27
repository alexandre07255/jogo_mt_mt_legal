#pragma once
#include "Camera.h"
#include "List.h"
#include "Collidable.h"
#include "Scene.h"

namespace Scenes
{
	class Level : public Scene
	{
	protected:
		//So that other objects can call methods and modify the updatables and drawables lists //Colocar HittableList e collidables aqui também
		list<Collidable*>* collidables;
		list<Entities::Characters::Hittable*>* hittableList;
		Entities::Characters::Player* pPlayer1;
		Entities::Characters::Player* pPlayer2;
		bool endingOnRight;
		float endX;
		virtual void levelCompleteHandler() = 0;
	public:
		Level();
		virtual ~Level();
		void update();
		list<Collidable*>* getCollidable();
		void addHittable(Entities::Characters::Hittable* pH);
		list<Entities::Characters::Hittable*>* getHittableList();
		void removeHittable(Entities::Characters::Hittable* pH);
		void removeCollidable(Collidable* pC);

		void stackPauseMenu();

		//void loadLevel1(bool isPlayer2);
		//void loadLevel2(bool isPlayer2);
		//void loadMenu();
	};
}

