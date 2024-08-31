#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class SpriteMatrix
{
private:
	std::vector<std::vector<sf::Texture*>*>* spriteSheet;
	std::string name;
	int xStep;
	int yStep;
	const bool isBlockEmpty(sf::Image& img, const int x, const int y) const;
public:
	SpriteMatrix();
	~SpriteMatrix();
	void loadFromFile(const std::string sName, const int stepX, const int stepY, const std::string path);
	const int getXStep() const;
	const int getYStep() const;
	const int getLineSize(const int l) const;
	const int getNumberOfLines() const;
	const std::string getName() const;
	sf::Texture* getSprite(const int x, const int y) const;
};

