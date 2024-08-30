#pragma once
#include "Obstacle.h"

namespace Entities
{
	namespace Obstacles
	{
		class Spike : public Obstacle
		{
		private:
			bool firstStep;
		public:
			Spike();
			~Spike();
			void execute();
			void activate();
			void deactivate();
			void toObstacle();

			void save(LevelSave* save);
		};
	}
}

