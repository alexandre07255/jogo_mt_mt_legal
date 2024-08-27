#pragma once
#include "Menu.h"

class Command
{
protected:
	Scenes::Menu* bound;
public:
	Command(Scenes::MainMenu* _bound);
	virtual void execute() = 0;
};

