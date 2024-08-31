#pragma once
#include "SpriteMatrix.h"
#include "Being.h"


namespace Managers
{
	class SpriteManager
	{
	private:
		static SpriteManager* instance;
		std::vector<SpriteMatrix*> spriteMatrices;
		SpriteManager();
	public:
		static SpriteManager* getInstance();
		~SpriteManager();
		const int getMatrixIndex(std::string name) const;
		void getTexture(Being* target, const int matrixIndex, const int x, const int y) const;
		void next(Being* target, const int matrixIndex, int& x, int& y);
	};
}

