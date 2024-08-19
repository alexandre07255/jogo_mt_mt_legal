#include "Button.h"
#include "inputManager.h"
#include "graphics.h"

Button::Button(const int act) :Entity(), action(act) {
	InputManager* instance = InputManager::getInstance();
	mouse = instance->getMouse();
	setSize(sf::Vector2f(200,100));
	setFillColor(sf::Color::Blue);
}

const int Button::getAction() const
{
	return action;
}

const bool Button::isMouseOn() {
	Graphics* instance = Graphics::getInstance();
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
	if (isMouseOn()) {
		setFillColor(sf::Color::Green);
	}
	else {
		setFillColor(sf::Color::Blue);
	}
}