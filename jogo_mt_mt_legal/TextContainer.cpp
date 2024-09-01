#include "TextContainer.h"
#include "LevelSave.h"
using namespace Entities;

TextContainer::TextContainer() {
	text = new sf::Text;
	text->setFont(font);
	setSize(200.f, 100.f);
	text->setCharacterSize(24);
	text->setFillColor(sf::Color::White);
}

TextContainer::~TextContainer()
{
	delete text;
}

void TextContainer::draw() {
	pGG->drawBeing(this);
	pGG->drawText(*text);
}

void TextContainer::execute() {
}

void TextContainer::save(LevelSave* save) {
}

sf::Font TextContainer::getFont() {
	sf::Font font;
	font.loadFromFile("HizaSprites/Fonts/mc-ten-lowercase-alt.ttf");
	return font;
}

void TextContainer::write(std::string sText) {
	text->setString(sText);
}

sf::Font TextContainer::font(TextContainer::getFont());

void TextContainer::setTextPosition(float x, float y) {
	text->setPosition(x, y);
}

void TextContainer::setTextFillColor(sf::Color col)
{
	text->setFillColor(col);
}