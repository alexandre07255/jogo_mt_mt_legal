#include "SpriteMatrix.h"

SpriteMatrix::SpriteMatrix() :
	spriteSheet(new vector<vector<Texture*>*>),
	name(),
	xStep(0),
	yStep(0)
{
}

const bool SpriteMatrix::isBlockEmpty(Image& img, const int x, const int y) const
{
	for (int j = y * yStep; j < (y + 1) * yStep; j++)
	{
		for (int i = x * xStep; i < (x + 1) * xStep; i++)
		{
			if (img.getPixel(i, j) != Color::Transparent)
				return 0;
		}
	}
	return 1;
}

void SpriteMatrix::loadFromFile(const string sName, const int stepX, const int stepY, const string path)
{
	xStep = stepX;
	yStep = stepY;

	Image img;
	img.loadFromFile(path);
	
	int xSize = img.getSize().x / xStep;
	int ySize = img.getSize().y / yStep;

	for (int j = 0; j < ySize; j++)
	{
		vector<Texture*>* line = new vector<Texture*>;
		spriteSheet->push_back(line);
		for (int i = 0; i < xSize; i++);
	}
}

const int SpriteMatrix::getXStep() const { return xStep; }

const int SpriteMatrix::getYStep() const { return yStep; }

const string SpriteMatrix::getName() const { return name; }

const Texture* SpriteMatrix::getSprite(int x, int y) const
{
	return NULL;
}