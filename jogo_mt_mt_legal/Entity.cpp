#include "Entity.h"
using namespace Entities;



Entity::Entity(): Being(), onAir(1), frictionFelt(1)
{
	pShape = new sf::RectangleShape();
}

Entity::~Entity() { }

const bool Entity::getOnAir() const
{
	return onAir;
}

void Entity::setOnAir(const bool value)
{
	onAir = value;
}

const float Entity::GRAVITY(1.f);

void Entity::setFriction(float fric){
	frictionFelt = fric;
}

void Entity::setSize(const float x, const float y) {
	width = x;
	height = y;
	pShape->setSize(sf::Vector2f(x, y));
}

void Entity::setSize(const sf::Vector2f& vec) {
	width = vec.x;
	height = vec.y;
	pShape->setSize(vec);
}

sf::Vector2f Entity::getSize() const{
	return (sf::Vector2f(height, width));
}

void Entity::setPosition(const float x, const float y) {
	xPos = x;
	yPos = y;
	pShape->setPosition(sf::Vector2f(x, y));
}

void Entity::setPosition(const sf::Vector2f& vec) {
	xPos = vec.x;
	yPos = vec.y;
	pShape->setPosition(vec);
}

sf::Vector2f Entity::getPosition() const {
	return (sf::Vector2f(xPos, yPos));
}

sf::FloatRect Entity::getGlobalBounds() const
{
	return pShape->getGlobalBounds();
}

void Entity::move(const float x, const float y)
{
	xPos += x;
	yPos += y;
	pShape->move(x, y);
}

void Entity::move(const sf::Vector2f& vec)
{
	xPos += vec.x;
	yPos += vec.y;
	pShape->move(vec);
}

void Entity::setHorizontalVelocity(const float hV)
{
	horizontalVelocity = hV;
}

void Entity::setVerticalVelocity(const float vV)
{
	verticalVelocity = vV;
}

const float Entity::right() const
{
	return xPos + width;
}

const float Entity::left() const
{
	return xPos;
}

const float Entity::top() const
{
	return yPos;
}

const float Entity::bottom() const
{
	return yPos + height;
}

const float Entity::xMid() const
{
	return xPos + width / 2;
}

const float Entity::yMid() const
{
	return yPos + height / 2;
}


void Entity::setFillColor(const sf::Color & col) {
	pShape->setFillColor(col);
}

void Entity::setTexture(sf::Texture* tex)
{
	pTexture = tex;
	pShape->setTexture(tex);
}