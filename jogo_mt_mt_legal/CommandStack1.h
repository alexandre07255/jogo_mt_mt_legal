#pragma once
#include "Command.h"
//#include "Menu.h"

class CommandStack1 : public Command
{
public:
	CommandStack1(Scenes::Menu* _bound);
	void execute();

};

