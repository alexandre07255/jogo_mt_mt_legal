#pragma once
#include "Command.h"

class CommandStart : public Command
{
public:
	CommandStart(Menu* _bound);
	void execute();
};

