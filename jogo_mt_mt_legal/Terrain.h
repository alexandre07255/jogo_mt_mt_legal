#pragma once
#include "Collidable.h"

namespace Entities
{
	class Terrain : public Collidable, public MyDrawable
	{
	public:
		Terrain(float frict);
		virtual sf::FloatRect getBounds();
		void collisionSolution(Entity* pE);
	};
}

