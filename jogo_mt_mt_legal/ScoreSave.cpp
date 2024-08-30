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

/*std::string ScoreSave::listen() {
	Managers::InputManager* instance = Managers::InputManager::getInstance();

	std::string name;
	sf::RenderWindow* window = pGraphic->getWindow();
	sf::Event event;
	bool isEnterPressed = false;
	char before = '/0';
	char after;

	do {
		window->pollEvent(event);
		if (event.type == sf::Event::TextEntered) {
			after = event.text.unicode;
			std::cout << after << endl;
			if (after != before) {
				name.push_back(after);
				before = after;
			}
		}
		if (instance->isKeyPressed(sf::Keyboard::Enter)) {
			isEnterPressed = true;
		}
	} while (!isEnterPressed);

	return name;
}*/

ScoreSave::ScoreSave(){
	keyPressed = false;
	name = new std::string;
}

bool ScoreSave::appendLetter() {
	Managers::InputManager* instance = Managers::InputManager::getInstance();
	sf::RenderWindow* window = pGraphic->getWindow();
	sf::Event event;

	window->pollEvent(event);

	if (event.type == sf::Event::TextEntered) {
		
		if (!keyPressed) { name->push_back(event.text.unicode); }
		
		
		else {
			return false;
		}
		std::cout << event.text.unicode << endl;

		keyPressed = true;
	}
	else {
		keyPressed = false;
	}
	return true;
}

void ScoreSave::setName(std::string* nm) {
	name = nm;
}