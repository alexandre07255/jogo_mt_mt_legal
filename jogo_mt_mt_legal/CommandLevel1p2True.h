#pragma once
#include "Command.h"
#include "Menu.h"

class CommandLevel1p2True : public Command
{
public:
	CommandLevel1p2True(Menu* _bound);
	void execute();
};

