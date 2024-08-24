#pragma once
#include "Entity.h"
class Button : public Entity
{
private:
	sf::Mouse* mouse;
	int action;
	sf::Color defaultColor;
public:
	bool clickable;
	enum Actions
	{
		startLevel1,
		startLevel2,
		player2True,
		player2False
	};
	Button(const int act,sf::Color col);
	const int getAction() const;
	const bool isMouseOn();
	void movement();
	const bool isMouseClicked();
};

