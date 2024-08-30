#include "ScoreSave.h"
#include "inputManager.h"

Managers::GraphicManager* ::ScoreSave::pGraphic(Managers::GraphicManager::getInstance());

void ScoreSave::savePlayer(int score) {
	addScore(*name, score);
}

void ScoreSave::addScore(std::string name, int score) {
	saveJson = readJson("saves.json");

	saveJson[name] = static_cast<char>(score);

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

ScoreSave::~ScoreSave()
{
	delete name;
}

bool ScoreSave::appendLetter() {
	Managers::InputManager* instance = Managers::InputManager::getInstance();
	sf::RenderWindow* window = pGraphic->getWindow();
	sf::Event event;

	if (!instance->isKeyPressed(sf::Keyboard::Key::Enter)) {
		window->pollEvent(event);
		if (event.type == sf::Event::TextEntered) {
			if (!keyPressed) { name->push_back(event.text.unicode); }

			keyPressed = true;
		}
		else {
			keyPressed = false;
		}
		return true;
	}
	else {
		return false;
	}
}
