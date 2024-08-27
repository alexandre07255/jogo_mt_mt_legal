#pragma once
#include "Hitbox.h"
#include "Collidable.h"
#include "List.h"
#include "Player.h"

namespace Managers
{
	class CollisionManager
	{
	private:
		static CollisionManager* instance;
		CollisionManager();
	public:
		static CollisionManager* getInstance();
		~CollisionManager();
		void testCollison(Entity* pE);
		void testHittableCollision(Entities::Characters::Hittable* target);
		const bool isColliding(sf::FloatRect one, sf::FloatRect other);
		void testHit(const bool target, Entities::Hitboxes::Hitbox* hitbox);
		float nearestCollidable(MyDrawable* relativeTo, float maxHeight) const;
	};
}

