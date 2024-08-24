#include "Button.h"
#include "inputManager.h"
#include "GraphicManager.h"

Button::Button(sf::Color col, Command* _com) : Entity(), defaultColor(col) {
	InputManager* instance = InputManager::getInstance();
	mouse = instance->getMouse();
	setSize(sf::Vector2f(200,100));
	setFillColor(defaultColor);
	clickable = true;
	com = _com;
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

void Button::movement() {
	if (isMouseOn() && clickable) {
		setFillColor(sf::Color::Yellow);
	}
	if (isMouseClicked()) {
		com->execute();
	}
	
	else {
		setFillColor(defaultColor);
	}
}