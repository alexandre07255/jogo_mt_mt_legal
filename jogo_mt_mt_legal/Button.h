#pragma once
#include "Entity.h"
class Button : public Entity
{
private:
	sf::Mouse* mouse;
	int action;
public:
	enum Actions
	{
		startLevel1,
		startLevel2
	};
	Button(const int act);
	const int getAction() const;
	const bool isMouseOn();
	void movement();
	const bool isMouseClicked();
};

