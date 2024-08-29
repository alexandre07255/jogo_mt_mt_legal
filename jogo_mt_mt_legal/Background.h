#pragma once
#include "Entity.h"

namespace Entities
{
	class Background : public Entity
	{
	private:
		float scale;
	public:
		Background();
		~Background();
		const float getScale() const;
		void setScale(const float sca);
		void execute();
		void save();
	};
}

