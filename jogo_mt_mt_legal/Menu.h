#pragma once
#include "Scene.h"
#include "SceneManager.h"

namespace Scenes{
	class Menu : public Scene
	{
	private:
		static Managers::SceneManager* pSmanager;
	public:
		Menu();
		virtual ~Menu();

		void stackScene(Scene* pS);
		void removeScene();
	};
}

