#pragma once
#include <SFML/Graphics.hpp>

class Graphics {
private:
	sf::RenderWindow* window;
public:
	Graphics();
	~Graphics();
	const bool isWindowOpen();
	sf::RenderWindow* getWindow();
};