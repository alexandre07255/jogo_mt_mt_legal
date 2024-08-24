#include "MainMenu.h"
#include "SceneManager.h"
#include "Level1.h"
#include <iostream>
using namespace std;

MainMenu::MainMenu() {
	level1Button = new Button(Button::Actions::startLevel1,sf::Color::Blue);
	level1Button->setPosition(500, 500);

	buttonList->push_back(level1Button);
	drawables->push_back(level1Button);
	updatables->push_back(level1Button);
}

void MainMenu::update() {
	//chama o movement pra cada botão, e depois chama as coisas pra cada botão específico, como level é uma scene, ele precisa de updatables,
	//ai a minha solução de movement pra botão foi de enfiar o negocio da cor mesmo
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

	ListIterator<Button> itButton = buttonList->begin();
	if (buttonList->size() > 0)
	{
		ListIterator<Button> itButtonNext;
		itButtonNext = itButton;
		itButtonNext++;
		while (itButtonNext != buttonList->end())
		{
			if ((*itButton)->isMouseClicked() && (*itButton)->clickable) {
				switch ((*itButton)->getAction())
				{
				case Button::Actions::startLevel1:
					moreButtons();
					break;
				case Button::Actions::startLevel2:
					break;
				case Button::Actions::player2False:
					stackLevel1(false);
					break;
				case Button::Actions::player2True:
					stackLevel1(true);
					break;
				}
			}
			itButton = itButtonNext;
			itButtonNext++;
		}
		if ((*itButton)->isMouseClicked() && (*itButton)->clickable) {
			switch ((*itButton)->getAction())
			{
			case Button::Actions::startLevel1:
				moreButtons();
				(*itButton)->clickable = false;
				break;
			case Button::Actions::startLevel2:
				break;
			case Button::Actions::player2False:
				stackLevel1(false);
				break;
			case Button::Actions::player2True:
				stackLevel1(true);
				break;
			}
		}
	}
}

void MainMenu::stackLevel1(bool player2) {

	SceneManager* instance = SceneManager::getInstance();
	//cria level1 aqui? mainmenu teria um ponteiro para level1? de fato, são muitas perguntas, e poucas respostas
	Level1* level;
	level = new Level1(player2);

	instance->push(level);

}

void MainMenu::moreButtons() {
	player2True = new Button(Button::Actions::player2True, sf::Color::Green);
	player2True->setPosition(800, 500);

	buttonList->push_back(player2True);
	drawables->push_back(player2True);
	updatables->push_back(player2True);

	player2False = new Button(Button::Actions::player2False, sf::Color::Red);
	player2False->setPosition(200, 500);

	buttonList->push_back(player2False);
	drawables->push_back(player2False);
	updatables->push_back(player2False);
}