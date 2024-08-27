#pragma once
#include "Level.h"

namespace Scenes
{
	class Level1 : public Level
	{
	private:
		void levelCompleteHandler();
	public:
		Level1(bool isPlayer2);
		~Level1();
	};
}

