#include "SpriteManager.h"
using namespace Managers;

SpriteManager::SpriteManager():
	spriteMatrices()
{
	spriteMatrices.clear();

	SpriteMatrix* spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Samurai1", 36, 44, "HizaSprites/Characters/s_samurai_red.png");
	spriteMatrices.push_back(spriteSheet);

	spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Samurai2", 36, 44, "HizaSprites/Characters/s_samurai_blue.png");
	spriteMatrices.push_back(spriteSheet);

	spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Bloberto", 32, 32, "HizaSprites/Enemies/bloberto.png");
	spriteMatrices.push_back(spriteSheet);

	spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Koi", 32, 16, "HizaSprites/Enemies/koi.png");
	spriteMatrices.push_back(spriteSheet);

	spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Spike", 16, 16, "HizaSprites/Environment/s_spike.png");
	spriteMatrices.push_back(spriteSheet);

	spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Fire", 16, 16, "HizaSprites/Environment/s_fire.png");
	spriteMatrices.push_back(spriteSheet);

	spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Support", 16, 16, "HizaSprites/Environment/s_beam.png");
	spriteMatrices.push_back(spriteSheet);

	spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Platform", 16, 16, "HizaSprites/Environment/s_lame_platform.png");
	spriteMatrices.push_back(spriteSheet);

	spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Background", 320, 180, "HizaSprites/Environment/s_cool_background.png");
	spriteMatrices.push_back(spriteSheet);

	spriteSheet = new SpriteMatrix;
	spriteSheet->loadFromFile("Tengu", 92, 109, "HizaSprites/Enemies/s_tengu.png");
	spriteMatrices.push_back(spriteSheet);
}

SpriteManager* SpriteManager::getInstance()
{
	if (instance == NULL)
		instance = new SpriteManager;
	return instance;
}

SpriteManager::~SpriteManager()
{
	int size = spriteMatrices.size();
	for (int i = 0; i < size; i++)
	{
		delete spriteMatrices[i];
	}
	spriteMatrices.clear();
}

const int SpriteManager::getMatrixIndex(std::string name) const
{
	int size = spriteMatrices.size();
	for (int i = 0; i < size; i++)
	{
		if (name == spriteMatrices[i]->getName())
			return i;
	}
	return -1;
}

void SpriteManager::getTexture(Being* target, const int matrixIndex, const int x, const int y) const
{
	if (matrixIndex >= spriteMatrices.size() || matrixIndex < 0) { return; }
	if (y >= spriteMatrices[matrixIndex]->getNumberOfLines() || y < 0) { return; }
	if (x >= spriteMatrices[matrixIndex]->getLineSize(y) || x < 0) { return; }

	target->setTexture(spriteMatrices[matrixIndex]->getSprite(x, y));
}

void SpriteManager::next(Being* target, const int matrixIndex, int& x, int& y)
{
	if (matrixIndex >= spriteMatrices.size() || matrixIndex < 0) { return; }
	if (y >= spriteMatrices[matrixIndex]->getNumberOfLines() || y < 0) { return; }
	if (x >= spriteMatrices[matrixIndex]->getLineSize(y) || x < 0) { return; }

	x = (x + 1) % spriteMatrices[matrixIndex]->getLineSize(y);
	target->setTexture(spriteMatrices[matrixIndex]->getSprite(x, y));
}

SpriteManager* SpriteManager::instance(NULL);