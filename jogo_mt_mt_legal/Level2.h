#pragma once
#include "Level.h"

namespace Scenes
{
	class Level2 : public Level
	{
	private:
		void levelCompleteHandler();
	public:
		Level2(bool isPlayer2);
		~Level2();
	};
}

