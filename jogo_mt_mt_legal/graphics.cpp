#include "graphics.h"

Graphics::Graphics() {
	window = new sf::RenderWindow (sf::VideoMode(200, 200), "jogo");
}

Graphics::~Graphics() {
	delete window;
}

const bool Graphics::isWindowOpen(){
	if (window->isOpen())
		return true;
	return false;
}

sf::RenderWindow* Graphics::getWindow() {
	return window;
}