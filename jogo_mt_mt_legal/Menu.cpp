#include "Menu.h"
using namespace Scenes;

Menu::Menu() {
	buttonList = new list<Button*>;
	size = sf::Vector2f(0, 0);
}

void Menu::setSize(sf::Vector2f _size) {
	size = _size;
}

void Menu::addButton(Button* but) {
	buttonList->push_back(but);
}

void Menu::save() {
	cout << "Teste salvamento" << endl;
}