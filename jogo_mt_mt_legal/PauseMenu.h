#pragma once
#include "Menu.h"
#include "Button.h"
#include "Level.h"

namespace Scenes
{
	class PauseMenu : public Menu
	{
	private:
		Level* levelActive;
	public:
		PauseMenu(Level* lAct);
		~PauseMenu();
		void escResolver();

		void save();
	};
}

