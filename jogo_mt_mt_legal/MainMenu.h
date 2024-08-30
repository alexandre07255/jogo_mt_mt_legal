#pragma once
#include "Menu.h"
#include <vector>
#include <list>

namespace Scenes
{
	class MainMenu : public Menu
	{
	private:
		//primeiro é my menu, segundo é start, terceiro é ranking e assim vai
		vector<Lists::EntityList*> versions;
		int version;
	public:
		MainMenu();
		~MainMenu();

		void stackLevel1(bool player2);
		void stackLevel2(bool player2);

		void changeMainButtons();
		void changeStartButtons();
		void changeRanking();
		void changeLoadButtons();

		void goBack();
		void moreButtons(bool level2);

		void escResolver();

		void load(bool level2);
	};
}

