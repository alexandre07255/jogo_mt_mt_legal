#pragma once
#include "Command.h"
//#include "Menu.h"


class CommandLevel1p2True : public Command
{
public:
	CommandLevel1p2True(Scenes::Menu* _bound);
	~CommandLevel1p2True();
	void execute();
};

