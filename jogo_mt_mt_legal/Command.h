#pragma once

class Menu;

class Command
{
protected:
	Menu* bound;
public:
	Command(Menu* _bound);
	virtual void execute() = 0;
};

