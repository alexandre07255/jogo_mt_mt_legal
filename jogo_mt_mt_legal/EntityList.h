#pragma once
#include "List.h"
#include "Entity.h"

namespace Lists
{
	class EntityList
	{
	private:
		List<Entities::Entity> listEntities;
	public:
		EntityList();
		~EntityList();

		void push_back(Entities::Entity* pE);
		void traverse();
		void drawAll();

		void removeEntity(Entities::Entity* pE);

		int getSize();
	};
}

