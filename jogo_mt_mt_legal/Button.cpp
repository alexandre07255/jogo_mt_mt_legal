#include "Button.h"
#include "inputManager.h"
#include "GraphicManager.h"
#include "LevelSave.h"
#include "SpriteManager.h"
using namespace Managers;
using namespace Entities;

Button::Button(sf::Color col, Command* _com,bool repeat, const int matriIndex) : Entity(), defaultColor(col), repeatable(repeat) {
	InputManager* instance = InputManager::getInstance();
	mouse = instance->getMouse();
	setSize(200.f,100.f);
	//setTextureBeing(text);
	setFillColor(defaultColor);
	clickable = true;
	com = _com;
	spriteMatrixIndex = matriIndex;
}

Button::~Button() {
	delete com;
}

const bool Button::isMouseOn() {
	GraphicManager* instance = GraphicManager::getInstance();
	sf::RenderWindow* window = instance->getWindow();

	int mouseX = mouse->getPosition(*window).x;
	int mouseY = mouse->getPosition(*window).y;

	sf::FloatRect mouseRect;
	mouseRect.left = mouseX;
	mouseRect.top = mouseY;
	mouseRect.width = 1;
	mouseRect.height = 1;

	sf::FloatRect bound = getGlobalBounds();

	if (mouseRect.intersects(bound)){
		return true;
	}

	return false;
}

const bool Button::isMouseClicked() {
	if (isMouseOn() && mouse->isButtonPressed(sf::Mouse::Left))
		return true;
	return false;
}

void Button::execute() {
	if (isMouseOn() && clickable) {
		InputManager* iInstance = InputManager::getInstance();
		if (spriteMatrixIndex >= 0)
			spriteY = 1;
		else
			setFillColor(sf::Color::Yellow);

		if (mouse->isButtonPressed(sf::Mouse::Left)) {
			if (!iInstance->getWasLMBPressed())
			{
				com->execute();
				if (!repeatable)
					clickable = false;
			}
			iInstance->setWasLMBPressed(1);
		}
		else
			iInstance->setWasLMBPressed(0);
	}
	
	else {
		if (spriteMatrixIndex >= 0)
			spriteY = 0;
		else
			setFillColor(defaultColor);
	}
	if (spriteMatrixIndex >= 0)
	{
		SpriteManager* spInstance = SpriteManager::getInstance();

		spInstance->getTexture(this, spriteMatrixIndex,spriteX, spriteY);
	}
}

void Button::save(LevelSave* save) {
	cout << "botao salvado com sucesso :3" << endl;
}