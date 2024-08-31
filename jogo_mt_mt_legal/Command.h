#pragma once
#include "Menu.h"

class Command
{
protected:
	Scenes::Menu* bound;
public:
	Command(Scenes::Menu* _bound);
	virtual ~Command();
	virtual void execute() = 0;
};

