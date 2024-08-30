#pragma once
#include "Enemy.h"
#include "Player.h"

namespace Entities
{
	namespace Characters
	{
		class EnemyMelee : public Enemy
		{
		private:
			int walkingBuffer;
			int waitBuffer;
			bool direction;
			bool attacking;

			const int attackStartup;
			const int attackHitboxDuration;
			const int attackEndLag;
			const float attackTriggerRange;
			const float attackTriggerYRange;

			static const float JUMP_STRENGTH;
			static const float FOLLOW_MAX_HORIZONTAL_VELOCITY;
			static const float FOLLOW_ACCELARATION;
			static const float WALK_ACCELARATION;
			static const float WALK_MAX_HORIZONTAL_VELOCITY;
		public:
			EnemyMelee();
			~EnemyMelee();
			void execute();
			void save(LevelSave* save);
		private:
			void executeFOLLOWING();
			void executePATROLLING();
			void executeATKCANCEL();
			const bool checkOnLedge() const;
		};
	}
}

