#pragma once
#include "Enemy.h"

namespace Entities
{
	namespace Characters
	{
		class EnemyBoss : public Enemy
		{
		private:
			int tiredCont;
			int stompCont;
			int stompMax;
			bool triggered;
			int triggerRange;
			bool followingPlayer2;
			int attackPart;
			int attackTimer;
			int startup;
			int endLag;
			int frameCont;

			enum attackParts
			{
				GROUNDED,
				ASCENDING,
				DESCENDING
			};

			Player* pPlayer1;
			Player* pPlayer2;

			static const int TIREDNESS_DURATION;
			static const int ASCENSION_DURATION;
			static const float ASCENDING_VELOCITY;
			static const float DESCENDING_VELOCITY;

			void checkTrigger();
			void attack();
			void stopAttack();

			void executeGROUNDED();
			void executeASCENDING();
			void executeDESCENDING();
		public:
			EnemyBoss(Player* p1, Player* p2);
			~EnemyBoss();
			void execute();
			void save(LevelSave* save);
		};
	}
}

