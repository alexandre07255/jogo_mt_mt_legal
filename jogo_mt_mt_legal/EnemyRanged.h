#pragma once
#include "Enemy.h"
#include "Projectile.h"

namespace Entities
{
	namespace Characters
	{
		class EnemyRanged : public Enemy
		{
		private:
			int walkingBuffer;
			int waitBuffer;
			bool direction;
			int cooldownCont;
			int contCycle;
			int nearestCollidableCont;

			const int cycleLenght;
			const int attackStartup;
			const int attackEndLag;
			const float heightStrip;
			const float idealHeight;
			const float attackTriggerRange;
			const float attackTriggerStrip;
			const float attackTriggerYRange;

			static const int COOLDOWN;
			static const int NEAREST_COLLIDABLE_COOLDOWN;
			static const float MAX_HEIGHT;
			static const float FLY_STRENGTH;
			static const float FOLLOW_MAX_HORIZONTAL_VELOCITY;
			static const float FOLLOW_ACCELARATION;
			static const float WALK_ACCELARATION;
			static const float WALK_MAX_HORIZONTAL_VELOCITY;
		public:
			EnemyRanged();
			~EnemyRanged();
			void execute();
			void save(LevelSave* save);
		private:
			void projectileCalculations(Projectile* proj, const float absHorVelocity, Hittable* target);
			void executeFOLLOWING();
			void executePATROLLING();
			void executeATTACK();
			void executeATKCANCEL();
		};
	}
}

