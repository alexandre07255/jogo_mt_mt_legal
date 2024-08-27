#pragma once
#include <SFML/Graphics.hpp>

namespace Managers
{
	class GraphicManager {
	private:
		sf::RenderWindow* window;
		static GraphicManager* instance;
	public:
		GraphicManager();
		~GraphicManager();
		const bool isWindowOpen();
		sf::RenderWindow* getWindow();
		static GraphicManager* getInstance();
	};
}
