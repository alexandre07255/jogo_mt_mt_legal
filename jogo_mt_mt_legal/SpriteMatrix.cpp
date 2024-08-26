#include "SpriteMatrix.h"

SpriteMatrix::SpriteMatrix() :
	spriteSheet(),
	name(),
	xStep(0),
	yStep(0),
	xSize(0),
	ySize(0)
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
	
	xSize = img.getSize().x / xStep;
	ySize = img.getSize().y / yStep;


}

const int SpriteMatrix::getXStep() const { return xStep; }

const int SpriteMatrix::getYStep() const { return yStep; }

const int SpriteMatrix::getXSize() const { return xSize; }

const int SpriteMatrix::getYSize() const { return ySize; }

const string SpriteMatrix::getName() const { return name; }

const Texture* SpriteMatrix::getSprite(int x, int y) const
{

}