#pragma once
#include "Entity.h"
#include "Command.h"

class Button : public Entities::Entity
{
private:
	sf::Mouse* mouse;
	sf::Color defaultColor;
	Command* com;
	bool repeatable;
public:
	bool clickable;
	Button(sf::Color col, Command* _com, bool repeat, const int matriIndex);
	~Button();
	const bool isMouseOn();
	void execute();
	const bool isMouseClicked();
	void save(LevelSave* save);
};


