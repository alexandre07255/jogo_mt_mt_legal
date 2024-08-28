#pragma once
#include "Hittable.h"

namespace Entities
{
	namespace Hitboxes
	{
		class Hitbox : public Entity
		{
		protected:
			bool target;
			Entities::Characters::Hittable* owner;
			sf::Vector2f relativePosition;
			int duration;
		public:
			Hitbox();
			void setTarget(const bool tar);
			void setOwner(Hittable* own);
			Entities::Characters::Hittable* getOwner();
			void setRelativePosition(sf::Vector2f rel);
			void setDuration(const int dur);
			virtual void hitSolution(Hittable* hit) = 0;
		};
	}
}

