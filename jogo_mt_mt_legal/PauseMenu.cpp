#include "PauseMenu.h"
#include "inputManager.h"
#include "SceneManager.h"
#include "CommandQuit.h"
#include "CommandSave.h"

using namespace Scenes;
using namespace Managers;


PauseMenu::PauseMenu(Level* lAct): levelActive(lAct){
	GraphicManager* gInstance = GraphicManager::getInstance();
	sf::RenderWindow* window = gInstance->getWindow();

	CommandQuit* com1 = new CommandQuit(this);

	Button* buttonQuit = new Button(sf::Color::Blue, com1, false);
	buttonQuit->setPosition(window->getSize().x,window->getSize().y/2 -100.f);

	CommandSave* com2 = new CommandSave(this);

	Button* buttonSave = new Button(sf::Color::Blue, com2, true);
	buttonSave->setPosition(window->getSize().x, window->getSize().y / 2 + 100.f);

	entityList->push_back(buttonQuit);
	entityList->push_back(buttonSave);
}

PauseMenu::~PauseMenu() {
}

void PauseMenu::escResolver() {
	pSmanager->pop();
}

void PauseMenu::save() {
	levelActive->save();
}