#include "MainMenu.h"
#include "SceneManager.h"
#include "Level1.h"
#include "Level2.h"
#include <iostream>
#include "CommandStack1.h"
#include "CommandStack2.h"
#include "CommandStart.h"
#include "CommandLevel2p2False.h"
#include "CommandLevel1p2False.h"
#include "CommandLevel2p2True.h"
#include "CommandLevel1p2True.h"
#include "GraphicManager.h"
#include "inputManager.h"
#include "Button.h"

using namespace std;
using namespace Managers;
using namespace Scenes;
using namespace Managers;
using namespace Lists;

MainMenu::MainMenu():version(0){

	GraphicManager* instance = GraphicManager::getInstance();

	CommandStart* com1 = new CommandStart(this);

	Button* startButton = new Button(sf::Color::Blue, com1, true);
	startButton->setPositionEntity(instance->getWindow()->getSize().x/2, instance->getWindow()->getSize().y / 3 - 25.f);

	EntityList* startList = new EntityList;
	startList->push_back(startButton);

	CommandStack1* com2 = new CommandStack1(this);
	CommandStack2* com3 = new CommandStack2(this);

	Button* buttonLevel1 = new Button(sf::Color::Blue, com2, false);
	Button* buttonLevel2 = new Button(sf::Color::Blue, com3, false);

	buttonLevel1->setPositionEntity(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 - 125.f);
	buttonLevel2->setPositionEntity(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 + 125.f);

	EntityList* levelsList = new EntityList;
	levelsList->push_back(buttonLevel1);
	levelsList->push_back(buttonLevel2);

	versions.push_back(startList);
	versions.push_back(levelsList);

	changeMainButtons();
}

MainMenu::~MainMenu() {
	delete versions[0];
	delete versions[1];
	delete versions[2];
}


void MainMenu::stackLevel1(bool player2) {

	SceneManager* instance = SceneManager::getInstance();
	//cria level1 aqui? mainmenu teria um ponteiro para level1? de fato, são muitas perguntas, e poucas respostas
	Level1* level;
	level = new Level1(player2);

	instance->push(level);

}

void MainMenu::stackLevel2(bool player2) {

	SceneManager* instance = SceneManager::getInstance();
	
	Level2* level;
	level = new Level2(player2);

	instance->push(level);
}

void MainMenu::changeMainButtons() {
	version = 0;
	setEntityList(versions[0]);
}
void MainMenu::changeStartButtons() {
	version = 1;
	setEntityList(versions[1]);
}
void MainMenu::changeOptionsButtons() {
	version = 2;
	setEntityList(versions[2]);
}

void MainMenu::goBack() {
	if (version == 0) {
		GraphicManager* instance = GraphicManager::getInstance();
		instance->getWindow()->close();
	}
	else if (version == 1 || version == 2){
		changeMainButtons();
	}
}

void MainMenu::moreButtons(bool level2) {
	//version = 3;//apenas uma ideia tola e sombria
	GraphicManager* instance = GraphicManager::getInstance();

	if (level2) {
		CommandLevel2p2False* com1 = new CommandLevel2p2False(this);
		CommandLevel2p2True* com2 = new CommandLevel2p2True(this);

		Button* greenThing = new Button(sf::Color::Green, com2, true);
		Button* redThing = new Button(sf::Color::Red, com1, true);

		greenThing->setPositionEntity(instance->getWindow()->getSize().x / 2 + 300, instance->getWindow()->getSize().y / 2 + 125.f);
		redThing->setPositionEntity(instance->getWindow()->getSize().x / 2 - 300, instance->getWindow()->getSize().y / 2 + 125.f);

		versions[1]->push_back(greenThing);
		versions[1]->push_back(redThing);
	}
	else {
		CommandLevel1p2False* com1 = new CommandLevel1p2False(this);
		CommandLevel1p2True* com2 = new CommandLevel1p2True(this);

		Button* greenThing = new Button(sf::Color::Green, com2, true);
		Button* redThing = new Button(sf::Color::Red, com1, true);

		greenThing->setPositionEntity(instance->getWindow()->getSize().x / 2 + 300, instance->getWindow()->getSize().y / 2 - 125.f);
		redThing->setPositionEntity(instance->getWindow()->getSize().x / 2 - 300, instance->getWindow()->getSize().y / 2 - 125.f);

		versions[1]->push_back(greenThing);
		versions[1]->push_back(redThing);
	}

	changeStartButtons();
}

void MainMenu::escResolver() {
	goBack();
}