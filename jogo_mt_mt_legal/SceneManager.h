#pragma once
#include "Scene.h"
#include <stack>

namespace Managers
{
	class SceneManager
	{
	private:
		static SceneManager* instance;
		stack<Scene*> scenes;
		sf::RenderWindow* window;
		SceneManager();
	public:
		static SceneManager* getInstance();
		void setWindow(sf::RenderWindow* pW);
		void push(Scene* pS);
		void pop();
		Scene* top() const;
		void step();
		int size();
	};
}

