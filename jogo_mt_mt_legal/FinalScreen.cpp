#include "FinalScreen.h"
#include "SceneManager.h"
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

	entityList->push_back(text);

	save = new ScoreSave;
}

void FinalScreen::execute() {
	entityList->drawAll();
	if (!save->appendLetter()) {
		SceneManager* sInstance = SceneManager::getInstance();
		while (sInstance->size() > 1) {
			sInstance->pop();
		}
	}
}

void FinalScreen::escResolver() {
}