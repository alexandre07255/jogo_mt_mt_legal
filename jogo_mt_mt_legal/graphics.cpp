#include "graphics.h"
#include <vector>
#include <iostream>

Graphics::Graphics() {
	sf::VideoMode video;
	std::vector< sf::VideoMode > modos = video.getFullscreenModes();
	window = new sf::RenderWindow (sf::VideoMode(modos[0].width, modos[0].height,modos[0].bitsPerPixel), "jogo");
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

Graphics* Graphics::getInstance()
{
	if (instance == NULL)
		instance = new Graphics;
	return instance;	
}

Graphics* Graphics::instance(NULL);