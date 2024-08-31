#pragma once
#include "Hittable.h"
#include "Player.h"

namespace Entities
{
	namespace Characters
	{
		class Enemy : public Hittable
		{
		protected:
			double sightSize;
			int timer;
			int searchPlayerCont;
			Player* followingPlayer;

			double upperLimitMultR;
			double lesserLimitMultR;
			double upperLimitMultL;
			double lesserLimitMultL;

			static const int SEARCH_PLAYER_COOLDOWN;

			const bool isInSearchPlayerCooldown();
		public:
			Enemy();
			virtual ~Enemy();
		protected:
			void executeHITSTUN();
			Player* searchPlayer() const;
		};
	}
}

