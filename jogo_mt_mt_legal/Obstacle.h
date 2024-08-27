#pragma once
#include "Entity.h"
#include "Hittable.h"

namespace Entities
{
	namespace Obstacles
	{
		class Obstacle : public Entity
		{
		protected:
			bool isActive;
			bool spawnedHitbox;
		public:
			Obstacle();
			const bool getIsActive() const;
			virtual void statusEffect(Entities::Characters::Hittable* hit);
			void setIsActive(const bool active);
			void setSpawnedHitbox(const bool spa);
		};
	}
}

