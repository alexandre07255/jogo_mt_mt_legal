#pragma once
#include "Obstacle.h"
#include "Collidable.h"
#include "Support.h"

namespace Entities { namespace Hitboxes { class ObstacleHitbox; } }


namespace Entities
{
	namespace Obstacles
	{
		class Platform :public Obstacle, public Collidable
		{
		private:
			Support* support;

			Hitboxes::ObstacleHitbox* hitboxRight;

			bool firstStep;
			const float minimalHeight;
		public:
			Platform(float xPosition, float yPosition, float xSize, float ySize);
			~Platform();
			sf::FloatRect getBounds();
			void toObstacle();
			void execute();
			Support* getSupport();
			void collisionSolution(Entity* pE);
			void save(LevelSave* save);
		};
	}
}

