#pragma once
#include "EntityList.h"

namespace Scenes
{
	class Scene: public Being
	{
	protected:
		Lists::EntityList* entityList;
	public:
		Scene();

		void draw();
		virtual void update() = 0;

		void addEntity(Entities::Entity* pU);
		void removeEntity(Entities::Entity* pU);
	};
}

