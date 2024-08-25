#pragma once
#include "Command.h"

class CommandQuit : public Command
{
public:
	CommandQuit(Menu* _bound);
	void execute();
};

