#pragma once
#include "List.h"
#include "MyDrawable.h"
#include "Updatable.h"

namespace Scenes
{
	class Scene
	{
	protected:
		List<MyDrawable>* drawables;
		List<Updatable>* updatables;
	public:
		Scene();
		void draw(sf::RenderWindow* window);
		virtual void update();
		void setDrawables(List<MyDrawable>* drawlist);
		List<MyDrawable>* getDrawables() const;
		void setUpdatables(List<Updatable>* updatelist);
		List<Updatable>* getUpdatables() const;
		void addUpdatable(Updatable* pU);
		void addDrawable(MyDrawable* pD);
		void removeDrawable(MyDrawable* pD);
		void removeUpdatable(Updatable* pU);
	};
}

