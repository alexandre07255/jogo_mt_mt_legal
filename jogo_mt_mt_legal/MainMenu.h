#pragma once
#include "Menu.h"
#include <vector>

class MainMenu : public Menu
{
private:
	//primeiro é my menu, segundo é start, terceiro é options e assim vai
	vector<List<Updatable>*>* updatableVersions;
	vector<List<MyDrawable>*>* myDrawableVersions;
	vector<List<Button>*>* buttonVersions;
	int version;
public:
	MainMenu();
	void update();
	void stackLevel1(bool player2);
	void stackLevel2(bool player2);
	void changeMainButtons();
	void changeStartButtons();
	void changeOptionsButtons();
	void goBack();
	void moreButtons(bool level2);
};

