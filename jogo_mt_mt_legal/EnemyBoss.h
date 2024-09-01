#pragma once
#include "Enemy.h"

namespace Entities { namespace Hitboxes { class AttackHitbox; } }

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
			float triggerRange;
			bool followingPlayer2;
			int attackPart;
			int attackTimer;
			bool attacking;
			int startup;
			int endLag;

			enum attackParts
			{
				GROUNDED,
				ASCENDING,
				DESCENDING
			};

			Player* targetPlayer[2];
			Hitboxes::AttackHitbox* hitboxes[2];

			static const int TIREDNESS_DURATION;
			static const int ASCENSION_DURATION;
			static const float HORIZONTAL_VELOCITY;
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

			bool getTriggered()const;
			void setTriggered(const bool trig);
		};
	}
}

