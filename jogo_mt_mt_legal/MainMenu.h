#pragma once
#include "Menu.h"
class MainMenu : public Menu
{
private:
	Button* level1Button;
public:
	MainMenu();
	void update();
	void stackLevel1();
};

