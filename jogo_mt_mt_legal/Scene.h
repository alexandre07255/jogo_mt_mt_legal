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
		void execute();

		void addEntity(Entities::Entity* pU);
		void removeEntity(Entities::Entity* pU);

		void setEntityList(Lists::EntityList* list);

		virtual void escResolver() = 0;
	};
}

