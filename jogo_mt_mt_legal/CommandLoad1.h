#pragma once
#include "Command.h"
class CommandLoad1 : public Command
{
public:
	CommandLoad1(Scenes::Menu* _bound);
	void execute();
};

