#pragma once
#include "Entity.h"
class Button : public Entity
{
private:
	sf::Mouse* mouse;
public:
	Button();
	const bool isMouseOn();
	void movement();
	const bool isMouseClicked();
};

