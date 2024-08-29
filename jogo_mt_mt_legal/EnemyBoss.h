#pragma once
#include "Enemy.h"

namespace Entities
{
	namespace Characters
	{
		class EnemyBoss : public Enemy
		{
		public:
			EnemyBoss();
			void execute();
			void save(LevelSave* save);

		};
	}
}

