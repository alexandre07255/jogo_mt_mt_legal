#include "Being.h"
using namespace Managers;

Being::Being():id(idCont++),pShape(NULL),pTexture(NULL) {
}

int Being::idCont(0);

GraphicManager* Being::pGG(GraphicManager::getInstance());

Being::~Being() {
	id = -1;
}

const int Being::getId() const
{
	return id;
}

void Being::draw() {
	pGG->drawBeing(this);
}

sf::RectangleShape* Being::getShape() {
	return pShape;
}

sf::Texture* Being::getTexture() {
	return pTexture;
}

void Being::setTexture(sf::Texture* ptext) {
	pTexture = ptext;
	if (pShape) {
		pShape->setTexture(pTexture);
	}
}

