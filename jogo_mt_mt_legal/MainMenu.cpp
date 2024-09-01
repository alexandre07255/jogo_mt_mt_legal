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
#include "CommandCredits.h"
#include "CommandGoBack.h"
#include "TextContainer.h"
#include "ScoreSave.h"
#include "LevelSave.h"
#include "SpriteManager.h"

using namespace std;
using namespace Managers;
using namespace Scenes;
using namespace Managers;
using namespace Lists;
using namespace Entities;

MainMenu::MainMenu():version(0){

	GraphicManager* instance = GraphicManager::getInstance();
	SpriteManager* spInstance = SpriteManager::getInstance();
	int matrixIndex = 0;

	CommandStart* com1 = new CommandStart(this);
	CommandRanking* com4 = new CommandRanking(this);
	CommandLoad* com6 = new CommandLoad(this);
	Button* startButton = new Button(sf::Color::White, com1, true);
	matrixIndex = spInstance->getMatrixIndex("StartButton");
	spInstance->getTexture(startButton, matrixIndex, 0, 0);
	startButton->setSize(54.f * 6, 17.f * 6);
	startButton->setPosition(instance->getWindow()->getSize().x/2 - startButton->getXSize() / 2, instance->getWindow()->getSize().y / 2 - 40.f);
	Button* buttonLoad = new Button(sf::Color::White, com6, true);
	matrixIndex = spInstance->getMatrixIndex("ContinueButton");
	spInstance->getTexture(buttonLoad, matrixIndex, 0, 0);
	buttonLoad->setSize(54.f * 6, 17.f * 6);
	buttonLoad->setPosition(instance->getWindow()->getSize().x / 2 - buttonLoad->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 85.f);
	Button* buttonRanking = new Button(sf::Color::Blue, com4, true);
	buttonRanking->setSize(62.f * 6, 17.f * 6);
	buttonRanking->setPosition(instance->getWindow()->getSize().x / 2 - buttonRanking->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 210.f);
	CommandCredits* com9 = new CommandCredits(this);
	Button* changeCreditsButton = new Button(sf::Color::White, com9, true);
	matrixIndex = spInstance->getMatrixIndex("CreditsButton");
	spInstance->getTexture(changeCreditsButton, matrixIndex, 0, 0);
	changeCreditsButton->setSize(54.f * 6, 17.f * 6);
	changeCreditsButton->setPosition(instance->getWindow()->getSize().x / 2 - changeCreditsButton->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 335.f);

	int backgroundMatrixIndex = spInstance->getMatrixIndex("Menu");
	Background* background = NULL;

	background = new Background;
	spInstance->getTexture(background, backgroundMatrixIndex, 0, 0);
	background->setSize(320.f * 6, 180.f * 6);

	EntityList* startList = new EntityList;
	startList->push_back(background);
	startList->push_back(startButton);
	startList->push_back(buttonRanking);
	startList->push_back(buttonLoad);
	startList->push_back(changeCreditsButton);

	CommandStack1* com2 = new CommandStack1(this);
	CommandStack2* com3 = new CommandStack2(this);

	Button* buttonLevel1 = new Button(sf::Color::Blue, com2, false);
	Button* buttonLevel2 = new Button(sf::Color::Blue, com3, false);

	buttonLevel1->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 - 125.f);
	buttonLevel2->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 + 125.f);

	background = new Background;
	spInstance->getTexture(background, backgroundMatrixIndex, 0, 0);
	background->setSize(320.f * 6, 180.f * 6);

	EntityList* levelsList = new EntityList;
	levelsList->push_back(background);
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
		
		textCont->setFillColor(sf::Color::Transparent);
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

	background = new Background;
	spInstance->getTexture(background, backgroundMatrixIndex, 0, 0);
	background->setSize(320.f * 6, 180.f * 6);

	EntityList* loadList = new EntityList;
	loadList->push_back(background);
	loadList->push_back(buttonLoad1);
	loadList->push_back(buttonLoad2);

	Entities::TextContainer* credits = new Entities::TextContainer;
	credits->write("PROGRAMAÇÃO:\n\nAlexandre Aires Amorim\nJohn William Souza Harrison\n\nARTE:\n\nNícolas Vinícius de Santa Gaio");
	credits->setSize(16 * 5.333 * 4.65, 16 * 5.333 * 3);
	credits->setTextPosition(instance->getWindow()->getSize().x / 2 - credits->getXSize() / 2 + 10, instance->getWindow()->getSize().y / 2);
	credits->setPosition(instance->getWindow()->getSize().x / 2 - credits->getXSize() / 2, instance->getWindow()->getSize().y / 2);
	credits->setFillColor(sf::Color::Black);

	background = new Background;
	spInstance->getTexture(background, backgroundMatrixIndex, 0, 0);
	background->setSize(320.f * 6, 180.f * 6);

	EntityList* CreditList = new EntityList;
	CreditList->push_back(background);
	CreditList->push_back(credits);

	versions.push_back(startList);
	versions.push_back(levelsList);
	versions.push_back(rankingList);
	versions.push_back(loadList);
	versions.push_back(CreditList);

	changeMainButtons();
}

MainMenu::~MainMenu() {
	for (int i = 0; i < 4; i++)
		if (i != version)
			delete versions[i];
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
void MainMenu::changeCreditsButtons() {
	version = 4;

	setEntityList(versions[4]);
}

void MainMenu::goBack() {
	if (version == 0) {
		GraphicManager* instance = GraphicManager::getInstance();
		instance->getWindow()->close();
	}
	else if (version == 1 || version == 2 || version == 3 || version == 4){
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