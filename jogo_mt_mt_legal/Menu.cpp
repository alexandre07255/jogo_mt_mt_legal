#include "Menu.h"
using namespace Scenes;
using namespace Managers;


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

SceneManager* Menu::pSmanager(SceneManager::getInstance());
