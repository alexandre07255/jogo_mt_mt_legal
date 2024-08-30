#pragma once
#include "Command.h"
//#include "Menu.h"

class CommandLevel2p2True : public Command
{
public:
	CommandLevel2p2True(Scenes::Menu* _bound);
	~CommandLevel2p2True();
	void execute();
};

