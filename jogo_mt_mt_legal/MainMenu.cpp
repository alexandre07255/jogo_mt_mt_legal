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
#include "CommandLoad.h"
#include "CommandLoad1.h"
#include "CommandLoad2.h"
#include "GraphicManager.h"
#include "inputManager.h"
#include "Button.h"
#include "CommandRanking.h"
#include "CommandGoBack.h"
#include "TextContainer.h"
#include "ScoreSave.h"
#include "LevelSave.h"

using namespace std;
using namespace Managers;
using namespace Scenes;
using namespace Managers;
using namespace Lists;

MainMenu::MainMenu():version(0){

	GraphicManager* instance = GraphicManager::getInstance();

	CommandStart* com1 = new CommandStart(this);
	CommandRanking* com4 = new CommandRanking(this);
	CommandLoad* com6 = new CommandLoad(this);
	Button* startButton = new Button(sf::Color::Blue, com1, true);
	startButton->setPosition(instance->getWindow()->getSize().x/2, instance->getWindow()->getSize().y / 3 - 25.f);
	Button* buttonRanking = new Button(sf::Color::Blue, com4, true);
	buttonRanking->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 3 + 100.f);
	Button* buttonLoad = new Button(sf::Color::Blue, com6, true);
	buttonLoad->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 3 + 225.f);

	EntityList* startList = new EntityList;
	startList->push_back(startButton);
	startList->push_back(buttonRanking);
	startList->push_back(buttonLoad);

	CommandStack1* com2 = new CommandStack1(this);
	CommandStack2* com3 = new CommandStack2(this);

	Button* buttonLevel1 = new Button(sf::Color::Blue, com2, false);
	Button* buttonLevel2 = new Button(sf::Color::Blue, com3, false);

	buttonLevel1->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 - 125.f);
	buttonLevel2->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 + 125.f);

	EntityList* levelsList = new EntityList;
	levelsList->push_back(buttonLevel1);
	levelsList->push_back(buttonLevel2);

	//CommandGoBack* com5 = new CommandGoBack(this);
	//Button* goBackButton = new Button(sf::Color::Blue,com5,true);
	//goBackButton->setSize(instance->getWindow()->getXSize() / 2, instance->getWindow()->getYSize() / 3 - 25.f);

	EntityList* rankingList = new EntityList;
	//rankingList->push_back(goBackButton);

	nlohmann::json ranking = Save::readJson("saves.json");

	Entities::TextContainer* textCont;
	int i = 0;
	for (auto it = ranking.begin(); it != ranking.end(); it++) {
		textCont = new Entities::TextContainer;

		std::string textToWrite = static_cast<std::string>(it.key()) + " : " + static_cast<std::string>(it.value());

		textCont->write(textToWrite);
		textCont->setPosition(instance->getWindow()->getSize().x / 2, i * 100.f);
		textCont->setTextPosition(instance->getWindow()->getSize().x / 2, i * 100.f);

		rankingList->push_back(textCont);
		i++;
	}

	CommandLoad1* com7 = new CommandLoad1(this);
	CommandLoad2* com8 = new CommandLoad2(this);

	Button* buttonLoad1 = new Button(sf::Color::Blue, com7, true);
	Button* buttonLoad2 = new Button(sf::Color::Blue, com8, true);

	buttonLoad1->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 - 125.f);
	buttonLoad2->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 + 125.f);

	EntityList* loadList = new EntityList;
	loadList->push_back(buttonLoad1);
	loadList->push_back(buttonLoad2);

	versions.push_back(startList);
	versions.push_back(levelsList);
	versions.push_back(rankingList);
	versions.push_back(loadList);

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
	level = new Level1(player2,false);

	stackScene(level);

}

void MainMenu::stackLevel2(bool player2) {
	
	Level2* level;
	level = new Level2(player2,false);

	stackScene(level);
}

void MainMenu::changeMainButtons() {
	version = 0;
	setEntityList(versions[0]);
}
void MainMenu::changeStartButtons() {
	version = 1;
	setEntityList(versions[1]);
}
void MainMenu::changeRanking() {
	version = 2;

	setEntityList(versions[2]);
}
void MainMenu::changeLoadButtons() {
	version = 3;

	setEntityList(versions[3]);
}

void MainMenu::goBack() {
	if (version == 0) {
		GraphicManager* instance = GraphicManager::getInstance();
		instance->getWindow()->close();
	}
	else if (version == 1 || version == 2 || version == 3){
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

		greenThing->setPosition(instance->getWindow()->getSize().x / 2 + 300, instance->getWindow()->getSize().y / 2 + 125.f);
		redThing->setPosition(instance->getWindow()->getSize().x / 2 - 300, instance->getWindow()->getSize().y / 2 + 125.f);

		versions[1]->push_back(greenThing);
		versions[1]->push_back(redThing);
	}
	else {
		CommandLevel1p2False* com1 = new CommandLevel1p2False(this);
		CommandLevel1p2True* com2 = new CommandLevel1p2True(this);

		Button* greenThing = new Button(sf::Color::Green, com2, true);
		Button* redThing = new Button(sf::Color::Red, com1, true);

		greenThing->setPosition(instance->getWindow()->getSize().x / 2 + 300, instance->getWindow()->getSize().y / 2 - 125.f);
		redThing->setPosition(instance->getWindow()->getSize().x / 2 - 300, instance->getWindow()->getSize().y / 2 - 125.f);

		versions[1]->push_back(greenThing);
		versions[1]->push_back(redThing);
	}

	changeStartButtons();
}

void MainMenu::escResolver() {
	goBack();
}

void MainMenu::load(bool level2) {
	LevelSave save;
	save.loadLevel(level2);
}