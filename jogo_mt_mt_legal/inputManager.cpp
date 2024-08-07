#include "inputManager.h"

inputManager* inputManager::instance(NULL);

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
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::Up);

	return keyboard->isKeyPressed(sf::Keyboard::Key::W);
}

const bool inputManager::isDownPressed(bool player2)
{
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::Down);

	return keyboard->isKeyPressed(sf::Keyboard::Key::S);
}

const bool inputManager::isRightPressed(bool player2) 
{
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::Right);

	return keyboard->isKeyPressed(sf::Keyboard::Key::D);
}

const bool inputManager::isLeftPressed(bool player2)
{
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::Left);

	return keyboard->isKeyPressed(sf::Keyboard::Key::A);
}

const bool inputManager::isAttackPressed(bool player2)
{
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::LControl);

	return mouse->isButtonPressed(sf::Mouse::Left);
}

const bool inputManager::isPausePressed() {
	return keyboard->isKeyPressed(sf::Keyboard::Escape);
}
