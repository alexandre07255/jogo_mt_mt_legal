#pragma once
#include "TextContainer.h"
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
		void loadTerrains();Entities::TextContainer* player1Hp;
		Entities::TextContainer* player2Hp;
	public:
		Level2(bool isPlayer2,bool isBeingLoaded, int p1Points = 0, int p2Points = 0);
		~Level2();
		void setIsBossAlive(const bool ba);
	};
}

