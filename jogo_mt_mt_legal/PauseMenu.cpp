#include "PauseMenu.h"
#include "inputManager.h"
#include "SceneManager.h"
#include "CommandQuit.h"
#include "CommandSave.h"
#include "SpriteManager.h"

using namespace Scenes;
using namespace Managers;
using namespace Entities;

PauseMenu::PauseMenu(Level* lAct): levelActive(lAct){
	//pGG->getWindow()->setView(pGG->getWindow()->getDefaultView());

	GraphicManager* gInstance = GraphicManager::getInstance();
	sf::RenderWindow* window = gInstance->getWindow();
	SpriteManager* spInstance = SpriteManager::getInstance();
	int matrixIndex = 0;


	float x = window->getSize().x;
	float y = window->getSize().y;

	matrixIndex = spInstance->getMatrixIndex("Menu");
	Background* background = new Background;
	spInstance->getTexture(background, matrixIndex, 0, 0);
	background->setSize(320.f * 6, 180.f * 6);

	CommandSave* com2 = new CommandSave(this);

	matrixIndex = spInstance->getMatrixIndex("SaveButton");
	Button* buttonSave = new Button(sf::Color::White, com2, true, matrixIndex);
	buttonSave->setSize(33.f * 6, 17.f * 6);
	buttonSave->setPosition(x / 2.0f - buttonSave->getXSize() / 2, y / 2.0f - 40.f);

	CommandQuit* com1 = new CommandQuit(this);

	matrixIndex = spInstance->getMatrixIndex("QuitButton");
	Button* buttonQuit = new Button(sf::Color::White, com1, false, matrixIndex);
	buttonQuit->setSize(33.f * 6, 17.f * 6);
	buttonQuit->setPosition(x/2.0f - buttonQuit->getXSize() / 2,y/2.0f + 140.f);

	
	entityList->push_back(background);
	entityList->push_back(buttonSave);
	entityList->push_back(buttonQuit);
}

PauseMenu::~PauseMenu() {
}

void PauseMenu::escResolver() {
	pSmanager->pop();
}

void PauseMenu::save() {
	levelActive->save();
}