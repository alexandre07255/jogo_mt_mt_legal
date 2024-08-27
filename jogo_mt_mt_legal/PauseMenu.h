#pragma once
#include "Menu.h"

namespace Scenes
{
	class PauseMenu : public Menu
	{
	private:
		Button* buttonQuit;
		Button* buttonSave;
	public:
		PauseMenu();
		void update();
	};
}

