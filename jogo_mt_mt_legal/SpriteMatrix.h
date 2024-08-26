#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
using namespace sf;
using namespace std;

class SpriteMatrix
{
private:
	vector<vector<Texture*>*>* spriteSheet;
	string name;
	int xStep;
	int yStep;
	const bool isBlockEmpty(Image& img, const int x, const int y) const;
public:
	SpriteMatrix();
	void loadFromFile(const string sName, const int stepX, const int stepY, const string path);
	const int getXStep() const;
	const int getYStep() const;
	const int getLineSize(const int l) const;
	const int getNumberOfLines() const;
	const string getName() const;
	const Texture* getSprite(int x, int y) const;
};

