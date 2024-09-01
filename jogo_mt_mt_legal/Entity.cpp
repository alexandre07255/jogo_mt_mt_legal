#include "Entity.h"
using namespace Entities;



Entity::Entity(): Being(), horizontalVelocity(0), verticalVelocity(0), onAir(1), frictionFelt(1),
xPos(0.f), yPos(0.f), width(1.f), height(1.f), spriteMatrixIndex(0), spriteX(0), spriteY(0), frameCont(0)
{
	pShape = new sf::RectangleShape();
}

Entity::~Entity()
{
	delete pShape;
}

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

const float Entity::getXSize() const
{
	return width;
}

const float Entity::getYSize() const
{
	return height;
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

const float Entity::getXPosition() const
{
	return xPos;
}

const float Entity::getYPosition() const
{
	return yPos;
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
	return xPos - pShape->getOrigin().x;
}

const float Entity::top() const
{
	return yPos - pShape->getOrigin().y;
}

const float Entity::bottom() const
{
	return yPos - pShape->getOrigin().y + height;
}

const float Entity::xMid() const
{
	return xPos - pShape->getOrigin().x + width / 2;
}

const float Entity::yMid() const
{
	return yPos - pShape->getOrigin().y + height / 2;
}


void Entity::setFillColor(const sf::Color & col) {
	pShape->setFillColor(col);
}

