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
			Player* followingPlayer;

			double upperLimitMultR;
			double lesserLimitMultR;
			double upperLimitMultL;
			double lesserLimitMultL;
		public:
			Enemy();
		protected:
			void executeHITSTUN();
			Player* searchPlayer() const;
		};
	}
}

