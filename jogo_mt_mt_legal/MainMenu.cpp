#include "MainMenu.h"
#include "SceneManager.h"
#include "Level1.h"

MainMenu::MainMenu() {
	level1Button = new Button;
	level1Button->setPosition(500, 500);

	drawables->push_back(level1Button);
	updatables->push_back(level1Button);
}

void MainMenu::update() {
	//chama o movement pra cada bot�o, e depois chama as coisas pra cada bot�o espec�fico, como level � uma scene, ele precisa de updatables,
	//ai a minha solu��o de movement pra bot�o foi de enfiar o negocio da cor mesmo
	list<Updatable*>::iterator itCurrent = updatables->begin();
	if (updatables->size() > 1)
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
	else if (updatables->size() == 1)
		(*itCurrent)->movement();

	if (level1Button->isMouseClicked()) {
		stackLevel1();
	}
}

void MainMenu::stackLevel1() {

	SceneManager* instance = SceneManager::getInstance();
	//cria level1 aqui? mainmenu teria um ponteiro para level1? de fato, s�o muitas perguntas, e poucas respostas
	Level1* level;
	level = new Level1(false);

	instance->push(level);

}