#include "GraphicManager.h"
#include <vector>
#include <iostream>

GraphicManager::GraphicManager() {
	sf::VideoMode video;
	std::vector< sf::VideoMode > modos = video.getFullscreenModes();
	window = new sf::RenderWindow (sf::VideoMode(modos[0].width, modos[0].height,modos[0].bitsPerPixel), "jogo");
}

GraphicManager::~GraphicManager() {
	delete window;
}

const bool GraphicManager::isWindowOpen(){
	if (window->isOpen())
		return true;
	return false;
}

sf::RenderWindow* GraphicManager::getWindow() {
	return window;
}

GraphicManager* GraphicManager::getInstance()
{
	if (instance == NULL)
		instance = new GraphicManager;
	return instance;	
}

GraphicManager* GraphicManager::instance(NULL);