#pragma once
#include "Obstacle.h"
#include "Collidable.h"
#include "Support.h"
#include "ObstacleHitbox.h"


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
			float mass;
			int time;
			float defaultY;
			float deformation;
			bool onTop;
			float HarmonicMovement(float range, float mass, float elasticity, float damping, float time);
		public:
			Platform(float xPosition, float yPosition, float xSize, float ySize);
			sf::FloatRect getBounds();
			void toObstacle();
			void execute();
			Support* getSupport();
			void collisionSolution(Entity* pE);
			void save();
		};
	}
}

