#pragma once
#include "Obstacle.h"
#include "ObstacleHitbox.h"

namespace Entities
{
	namespace Obstacles
	{
		class Fire : public Obstacle
		{
		private:
			int lingeringTime;
		public:
			Fire();
			~Fire();
			void execute();
			void statusEffect(Characters::Hittable* hit);
			void setLingeringTime(const int time);
			void activate();
			void deactivate();
			void toObstacle();
			void save(LevelSave* save);
		};
	}
}

