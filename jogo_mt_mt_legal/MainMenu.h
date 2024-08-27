#pragma once
#include "Menu.h"
#include <vector>
#include <list>

namespace Scenes
{
	class MainMenu : public Menu
	{
	private:
		//primeiro é my menu, segundo é start, terceiro é options e assim vai
		vector<list<Updatable*>*>* updatableVersions;
		vector<list<MyDrawable*>*>* myDrawableVersions;
		vector<list<Button*>*>* buttonVersions;
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
}

