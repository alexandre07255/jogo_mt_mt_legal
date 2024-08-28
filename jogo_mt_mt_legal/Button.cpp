#include "Button.h"
#include "inputManager.h"
#include "GraphicManager.h"
using namespace Managers;
using namespace Entities;

Button::Button(sf::Color col, Command* _com,bool repeat) : Entity(), defaultColor(col), repeatable(repeat) {
	InputManager* instance = InputManager::getInstance();
	mouse = instance->getMouse();
	setSizeEntity(200.f,100.f);
	//setTextureBeing(text);
	setColorBeing(defaultColor);
	clickable = true;
	com = _com;
}

Button::~Button() {
	delete com;
}

const bool Button::isMouseOn() {
	GraphicManager* instance = GraphicManager::getInstance();
	sf::RenderWindow* window = instance->getWindow();

	int mouseX = mouse->getPosition(*window).x;
	int mouseY = mouse->getPosition(*window).y;

	if (mouseX >= getPosition().x && mouseX <= getPosition().x + getSize().x) {
		if (mouseY >= getPosition().y && mouseY <= getPosition().y + getSize().y)
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
		setColorBeing(sf::Color::Yellow);
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
		setColorBeing(defaultColor);
	}
}

void Button::save() {
	cout << "botao salvado com sucesso :3" << endl;
}