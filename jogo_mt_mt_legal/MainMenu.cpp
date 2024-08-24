#include "MainMenu.h"
#include "SceneManager.h"
#include "Level1.h"
#include <iostream>
#include "CommandStack1.h"
using namespace std;

MainMenu::MainMenu() {
	CommandStack1* com = new CommandStack1(this);
	level1Button = new Button(sf::Color::Blue,com);
	level1Button->setPosition(500, 500);

	buttonList->push_back(level1Button);
	drawables->push_back(level1Button);
	updatables->push_back(level1Button);
}

void MainMenu::update() {
	
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

void MainMenu::stackLevel1(bool player2) {

	SceneManager* instance = SceneManager::getInstance();
	//cria level1 aqui? mainmenu teria um ponteiro para level1? de fato, são muitas perguntas, e poucas respostas
	Level1* level;
	level = new Level1(player2);

	instance->push(level);

}
