#pragma once
#include "Entity.h"
#include "Command.h"

class Button : public Entities::Entity
{
private:
	sf::Mouse* mouse;
	sf::Texture* defaultTexture;
	sf::Color defaultColor;
	Command* com;
	bool repeatable;
public:
	bool clickable;
	Button(sf::Color col, Command* _com, bool repeat);
	~Button();
	const bool isMouseOn();
	void execute();
	const bool isMouseClicked();
	void save(LevelSave* save);
};


