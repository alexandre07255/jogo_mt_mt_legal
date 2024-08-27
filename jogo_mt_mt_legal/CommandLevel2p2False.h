#pragma once
#include "Command.h"
//#include "Menu.h"


class CommandLevel2p2False : public Command
{
public:
	CommandLevel2p2False(Scenes::Menu* _bound);
	void execute();
};

