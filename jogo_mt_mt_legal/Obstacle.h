#pragma once
#include "Hittable.h"


namespace Entities { namespace Hitboxes { class ObstacleHitbox; } }


namespace Entities
{
	namespace Obstacles
	{
		class Obstacle : public Entity
		{
		protected:
			bool isActive;
			bool spawnedHitbox;
			Hitboxes::ObstacleHitbox* hitbox;
		public:
			Obstacle();
			virtual ~Obstacle();
			const bool getIsActive() const;
			virtual void toObstacle() = 0;
			virtual void statusEffect(Entities::Characters::Hittable* hit);
			void setIsActive(const bool active);
			void setSpawnedHitbox(const bool spa);
		};
	}
}

