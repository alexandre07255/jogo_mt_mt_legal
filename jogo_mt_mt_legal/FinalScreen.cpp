#include "FinalScreen.h"
#include "SceneManager.h"
#include <iostream>
#include <windows.h>
#include "SpriteManager.h"
using namespace std;

using namespace Scenes;
using namespace Entities;
using namespace Managers;

FinalScreen::FinalScreen(int _score, bool death) {
	score = _score;
	std::string textToWrite;

	SpriteManager* spInstance = SpriteManager::getInstance();
	int matrixIndex = -1;

	text = new TextContainer;
	text->write(textToWrite);

	
	if (death)
	{
		matrixIndex = spInstance->getMatrixIndex("GameOver");
		text->setTextFillColor(sf::Color::White);
		text->setPosition(pGG->getWindow()->getSize().x / 2, pGG->getWindow()->getSize().y / 2);
		text->setTextPosition(pGG->getWindow()->getSize().x / 2 - 100.f, 2 * pGG->getWindow()->getSize().y / 3 + 50.f);
	}
	else
	{
		matrixIndex = spInstance->getMatrixIndex("HappyEnding");
		text->setTextFillColor(sf::Color::Black);
		text->setPosition(pGG->getWindow()->getSize().x / 2, pGG->getWindow()->getSize().y / 2);
		text->setTextPosition(pGG->getWindow()->getSize().x / 2 + 50.f, 2 * pGG->getWindow()->getSize().y / 3 + 50.f);
	}

	Background* background = new Background;
	spInstance->getTexture(background, matrixIndex, 0, 0);
	background->setSize(320.f * 6, 180.f * 6);
	
	entityList->push_back(background);
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