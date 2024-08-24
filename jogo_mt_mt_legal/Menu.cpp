#include "Menu.h"

Menu::Menu() {
	buttonList = new List<Button>;
	size = sf::Vector2f(0, 0);
}

void Menu::setSize(sf::Vector2f _size) {
	size = _size;
}

void Menu::addButton(Button* but) {
	buttonList->push_back(but);
}