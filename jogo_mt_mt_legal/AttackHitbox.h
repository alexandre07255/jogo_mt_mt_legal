#pragma once
#include "Hitbox.h"
#include "CollisionManager.h"
#include "List.h"
#include "Level.h"
#include <list>

namespace Entities
{
	namespace Hitboxes
	{
		class AttackHitbox : public Hitbox
		{
		private:
			float verKnockback;
			float horKnockback;
			bool isInfinite;
			bool doesATKCANCEL;
			int damage;
			int hitstun;
			list<Entities::Characters::Hittable*> hitList;
			bool hasHit;
			const bool hasAlreadyHit(Hittable* pA);
		public:
			AttackHitbox();
			void setHorKnockback(const float horKnock);
			void setVerKnockback(const float verKnock);
			void setDamage(const int dmg);
			void setHitstun(const int stun);
			void setIsInfinite(const bool inf);
			void setDoesATKCANCEL(const bool dAC);
			const bool getHasHit() const;
			void movement();
			void hitSolution(Hittable* hit);
		};

	}
}
