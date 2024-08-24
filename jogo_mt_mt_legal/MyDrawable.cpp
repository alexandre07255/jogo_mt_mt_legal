#include "MyDrawable.h"

MyDrawable::MyDrawable(string path, sf::Vector2f size, sf::Vector2f pos) :
	sf::RectangleShape(size),id(idCont++)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	setTexture(texture);
	setOrigin(pos);
}

MyDrawable::MyDrawable() :id(idCont++) {

}

MyDrawable::~MyDrawable() { }

const float MyDrawable::bottom() const { return (getPosition().y + getSize().y); }

const float MyDrawable::top() const { return getPosition().y; }

const float MyDrawable::left() const { return getPosition().x; }

const float MyDrawable::right() const { return (getPosition().x + getSize().x); }

const float MyDrawable::xMid() const { return (getPosition().x + getSize().x /2); }

const float MyDrawable::yMid() const { return (getPosition().y + getSize().y / 2); }


void MyDrawable::setTextura(string path) {
	sf::Texture* textura;
	textura = new sf::Texture;
	textura->loadFromFile(path);

	setTexture(textura);
}

int MyDrawable::idCont(0);

int MyDrawable::getId() {
	return id;
}