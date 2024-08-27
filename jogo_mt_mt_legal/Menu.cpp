#include "Menu.h"
using namespace Scenes;

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::stackScene(Scene* pS) {
	pSmanager->push(pS);
}

void Menu::removeScene() {
	pSmanager->pop();
}
