#pragma once
#include "Level.h"

namespace Scenes
{
	class Level2 : public Level
	{
	private:
		bool isBossAlive;
		void levelCompleteHandler();
		void levelCompleteChecker();
		void createFromScratch(const bool isPlayer2);
		void loadTerrains();
	public:
		Level2(bool isPlayer2,bool isBeingLoaded);
		~Level2();
		void setIsBossAlive(const bool ba);
	};
}

