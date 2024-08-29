#pragma once
#include "Command.h"
class CommandGoBack : public Command
{
public:
	CommandGoBack(Scenes::Menu* _bound);
	void execute();
};

