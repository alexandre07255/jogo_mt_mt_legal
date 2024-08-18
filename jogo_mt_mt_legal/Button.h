#pragma once
#include "MyDrawable.h"
class Button : public MyDrawable
{
private:
	sf::Mouse* mouse;
public:
	Button();
	const bool isMouseOn();
};

