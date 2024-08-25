#pragma once
#include "Menu.h"

class PauseMenu : public Menu
{
private:
	Button* buttonQuit;
public:
	PauseMenu();
	void update();
};

