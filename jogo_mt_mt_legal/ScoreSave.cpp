#include "ScoreSave.h"
#include "Game.h"
#include "SceneManager.h"
using namespace Managers;
using namespace Scenes;

Managers::GraphicManager* ::ScoreSave::pGraphic(Managers::GraphicManager::getInstance());

void ScoreSave::savePlayer(int score) {
	addScore(*name, score);
}

void ScoreSave::addScore(std::string name, int score) {
	saveJson = readJson("saves/score_save.json");
	
	std::string stringScore = std::to_string(score);

	saveJson[name] = stringScore;

	writejson("saves/score_save.json", saveJson);
}

ScoreSave::ScoreSave(){
	keyPressed = false;
	name = new std::string;
}

ScoreSave::~ScoreSave()
{
	delete name;
}


const bool ScoreSave::appendLetter() {
	Managers::InputManager* instance = Managers::InputManager::getInstance();
	sf::RenderWindow* window = pGraphic->getWindow();
	sf::Event* event = Game::getEvent();

	if (event->type == sf::Event::TextEntered)
	{
		if (event->text.unicode == '\b' && !name->empty())
		{
			name->pop_back();
			return 1;
		}
		else if (event->text.unicode < 128 && event->text.unicode != 27)
		{
			name->push_back(event->text.unicode);
			return 1;
		}
	}
	
	return 0;
}

void ScoreSave::setName(std::string* nm) {
	name = nm;
}

std::string* ScoreSave::getName() {
	return name;
}
