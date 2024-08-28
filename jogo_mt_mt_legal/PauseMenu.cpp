#include "PauseMenu.h"
#include "inputManager.h"
#include "SceneManager.h"
#include "CommandQuit.h"
#include "CommandSave.h"
using namespace Scenes;
using namespace Managers;



PauseMenu::PauseMenu(){
	CommandQuit* com1 = new CommandQuit(this);

	buttonQuit = new Button(sf::Color::Blue, com1, false);
	buttonQuit->setPosition(500.f, 500.f);

	updatables->push_back(buttonQuit);
	drawables->push_back(buttonQuit);
	buttonList->push_back(buttonQuit);

	CommandSave* com2 = new CommandSave(this);

	buttonSave = new Button(sf::Color::Blue, com2, true);
	buttonSave->setPosition(500.f,700.f);

	updatables->push_back(buttonSave);
	drawables->push_back(buttonSave);
	buttonList->push_back(buttonSave);
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

	list<Updatable>::iterator itCurrent = updatables->begin();
	if (updatables->size() > 0)
	{
		list<Updatable>::iterator itNext = itCurrent;
		itNext++;
		while (itNext != updatables->end())
		{
			(*itCurrent)->execute();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->execute();
	}

}