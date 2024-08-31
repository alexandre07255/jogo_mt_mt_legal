#pragma once
#include "Command.h"
//#include "Menu.h"

class CommandSave : public Command
{
public:
	CommandSave(Scenes::Menu* _bound);
	~CommandSave();
	void execute();
};

