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
			void execute();
			void activate();
			void deactivate();
		};
	}
}

