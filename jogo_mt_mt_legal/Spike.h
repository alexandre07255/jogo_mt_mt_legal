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
			void movement();
			void activate();
			void deactivate();
		};
	}
}

