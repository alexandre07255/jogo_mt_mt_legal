#pragma once
#include <SFML/Window.hpp>

class inputManager //Classe Singleton e Observed :3 berunyan
{
private:
	static inputManager* instance;
	sf::Keyboard* keyboard;
	sf::Mouse* mouse;
	inputManager();
public:
	~inputManager();
	static inputManager* getInstance();
	const bool isKeyPressed(sf::Keyboard::Key key);
	const bool isUpPressed(bool player2);
	const bool isDownPressed(bool player2);
	const bool isRightPressed(bool player2);
	const bool isLeftPressed(bool player2);
	const bool isAttackPressed(bool player2);
	const bool isPausePressed();
};

