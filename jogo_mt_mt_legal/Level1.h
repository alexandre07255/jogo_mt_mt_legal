#pragma once
#include "Level.h"
#include "TextContainer.h"

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
		Entities::TextContainer* player1Hp;
		Entities::TextContainer* player2Hp;
	public:
		Level1(bool isPlayer2,bool isBeingLoaded);
		~Level1();
		Entities::TextContainer* getTextContainer(bool isPlayer2);
	};
}

