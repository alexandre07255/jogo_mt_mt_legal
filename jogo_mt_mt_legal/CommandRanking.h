#pragma once
#include "Command.h"

class CommandRanking : public Command
{
public:
	CommandRanking(Scenes::Menu* _bound);
	~CommandRanking();
	void execute();
};

