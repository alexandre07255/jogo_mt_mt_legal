#include "inputManager.h"


inputManager::inputManager():
	keyboard(new sf::Keyboard),
	mouse(new sf::Mouse)
{

}

inputManager::~inputManager()
{
	delete keyboard;
	delete mouse;
	instance = NULL;
}

inputManager* inputManager::getInstance()
{
	if (instance == NULL)
		instance = new inputManager();
	return instance;
}

const bool inputManager::isKeyPressed(sf::Keyboard::Key key) { return keyboard->isKeyPressed(key); }

const bool inputManager::isUpPressed(bool player2)
{

}

const bool inputManager::isDownPressed(bool player2);

const bool inputManager::isRightPressed(bool player2);

const bool inputManager::isLeftPressed(bool player2);

const bool inputManager::isAttackPressed(bool player2);

const bool inputManager::isPausePressed();
