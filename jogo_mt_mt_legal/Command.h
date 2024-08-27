#pragma once
#include "Menu.h"
//class Menu;

class Command
{
protected:
	Scenes::Menu* bound;
public:
	Command(Scenes::Menu* _bound);
	virtual void execute() = 0;
};

