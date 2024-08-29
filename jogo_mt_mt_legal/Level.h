#pragma once
#include "Camera.h"
#include <list>
#include "Collidable.h"
#include "Scene.h"
#include "Support.h"
#include "Enemy.h"


namespace Scenes
{
	class Level : public Scene
	{
	protected:
		//So that other objects can call methods and modify the updatables and drawables lists //Colocar HittableList e collidables aqui também
		std::list<Collidable*>* collidables;
		std::vector<Entities::Characters::Enemy*>* enemyVector;
		std::vector<Entities::Support*>* supportVector;
		Entities::Characters::Player* pPlayer1;
		Entities::Characters::Player* pPlayer2;
		bool endingOnRight;
		float endX;
		virtual void levelCompleteHandler() = 0;
		void manageCollisions();
	public:
		Level();
		virtual ~Level();

		void excute();

		list<Collidable*>* getCollidables();
		void removeCollidable(Collidable* pC);

		vector<Entities::Characters::Enemy*>* getEnemyVector();
		void addEnemy(Entities::Characters::Enemy* pE);
		void removeEnemy(Entities::Characters::Enemy* pE);

		vector<Entities::Support*>* getSupportVector();
		void addSupport(Entities::Support* pS);
		void removeSupport(Entities::Support* pS);

		void stackPauseMenu();

		void createEnemyMelee(const float x, const float y, const int points);
		void createEnemyRanged(const float x, const float y, const int points);
		void createEnemyBoss(const float x, const float y, const int points);

		void createPlatform(const float x, const float y, const float xSize, const float ySize);
		void createSpike(const float x, const float y, const float xSize, const float ySize);
		void createFire(const float x, const float y, const float xSize, const float ySize);

		void save();


		//void loadLevel1(bool isPlayer2);
		//void loadLevel2(bool isPlayer2);
		//void loadMenu();
	};
}

