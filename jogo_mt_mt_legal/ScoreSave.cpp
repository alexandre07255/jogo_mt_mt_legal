#include "ScoreSave.h"
#include "inputManager.h"

Managers::GraphicManager* ::ScoreSave::pGraphic(Managers::GraphicManager::getInstance());

void ScoreSave::savePlayer(int score) {
	addScore(*name, score);
}

void ScoreSave::addScore(std::string name, int score) {
	saveJson = readJson("saves.json");
	
	std::string stringScore = std::to_string(score);

	saveJson[name] = stringScore;

	writejson("saves.json", saveJson);
}

ScoreSave::ScoreSave(){
	keyPressed = false;
	name = new std::string;
}

void ScoreSave::appendLetter() {
	Managers::InputManager* instance = Managers::InputManager::getInstance();
	sf::RenderWindow* window = pGraphic->getWindow();
	sf::Event event;

	while (window->pollEvent(event)) {

		if (event.type == sf::Event::TextEntered) {

			name->push_back(event.text.unicode);
			
		}
	}
}

void ScoreSave::setName(std::string* nm) {
	name = nm;
}

std::string* ScoreSave::getName() {
	return name;
}
