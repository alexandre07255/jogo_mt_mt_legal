#include "Level.h"
#include "GraphicManager.h"
#include "Player.h"
#include "CollisionManager.h"
#include "EnemyMelee.h"
#include "SceneManager.h"
#include "PauseMenu.h"
#include "inputManager.h"

Level::Level(): hittableList(NULL),collidables(NULL), endX(0), endingOnRight(1), pPlayer1(NULL), pPlayer2(NULL)
{
    hittableList = new List<Hittable>;
    collidables = new List<Collidable>;
}

Level::~Level() //TODO
{
}

void Level::update()
{
	InputManager* instance = InputManager::getInstance();
	if (instance->isKeyPressed(sf::Keyboard::Key::Escape)) {
		stackPauseMenu();
	}

	else {
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

		if (endingOnRight)
		{
			if (pPlayer1->getPosition().x + pPlayer1->getSize().x / 2 > endX)
				levelCompleteHandler();
			else if (pPlayer2 != NULL)
				if (pPlayer2->getPosition().x + pPlayer2->getSize().x / 2 > endX)
					levelCompleteHandler();
		}
		else
		{
			if (pPlayer1->getPosition().x + pPlayer1->getSize().x / 2 < endX)
				levelCompleteHandler();
			else if (pPlayer2 != NULL)
				if (pPlayer2->getPosition().x + pPlayer2->getSize().x / 2 < endX)
					levelCompleteHandler();
		}
	}
}

List<Collidable>* Level::getCollidable() {
	return collidables;
}

List<Hittable>* Level::getHittableList() {
	return hittableList;
}

void Level::addHittable(Hittable* pH) {
	hittableList->push_back(pH);
}

void Level::removeHittable(Hittable* pH) {
	hittableList->remove(pH);
}

void Level::removeCollidable(Collidable* pC) {
	collidables->remove(pC);
}

void Level::stackPauseMenu() {
	SceneManager* instance = SceneManager::getInstance();

	PauseMenu* pMenu;
	pMenu = new PauseMenu;

	instance->push(pMenu);
	
	GraphicManager* graph = GraphicManager::getInstance();
	sf::RenderWindow* window = graph->getWindow();

	window->setView(window->getDefaultView());
}
