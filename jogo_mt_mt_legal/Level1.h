#pragma once
#include "Level.h"

namespace Scenes
{
	class Level1 : public Level
	{
	private:
		bool endingOnRight;
		float endX;
		void levelCompleteHandler();
		void levelCompleteChecker();
		void createFromScratch(const bool isPlayer2);
		void loadTerrains();
	public:
		Level1(bool isPlayer2,bool isBeingLoaded);
		~Level1();
	};
}

