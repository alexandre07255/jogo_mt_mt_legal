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
	matrixIndex = spInstance->getMatrixIndex("StartButton");
	Button* startButton = new Button(sf::Color::White, com1, true, matrixIndex);
	startButton->setSize(62.f * 6, 17.f * 6);
	startButton->setPosition(instance->getWindow()->getSize().x/2 - startButton->getXSize() / 2, instance->getWindow()->getSize().y / 2 - 40.f - 90.f);
	matrixIndex = spInstance->getMatrixIndex("ContinueButton");
	Button* buttonLoad = new Button(sf::Color::White, com6, true, matrixIndex);
	buttonLoad->setSize(62.f * 6, 17.f * 6);
	buttonLoad->setPosition(instance->getWindow()->getSize().x / 2 - buttonLoad->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 85.f - 90.f);
	matrixIndex = spInstance->getMatrixIndex("RankingButton");
	Button* buttonRanking = new Button(sf::Color::White, com4, true, matrixIndex);
	buttonRanking->setSize(62.f * 6, 17.f * 6);
	buttonRanking->setPosition(instance->getWindow()->getSize().x / 2 - buttonRanking->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 210.f - 90.f);
	CommandCredits* com9 = new CommandCredits(this);
	matrixIndex = spInstance->getMatrixIndex("CreditsButton");
	Button* changeCreditsButton = new Button(sf::Color::White, com9, true, matrixIndex);
	changeCreditsButton->setSize(62.f * 6, 17.f * 6);
	changeCreditsButton->setPosition(instance->getWindow()->getSize().x / 2 - changeCreditsButton->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 335.f - 90.f);

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

	matrixIndex = spInstance->getMatrixIndex("Level1Button");
	Button* buttonLevel1 = new Button(sf::Color::White, com2, false, matrixIndex);
	matrixIndex = spInstance->getMatrixIndex("Level2Button");
	Button* buttonLevel2 = new Button(sf::Color::White, com3, false, matrixIndex);

	buttonLevel1->setSize(20.f * 6, 17.f * 6);
	buttonLevel1->setPosition(instance->getWindow()->getSize().x / 2 - buttonLevel1->getXSize() / 2, instance->getWindow()->getSize().y / 2 - 40.f);
	buttonLevel2->setSize(20.f * 6, 17.f * 6);
	buttonLevel2->setPosition(instance->getWindow()->getSize().x / 2 - buttonLevel2->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 140.f);

	backgroundMatrixIndex = spInstance->getMatrixIndex("Menu");
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

	backgroundMatrixIndex = spInstance->getMatrixIndex("MenuDark");
	background = new Background;
	spInstance->getTexture(background, backgroundMatrixIndex, 0, 0);
	background->setSize(320.f * 6, 180.f * 6);
	rankingList->push_back(background);

	nlohmann::json ranking = Save::readJson("saves/score_save.json");

	Entities::TextContainer* textCont;
	int i = 0;
	for (auto it = ranking.begin(); it != ranking.end(); it++) {
		textCont = new Entities::TextContainer;
		
		std::string textToWrite = static_cast<std::string>(it.key()) + " : " + static_cast<std::string>(it.value());
		
		textCont->setFillColor(sf::Color::Transparent);
		textCont->setTextFillColor(sf::Color::White);
		textCont->write(textToWrite);
		textCont->setPosition(instance->getWindow()->getSize().x / 2, (i + 1) * 50.f);
		textCont->setTextPosition(instance->getWindow()->getSize().x / 2 - 100.f, (i + 1) * 50.f);

		rankingList->push_back(textCont);
		i++;
	}

	CommandLoad1* com7 = new CommandLoad1(this);
	CommandLoad2* com8 = new CommandLoad2(this);


	matrixIndex = spInstance->getMatrixIndex("Level1Button");
	Button* buttonLoad1 = new Button(sf::Color::White, com7, true, matrixIndex);
	matrixIndex = spInstance->getMatrixIndex("Level2Button");
	Button* buttonLoad2 = new Button(sf::Color::White, com8, true, matrixIndex);

	buttonLoad1->setSize(20.f * 6, 17.f * 6);
	buttonLoad1->setPosition(instance->getWindow()->getSize().x / 2 - buttonLoad1->getXSize() / 2, instance->getWindow()->getSize().y / 2 - 40.f);
	buttonLoad2->setSize(20.f * 6, 17.f * 6);
	buttonLoad2->setPosition(instance->getWindow()->getSize().x / 2 - buttonLoad2->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 140.f);

	backgroundMatrixIndex = spInstance->getMatrixIndex("Menu");
	background = new Background;
	spInstance->getTexture(background, backgroundMatrixIndex, 0, 0);
	background->setSize(320.f * 6, 180.f * 6);

	EntityList* loadList = new EntityList;
	loadList->push_back(background);
	loadList->push_back(buttonLoad1);
	loadList->push_back(buttonLoad2);

	Entities::TextContainer* credits = new Entities::TextContainer;
	credits->write("PROGRAMAÇÃO:\n\nAlexandre Aires Amorim\nJohn William Souza Harrison\n\nARTE:\n\nNícolas Vinícius de Santa Gaio");
	credits->setSize(16 * 5.333 * 4.65, 16 * 5.333 * 3.4f);
	credits->setTextPosition(instance->getWindow()->getSize().x / 2 - credits->getXSize() / 2 + 10, instance->getWindow()->getSize().y / 2);
	credits->setPosition(instance->getWindow()->getSize().x / 2 - credits->getXSize() / 2, instance->getWindow()->getSize().y / 2 - 5.f);
	credits->setFillColor(sf::Color::Black);

	backgroundMatrixIndex = spInstance->getMatrixIndex("Menu");
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
	SpriteManager* spInstance = SpriteManager::getInstance();


	int matrixIndex = 0;

	if (level2) {
		CommandLevel2p2False* com1 = new CommandLevel2p2False(this);
		CommandLevel2p2True* com2 = new CommandLevel2p2True(this);

		matrixIndex = spInstance->getMatrixIndex("IsPlayer2");
		Button* greenThing = new Button(sf::Color::White, com2, true, matrixIndex);
		matrixIndex = spInstance->getMatrixIndex("IsPlayer1");
		Button* redThing = new Button(sf::Color::White, com1, true, matrixIndex);

		greenThing->setSize(54.f * 6, 17.f * 6);
		greenThing->setPosition(instance->getWindow()->getSize().x / 2 + 250 - greenThing->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 140.f);
		redThing->setSize(54.f * 6, 17.f * 6);
		redThing->setPosition(instance->getWindow()->getSize().x / 2 - 250 - redThing->getXSize() / 2, instance->getWindow()->getSize().y / 2 + 140.f);

		versions[1]->push_back(greenThing);
		versions[1]->push_back(redThing);
	}
	else {
		CommandLevel1p2False* com1 = new CommandLevel1p2False(this);
		CommandLevel1p2True* com2 = new CommandLevel1p2True(this);

		matrixIndex = spInstance->getMatrixIndex("IsPlayer2");
		Button* greenThing = new Button(sf::Color::White, com2, true, matrixIndex);
		matrixIndex = spInstance->getMatrixIndex("IsPlayer1");
		Button* redThing = new Button(sf::Color::White, com1, true, matrixIndex);

		greenThing->setSize(54.f * 6, 17.f * 6);
		greenThing->setPosition(instance->getWindow()->getSize().x / 2 + 250 - greenThing->getXSize() / 2, instance->getWindow()->getSize().y / 2 - 40.f);
		redThing->setSize(54.f * 6, 17.f * 6);
		redThing->setPosition(instance->getWindow()->getSize().x / 2 - 250 - redThing->getXSize() / 2, instance->getWindow()->getSize().y / 2 - 40.f);

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