#include "PauseMenu.h"
#include "inputManager.h"
#include "SceneManager.h"
#include "CommandQuit.h"
#include "CommandSave.h"

using namespace Scenes;
using namespace Managers;


PauseMenu::PauseMenu(Level* lAct): levelActive(lAct){
	CommandQuit* com1 = new CommandQuit(this);

	Button* buttonQuit = new Button(sf::Color::Blue, com1, false);
	buttonQuit->setPositionEntity(500.f, 500.f);

	CommandSave* com2 = new CommandSave(this);

	Button* buttonSave = new Button(sf::Color::Blue, com2, true);
	buttonSave->setPositionEntity(500.f,700.f);

	entityList->push_back(buttonQuit);
	entityList->push_back(buttonSave);
}

PauseMenu::~PauseMenu() {
}

void PauseMenu::escResolver() {
	pSmanager->pop();
}

void PauseMenu::save() {
	//todo
}