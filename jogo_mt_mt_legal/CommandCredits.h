#pragma once
#include"Command.h"
class CommandCredits:public Command
{
public:
	CommandCredits(Scenes::Menu* _bound);
	void execute();
};

