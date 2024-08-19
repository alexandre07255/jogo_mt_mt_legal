#include "Menu.h"

Menu::Menu() {
	buttonList = new list<Button*>;
	size = sf::Vector2f(0, 0);
}

void Menu::setSize(sf::Vector2f _size) {
	size = _size;
}