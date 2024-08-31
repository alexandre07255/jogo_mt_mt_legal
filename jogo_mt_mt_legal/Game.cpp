#include "Game.h"
using namespace Managers;
using namespace Scenes;

void Game::createManagers()
{
	pGM = GraphicManager::getInstance();
	pSM = SceneManager::getInstance();
}

void Game::createMenu()
{
	pSM->push(new MainMenu);
}

Game::Game():
	pGM(NULL),
	pSM(NULL)
{
	createManagers();
	createMenu();
}
Game::~Game()
{
	delete pGM;
	delete pSM;
}
void Game::run()
{
	sf::RenderWindow* window = pGM->getWindow();

	window->setFramerateLimit(60);
	//window->setVerticalSyncEnabled(true);

	pSM->setWindow(window);
	while (pGM->isWindowOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		pSM->step();
	}
}