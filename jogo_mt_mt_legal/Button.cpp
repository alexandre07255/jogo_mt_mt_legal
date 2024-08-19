#include "Button.h"
#include "inputManager.h"

Button::Button() :Entity() {
	InputManager* instance = InputManager::getInstance();
	mouse = instance->getMouse();
	setSize(sf::Vector2f(200,100));
	setFillColor(sf::Color::Blue);
}

const bool Button::isMouseOn() {
	int mouseX = mouse->getPosition().x;
	int mouseY = mouse->getPosition().y;

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
	if (isMouseOn()) {
		setFillColor(sf::Color::Green);
	}
	else {
		setFillColor(sf::Color::Blue);
	}
}