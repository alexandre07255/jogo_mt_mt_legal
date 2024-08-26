#include "MainMenu.h"
#include "SceneManager.h"
#include "Level1.h"
#include "Level2.h"
#include <iostream>
#include "CommandStack1.h"
#include "CommandStack2.h"
#include "CommandStart.h"
#include "GraphicManager.h"
#include "inputManager.h"
using namespace std;

MainMenu::MainMenu():version(0){

	GraphicManager* instance = GraphicManager::getInstance();

	updatableVersions = new vector<List<Updatable>*>;
	myDrawableVersions = new vector<List<MyDrawable>*>;
	buttonVersions = new vector<List<Button>*>;

	List<Updatable>* updatableMain = new List<Updatable>;
	updatableVersions->push_back(updatableMain);

	List<MyDrawable>* MyDrawableMain = new List<MyDrawable>;
	myDrawableVersions->push_back(MyDrawableMain);

	List<Button>* ButtonMain = new List<Button>;
	buttonVersions->push_back(ButtonMain);

	CommandStart* com1 = new CommandStart(this);
	Button* startButton = new Button(sf::Color::Blue, com1, true);
	startButton->setPosition(instance->getWindow()->getSize().x/2, instance->getWindow()->getSize().y / 3 - 25.f);

	updatableMain->push_back(startButton);
	MyDrawableMain->push_back(startButton);
	ButtonMain->push_back(startButton);

	List<Updatable>* updatableStart = new List<Updatable>;
	updatableVersions->push_back(updatableStart);

	List<MyDrawable>* MyDrawableStart = new List<MyDrawable>;
	myDrawableVersions->push_back(MyDrawableStart);

	List<Button>* ButtonStart = new List<Button>;
	buttonVersions->push_back(ButtonStart);

	CommandStack1* com2 = new CommandStack1(this);
	CommandStack2* com3 = new CommandStack2(this);

	Button* buttonLevel1 = new Button(sf::Color::Blue, com2, false);
	Button* buttonLevel2 = new Button(sf::Color::Blue, com3, false);

	buttonLevel1->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 - 125.f);
	buttonLevel2->setPosition(instance->getWindow()->getSize().x / 2, instance->getWindow()->getSize().y / 2 + 125.f);

	updatableStart->push_back(buttonLevel1);
	MyDrawableStart->push_back(buttonLevel1);
	ButtonStart->push_back(buttonLevel1);

	updatableStart->push_back(buttonLevel2);
	MyDrawableStart->push_back(buttonLevel2);
	ButtonStart->push_back(buttonLevel2);

	List<Updatable>* updatableOptions = new List<Updatable>;
	updatableVersions->push_back(updatableOptions);

	List<MyDrawable>* MyDrawableOptions = new List<MyDrawable>;
	myDrawableVersions->push_back(MyDrawableOptions);

	List<Button>* ButtonOptions = new List<Button>;
	buttonVersions->push_back(ButtonOptions);

	changeMainButtons();
}

void MainMenu::update() {

	InputManager* instance = InputManager::getInstance();
	if (instance->isPausePressed()) {
		if (!instance->getWasEscPressed())
		{
			goBack();
		}
		instance->setWasEscPressed(1);
	}
	else
		instance->setWasEscPressed(0);
	
	ListIterator<Updatable> itCurrent = updatables->begin();
	if (updatables->size() > 0)
	{
		ListIterator<Updatable> itNext = itCurrent;
		itNext++;
		while (itNext != updatables->end())
		{
			(*itCurrent)->movement();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->movement();
	}

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
	updatables = (*updatableVersions)[0];
	drawables = (*myDrawableVersions)[0];
	buttonList = (*buttonVersions)[0];
}
void MainMenu::changeStartButtons() {
	version = 1;
	updatables = (*updatableVersions)[1];
	drawables = (*myDrawableVersions)[1];
	buttonList = (*buttonVersions)[1];
}
void MainMenu::changeOptionsButtons() {
	version = 2;
	updatables = (*updatableVersions)[2];
	drawables = (*myDrawableVersions)[2];
	buttonList = (*buttonVersions)[2];
}

void MainMenu::goBack() {
	if (version == 0) {
		GraphicManager* instance = GraphicManager::getInstance();
		instance->getWindow()->close();
	}
	else {
		changeMainButtons();
	}
}