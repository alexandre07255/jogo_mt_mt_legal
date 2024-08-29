#pragma once
#include "Collidable.h"

namespace Entities
{
	class Terrain : public Collidable, public Entity
	{
	public:
		Terrain(float frict);
		void execute();
		virtual sf::FloatRect getBounds();
		void collisionSolution(Entity* pE);

		void save(LevelSave* save);
	};
}

