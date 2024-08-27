#pragma once
#include "Scene.h"
#include <vector>
#include <list>

class MainMenu : public Scenes::Scene
{
private:
	//primeiro � my menu, segundo � start, terceiro � options e assim vai
	vector<EntityList> versions;
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

