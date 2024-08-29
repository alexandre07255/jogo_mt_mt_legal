#pragma once
#include "Hittable.h"

namespace Entities { namespace Obstacles { class Platform; } }

namespace Entities
{
	class Support : public Characters::Hittable
	{
	private:
		Obstacles::Platform* boundedTo;
		static int MAXHEALTH;
	public:
		Support(Obstacles::Platform* plat, const float height);
		void setPlatform(Obstacles::Platform* plat);
		void execute();

		void save(LevelSave* save);
	};
}

