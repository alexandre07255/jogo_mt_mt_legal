#pragma once
#include "Command.h"
//#include "Menu.h"

class CommandStart : public Command
{
public:
	CommandStart(Scenes::Menu* _bound);
	void execute();
};

