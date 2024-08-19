#include "MainMenu.h"
#include "SceneManager.h"
#include "Level1.h"
#include <iostream>
using namespace std;

MainMenu::MainMenu() {
	level1Button = new Button(Button::Actions::startLevel1);
	level1Button->setPosition(500, 500);

	buttonList->push_back(level1Button);
	drawables->push_back(level1Button);
	updatables->push_back(level1Button);
}

void MainMenu::update() {
	//chama o movement pra cada botão, e depois chama as coisas pra cada botão específico, como level é uma scene, ele precisa de updatables,
	//ai a minha solução de movement pra botão foi de enfiar o negocio da cor mesmo
	list<Updatable*>::iterator itCurrent = updatables->begin();
	if (updatables->size() > 0)
	{
		list<Updatable*>::iterator itNext = itCurrent;
		itNext++;
		while (itNext != updatables->end())
		{
			(*itCurrent)->movement();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->movement();
	}

	list<Button*>::iterator itButton = buttonList->begin();
	if (buttonList->size() > 0)
	{
		list<Button*>::iterator itButtonNext = itButton;
		itButtonNext++;
		while (itButtonNext != buttonList->end())
		{
			if ((*itButton)->isMouseClicked()) {
				switch ((*itButton)->getAction())
				{
				case Button::Actions::startLevel1:
					stackLevel1();
					break;
				case Button::Actions::startLevel2:
					break;
				}
			}
			itButton = itButtonNext;
			itButtonNext++;
		}
		if ((*itButton)->isMouseClicked()) {
			switch ((*itButton)->getAction())
			{
			case Button::Actions::startLevel1:
				stackLevel1();
				break;
			case Button::Actions::startLevel2:
				break;
			}
		}
	}
}

void MainMenu::stackLevel1() {

	SceneManager* instance = SceneManager::getInstance();
	//cria level1 aqui? mainmenu teria um ponteiro para level1? de fato, são muitas perguntas, e poucas respostas
	Level1* level;
	level = new Level1(0);

	instance->push(level);

}