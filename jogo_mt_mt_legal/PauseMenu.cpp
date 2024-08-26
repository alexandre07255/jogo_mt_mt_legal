#include "PauseMenu.h"
#include "inputManager.h"
#include "SceneManager.h"
#include "CommandQuit.h"

PauseMenu::PauseMenu(){
	CommandQuit* com = new CommandQuit(this);

	buttonQuit = new Button(sf::Color::Blue, com, false);
	buttonQuit->setPosition(500.f, 500.f);

	updatables->push_back(buttonQuit);
	drawables->push_back(buttonQuit);
	buttonList->push_back(buttonQuit);
}

void PauseMenu::update()
{
	InputManager* instance = InputManager::getInstance();
	if (instance->isPausePressed()) {
		if (!instance->getWasEscPressed())
		{
			SceneManager* sInstance = SceneManager::getInstance();
			sInstance->pop();
		}
		instance->setWasEscPressed(1);
	}
	else
		instance->setWasEscPressed(0);

	ListIterator<Updatable> itCurrent = updatables->begin();
	if (updatables->size() > 0)
	{
		ListIterator<Updatable> itNext = itCurrent;
		itNext++;
		while (itNext != updatables->end())
		{
			(*itCurrent)->movement();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->movement();
	}

}