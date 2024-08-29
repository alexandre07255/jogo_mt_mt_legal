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
			void setOwner(Entities::Characters::Hittable* own);
			void save();
			Entities::Characters::Hittable* getOwner();
			void setRelativePosition(sf::Vector2f rel);
			void setDuration(const int dur);
			virtual void hitSolution(Entities::Characters::Hittable* hit) = 0;
			void save(LevelSave* save);
		};
	}
}

