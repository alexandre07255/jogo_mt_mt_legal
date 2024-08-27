#include "Being.h"
using namespace Managers;

Being::Being():id(idCont++),pShape(NULL),pTexture(NULL) {
}

int Being::idCont(0);

GraphicManager* Being::pGG(GraphicManager::getInstance());

Being::~Being() {
	id = -1;
}

void Being::draw() {
	pGG->drawBeing(this);
}

sf::RectangleShape* Being::getShape() {
	return pShape;
}

void Being::setShape(sf::RectangleShape* rect) {
	pShape = rect;
}

sf::Texture* Being::getTexture() {
	return pTexture;
}

void Being::setTextureBeing(sf::Texture* ptext) {
	pTexture = ptext;
	if (ptext) {
		pShape->setTexture(pTexture);
	}
}

