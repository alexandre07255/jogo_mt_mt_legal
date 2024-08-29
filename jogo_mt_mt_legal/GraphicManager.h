#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace Managers {
	class GraphicManager {
	private:
		sf::RenderWindow* window;
		static GraphicManager* instance;
	public:
		GraphicManager();
		~GraphicManager();
		const bool isWindowOpen();
		sf::RenderWindow* getWindow();
		void drawBeing(Being* pE);
		void drawText(sf::Text text);
		static GraphicManager* getInstance();
	};
}