#pragma once
#include "Menu.h"

class PauseMenu : public Menu
{
private:
	Button* buttonQuit;
	Button* buttonSave;
public:
	PauseMenu();
	void update();
};

