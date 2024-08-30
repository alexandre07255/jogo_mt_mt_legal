#pragma once
#include "Entity.h"

namespace Entities {
	namespace Characters {
		class Hittable : public Entity
		{
		protected:
			int hp;
			bool isAlly;
			int state;
			int stun;
			bool facingRight;
			int points;
			int fireCont;
			int fireRemaining;
		public:
			Hittable(const bool ally, const int health);
			virtual  ~Hittable();
			enum States
			{
				FREE,
				ATTACK,
				HITSTUN,
				ATKCANCEL,
				PATROLLING, //usar apenas com inimigo
				FOLLOWING //usar apenas com inimigo
			};
			void setFireRemaining(const int cont);
			void setState(const int st);
			void setStun(const int st);
			const int getStun() const;
			const int getState() const;
			const bool getIsAlly() const;
			void dealDamage(const int dmg);
			const int getHp() const;
			const int getPoints() const;
			void setPoints(int p);

			virtual void execute() = 0;
		};
	}
}

