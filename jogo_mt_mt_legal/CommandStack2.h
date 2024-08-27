#pragma once
#include "Command.h"
//#include "Menu.h"

class CommandStack2 : public Command
{
public:
	CommandStack2(Scenes::Menu* _bound);
	void execute();

};

