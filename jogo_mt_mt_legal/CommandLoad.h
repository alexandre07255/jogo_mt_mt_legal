#pragma once
#include "Command.h"
class CommandLoad : public Command
{
public:
	CommandLoad(Scenes::Menu* _bound);
	~CommandLoad();
	void execute();
};

