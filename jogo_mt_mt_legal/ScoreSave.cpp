#include "ScoreSave.h"
#include "inputManager.h"

Managers::GraphicManager* ::ScoreSave::pGraphic(Managers::GraphicManager::getInstance());

void ScoreSave::savePlayer(int score) {
	std::string name = listen();
	addScore(name, score);
}

void ScoreSave::addScore(std::string name, int score) {
	saveJson = readJson("saves.json");

	saveJson[name] = score;

	writejson("saves.json", saveJson);
}

std::string ScoreSave::listen() {
	Managers::InputManager* instance = Managers::InputManager::getInstance();

	std::string name;
	sf::RenderWindow* window = pGraphic->getWindow();
	sf::Event event;
	bool isEnterPressed = false;

	do {
		window->pollEvent(event);
		if (event.type == sf::Event::TextEntered) {
			name.push_back(static_cast<char>(event.text.unicode));
		}
		if (instance->isKeyPressed(sf::Keyboard::Enter)) {
			isEnterPressed = true;
		}
	} while (!isEnterPressed);

	return name;
}

ScoreSave::ScoreSave(){}
