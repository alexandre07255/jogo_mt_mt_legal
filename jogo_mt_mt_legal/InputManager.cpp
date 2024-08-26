#include "InputManager.h"

InputManager* InputManager::instance(NULL);

InputManager::InputManager():
	keyboard(new sf::Keyboard),
	mouse(new sf::Mouse),
	wasEscPressed(0),
	wasLMBPressed(0)
{

}

InputManager::~InputManager()
{
	delete keyboard;
	delete mouse;
	instance = NULL;
}

InputManager* InputManager::getInstance()
{
	if (instance == NULL)
		instance = new InputManager();
	return instance;
}

const bool InputManager::getWasLMBPressed() const
{
	return wasLMBPressed;
}

void InputManager::setWasLMBPressed(const bool lmb)
{
	wasLMBPressed = lmb;
}

const bool InputManager::getWasEscPressed() const
{
	return wasEscPressed;
}

void InputManager::setWasEscPressed(const bool wpp)
{
	wasEscPressed = wpp;
}

const bool InputManager::isKeyPressed(sf::Keyboard::Key key) { return keyboard->isKeyPressed(key); }

const bool InputManager::isUpPressed(bool player2)
{
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::Up);

	return keyboard->isKeyPressed(sf::Keyboard::Key::W);
}

const bool InputManager::isDownPressed(bool player2)
{
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::Down);

	return keyboard->isKeyPressed(sf::Keyboard::Key::S);
}

const bool InputManager::isRightPressed(bool player2) 
{
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::Right);

	return keyboard->isKeyPressed(sf::Keyboard::Key::D);
}

const bool InputManager::isLeftPressed(bool player2)
{
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::Left);

	return keyboard->isKeyPressed(sf::Keyboard::Key::A);
}

const bool InputManager::isAttackPressed(bool player2)
{
	if (player2)
		return keyboard->isKeyPressed(sf::Keyboard::Key::L);

	return keyboard->isKeyPressed(sf::Keyboard::Key::LShift);
}

const bool InputManager::isPausePressed() {
	return keyboard->isKeyPressed(sf::Keyboard::Escape);
}

sf::Mouse* InputManager::getMouse() const
{
	return mouse;
}