#pragma once
#include <SFML/Window.hpp>

class InputManager //Classe Singleton e Observed :3 berunyan
{
private:
	static InputManager* instance;
	sf::Keyboard* keyboard;
	sf::Mouse* mouse;
	InputManager();
public:
	~InputManager();
	static InputManager* getInstance();
	const bool isKeyPressed(sf::Keyboard::Key key);
	const bool isUpPressed(bool player2);
	const bool isDownPressed(bool player2);
	const bool isRightPressed(bool player2);
	const bool isLeftPressed(bool player2);
	const bool isAttackPressed(bool player2);
	const bool isPausePressed();
};

