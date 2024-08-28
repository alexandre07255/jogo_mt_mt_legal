#pragma once
#include "Hittable.h"
#include "Platform.h"

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
	};
}

