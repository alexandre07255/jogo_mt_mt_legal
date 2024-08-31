#pragma once
#include "Command.h"
//#include "Menu.h"

class CommandLevel1p2False : public Command
{
public:
	CommandLevel1p2False(Scenes::Menu* _bound);
	~CommandLevel1p2False();
	void execute();
};

