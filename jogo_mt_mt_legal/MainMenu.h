#pragma once
#include "Menu.h"
class MainMenu : public Menu
{
private:
	Button* level1Button;
	Button* player2True;
	Button* player2False;
public:
	MainMenu();
	void update();
	void stackLevel1(bool player2);
	void moreButtons();
};

