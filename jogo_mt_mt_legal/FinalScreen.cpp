#include "FinalScreen.h"
#include "SceneManager.h"
#include <iostream>
#include <windows.h>
using namespace std;

using namespace Scenes;
using namespace Entities;
using namespace Managers;

FinalScreen::FinalScreen(int _score, bool death) {
	score = _score;
	std::string textToWrite;
	if (death) {
		textToWrite = "Verme imundo";
	}
	else {
		textToWrite = "Te amo";
	}

	text = new TextContainer;
	text->write(textToWrite);
	text->setPosition(pGG->getWindow()->getSize().x/2, pGG->getWindow()->getSize().y / 2);
	text->setTextPosition(pGG->getWindow()->getSize().x / 2, pGG->getWindow()->getSize().y / 2);

	entityList->push_back(text);

	save = new ScoreSave;
	text->setFillColor(sf::Color::Transparent);
}

FinalScreen::~FinalScreen()
{
	//delete text;
	delete save;
}

void FinalScreen::execute() {
	
	entityList->drawAll();
	if (save->appendLetter())
	{
		Sleep(140);
		text->write(*save->getName());
	}
	escChecker();
	/*std::string* name = new std::string;
	std::cin >> *name;
	save->setName(name);
	save->savePlayer(score);
	SceneManager* sInstance = SceneManager::getInstance();
	while (sInstance->size() > 1) {
		sInstance->pop();
	}*/
}

void FinalScreen::escResolver() {
	save->savePlayer(score);
	SceneManager* sInstance = SceneManager::getInstance();
	while (sInstance->size() > 1) {
		sInstance->pop();
	}
}