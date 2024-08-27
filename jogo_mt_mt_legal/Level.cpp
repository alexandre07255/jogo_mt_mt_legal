#include "Level.h"
#include "GraphicManager.h"
#include "Player.h"
#include "CollisionManager.h"
#include "EnemyMelee.h"
#include "SceneManager.h"
#include "PauseMenu.h"
#include "inputManager.h"
using namespace Scenes;
using namespace Managers;
using namespace Entities::Characters;



Level::Level(): hittableList(NULL),collidables(NULL), endX(0), endingOnRight(1), pPlayer1(NULL), pPlayer2(NULL), backgroundAndLevel(NULL)
{
    hittableList = new list<Hittable*>;
    collidables = new list<Collidable*>;
}

Level::~Level() //TODO
{
}

void Level::update()
{
	List<Updatable>::Iterator itCurrent = updatables->begin();
	if (updatables->size() > 0)
	{
		List<Updatable>::Iterator itNext = itCurrent;
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
	

	InputManager* instance = InputManager::getInstance();
	if (instance->isPausePressed()) {
		if (!instance->getWasEscPressed())
			stackPauseMenu();
		instance->setWasEscPressed(1);
	}
	else
		instance->setWasEscPressed(0);
}

list<Collidable*>* Level::getCollidable() {
	return collidables;
}

list<Hittable*>* Level::getHittableList() {
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
