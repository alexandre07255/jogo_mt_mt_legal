#pragma once
#include "Command.h"
class CommandLoad2 : public Command
{
public:
	CommandLoad2(Scenes::Menu* _bound);
	~CommandLoad2();
	void execute();
};

