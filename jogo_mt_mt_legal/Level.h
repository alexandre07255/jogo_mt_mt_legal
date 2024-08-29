#pragma once
#include "Camera.h"
#include <list>
#include "Collidable.h"
#include "Scene.h"
#include "Support.h"
#include "Enemy.h"
#include "Obstacle.h"


namespace Scenes
{
	class Level : public Scene
	{
	protected:
		//So that other objects can call methods and modify the updatables and drawables lists //Colocar HittableList e collidables aqui também
		std::list<Collidable*>* collidables;
		std::list<Entities::Obstacles::Obstacle*>* obstacleList;
		std::vector<Entities::Characters::Enemy*>* enemyVector;
		std::vector<Entities::Support*>* supportVector;
		Entities::Characters::Player* pPlayer1;
		Entities::Characters::Player* pPlayer2;
		static const float SCALE;
		virtual void levelCompleteHandler() = 0;
		virtual void levelCompleteChecker() = 0;
		virtual void createFromScratch(const bool isPlayer2) = 0;
		virtual void loadTerrains() = 0;
		void manageCollisions();
	public:
		Level();
		virtual ~Level();

		void execute();
		void escResolver();

		list<Collidable*>* getCollidables();
		void removeCollidable(Collidable* pC);

		vector<Entities::Characters::Enemy*>* getEnemyVector();
		void addEnemy(Entities::Characters::Enemy* pE);
		void removeEnemy(Entities::Characters::Enemy* pE);

		vector<Entities::Support*>* getSupportVector();
		void addSupport(Entities::Support* pS);
		void removeSupport(Entities::Support* pS);

		Entities::Characters::Player* getPlayer1() const;
		Entities::Characters::Player* getPlayer2() const;

		void stackPauseMenu();

		void createEnemyMelee(const float x, const float y, const int points);
		void createEnemyRanged(const float x, const float y, const int points);
		void createEnemyBoss(const float x, const float y, const int points);

		void createPlatform(const float x, const float y, const float xSize, const float ySize);
		void createSpike(const float x, const float y, const float xSize, const float ySize);
		void createFire(const float x, const float y, const float xSize, const float ySize);

		void createTerrain(const float x, const float y, const float xSize, const float ySize, const float frict);

		void createPlayer1(const float x, const float y, const int points, const int hp);
		void createPlayer1(const float x, const float y, const int points);
		void createPlayer2(const float x, const float y, const int points, const int hp);
		void createPlayer2(const float x, const float y, const int points);

		//void loadLevel1(bool isPlayer2);
		//void loadLevel2(bool isPlayer2);
		//void loadMenu();
	};
}

