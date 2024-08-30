#pragma once
#include "Scene.h"
#include <stack>

namespace Managers
{
	class SceneManager
	{
	private:
		static SceneManager* instance;
		stack<Scenes::Scene*> scenes;
		sf::RenderWindow* window;
		SceneManager();
	public:
		~SceneManager();
		static SceneManager* getInstance();
		void setWindow(sf::RenderWindow* pW);
		void push(Scenes::Scene* pS);
		void pop();
		Scenes::Scene* top() const;
		void step();
		int size();
	};
}

