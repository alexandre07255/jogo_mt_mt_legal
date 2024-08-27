#include "SpriteMatrix.h"
using namespace sf;
using namespace std;


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
		bool lineEnd = 0;
		for (int i = 0; i < xSize && !lineEnd; i++)
		{
			if (!isBlockEmpty(img, i, j))
			{
				Texture* block = new Texture;
				bool result = 0;
				do
				{
					result = block->loadFromImage(img, IntRect(i * xStep, j * yStep, xStep, yStep));
				} while (!result);

				line->push_back(block);
			}
			else
				lineEnd = 1;
		}
	}
	name = sName;
}

const int SpriteMatrix::getXStep() const { return xStep; }

const int SpriteMatrix::getYStep() const { return yStep; }

const string SpriteMatrix::getName() const { return name; }

const int SpriteMatrix::getLineSize(const int l) const { return spriteSheet->at(l)->size(); }

const int SpriteMatrix::getNumberOfLines() const { return spriteSheet->size(); }

const Texture* SpriteMatrix::getSprite(int x, int y) const
{
	return spriteSheet->at(y)->at(x);
}