#pragma once
#include "Entity.h"
#include "Command.h"

class Button : public Entity
{
private:
	sf::Mouse* mouse;
	sf::Color defaultColor;
	Command* com;
	bool repeatable;
public:
	bool clickable;
	Button(sf::Color col,Command* _com,bool repeat);
	const bool isMouseOn();
	void movement();
	const bool isMouseClicked();
};

