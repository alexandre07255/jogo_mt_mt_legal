#include "Button.h"
#include "inputManager.h"

Button::Button() :MyDrawable() {
	InputManager* instance = InputManager::getInstance();
	mouse = instance->getMouse();
	setSize(sf::Vector2f(200,100));
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