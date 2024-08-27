#pragma once
#include "Scene.h"
#include "SceneManager.h"

namespace Scenes{
	class Menu : public Scene
	{
	protected:
		static Managers::SceneManager* pSmanager;
	public:
		Menu();
		virtual ~Menu();

		void stackScene(Scene* pS);
		void removeScene();
	};
}

