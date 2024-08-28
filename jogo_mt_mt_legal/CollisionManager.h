#pragma once
#include "Hitbox.h"
#include "Collidable.h"
#include <list>
#include <vector>
#include "Enemy.h"
#include "Obstacle.h"
#include "Support.h"


namespace Managers
{
	class CollisionManager
	{
	private:
		static CollisionManager* instance;
		Entities::Characters::Player* player1;
		Entities::Characters::Player* player2;
		std::vector<Entities::Characters::Enemy*>* enemyVector;
		std::vector<Entities::Support*>* supportVector;
		std::list<Collidable*>* collidables;
		std::list<Entities::Obstacles::Obstacle*>* obstaclelist;
		CollisionManager();
	public:
		static CollisionManager* getInstance();
		~CollisionManager();
		void testHittableToObstacleCollisions();
		void testPlayerToEnemyCollision();
		void testHittableToCollidableCollisions();
		void testCollison(Entities::Entity* pE);
		const bool isColliding(sf::FloatRect one, sf::FloatRect other);
		void testHit(const bool target, Entities::Hitboxes::Hitbox* hitbox);
		float nearestCollidable(Entities::Entity* relativeTo, float maxHeight) const;
	};
}

