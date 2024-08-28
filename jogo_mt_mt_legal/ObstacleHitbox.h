#pragma once
#include "Hitbox.h"
#include "Obstacle.h"
#include <list>

namespace Entities
{
	namespace Hitboxes
	{
		class ObstacleHitbox : public Hitbox
		{
		private:
			float verLaunchStrength;
			float horLaunchStrength;
			int damage;
			list<Entities::Characters::Hittable*> hitList;
			int cont;
			int cooldown;
			Entities::Obstacles::Obstacle* obstacle;
			const bool hasAlreadyHit(Entities::Characters::Hittable* pA);
		public:
			ObstacleHitbox(Entities::Obstacles::Obstacle* obs);
			~ObstacleHitbox();
			void ajustToRelativePosition();
			void setVerLaunchStrength(const float ver);
			void setHorLaunchStrength(const float hor);
			void setDamage(const int dmg);
			void setCooldown(const int cd);
			void execute();
			void save();
			void hitSolution(Entities::Characters::Hittable* hit);
		};
	}
}

