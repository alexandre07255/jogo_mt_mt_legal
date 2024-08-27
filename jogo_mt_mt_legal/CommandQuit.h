#pragma once
#include "Command.h"
//#include "Menu.h"

class CommandQuit : public Command
{
public:
	CommandQuit(Scenes::Menu* _bound);
	void execute();
};

