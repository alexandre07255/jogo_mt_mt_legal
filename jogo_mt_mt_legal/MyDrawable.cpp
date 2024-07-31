#include "MyDrawable.h"

MyDrawable::MyDrawable(string path, sf::Vector2f size, sf::Vector2f pos) :
	sf::RectangleShape(size)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	setTexture(texture);
	setOrigin(pos);
}