#pragma once
#include <SFML/Graphics.hpp>

class Graphics {
private:
	sf::RenderWindow* window;
	static Graphics* instance;
public:
	Graphics();
	~Graphics();
	const bool isWindowOpen();
	sf::RenderWindow* getWindow();
	static Graphics* getInstance();
};