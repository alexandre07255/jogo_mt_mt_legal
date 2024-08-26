#pragma once
#include "Command.h"
class CommandSave : public Command
{
public:
	CommandSave(Menu* _bound);
	void execute();
};

