#pragma once
#include "Entity.h"
#include "AttackHitbox.h"

namespace Entities
{
	class Projectile : public Entity
	{
	private:
		Hitboxes::AttackHitbox* hitbox;
		int hitstun;
		bool hasHit;
		bool firstStep;
	public:
		Projectile();
		void setHorKnockback(const float horKnock);
		void setVerKnockback(const float verKnock);
		void setDamage(const int dmg);
		void setHitstun(const int stun);
		void setTarget(const bool tar);
		void setRelativePosition(sf::Vector2f rel);
		void setOwner(Entities::Characters::Hittable* own);
		void movement();
	};
}

