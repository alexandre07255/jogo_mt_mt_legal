#include "Level.h"
#include "GraphicManager.h"
#include "Player.h"
#include "CollisionManager.h"
#include "EnemyMelee.h"
#include "SceneManager.h"
#include "PauseMenu.h"
#include "inputManager.h"
using namespace std;
using namespace Scenes;
using namespace Managers;
using namespace Entities::Characters;
using namespace Entities;
using namespace Lists;




Level::Level(): enemyVector(NULL),collidables(NULL), endX(0), endingOnRight(1), pPlayer1(NULL), pPlayer2(NULL), supportVector(NULL)
{
    enemyVector = new vector<Enemy*>;
    collidables = new list<Collidable*>;
	supportVector = new vector<Support*>;
}

Level::~Level() //TODO
{
}

void Level::excute()
{
	entityList->traverse();
	manageCollisions();
	entityList->drawAll();
}

void Level::manageCollisions()
{
	CollisionManager* cInstance = CollisionManager::getInstance();
	cInstance->testHittableToObstacleCollisions();
	cInstance->testPlayerToEnemyCollision();
	cInstance->testHittableToCollidableCollisions();
}

list<Collidable*>* Level::getCollidables() {
	return collidables;
}

vector<Enemy*>* Level::getEnemyVector() {
	return enemyVector;
}

void Level::addEnemy(Enemy* pE) {
	enemyVector->push_back(pE);
}

void Level::removeEnemy(Enemy* pE) {
	if (!enemyVector) { return; }

	int size = enemyVector->size();
	for (int i = 0; i < size; i++)
	{
		if (enemyVector->at(i) == pE)
		{
			vector<Enemy*>::iterator it = enemyVector->begin() + i;
			enemyVector->erase(it);
			delete (*it);
			i--;
			size--;
		}
	}
}

void Level::removeCollidable(Collidable* pC) {
	collidables->remove(pC);
}

vector<Support*>* Level::getSupportVector() { return supportVector; }
void Level::addSupport(Support* pS) { if (supportVector) supportVector->push_back(pS); }
void Level::removeSupport(Support* pS)
{
	if (!supportVector) { return; }
	
	int size = supportVector->size();
	for (int i = 0; i < size; i++)
	{
		if (supportVector->at(i) == pS)
		{
			vector<Support*>::iterator it = supportVector->begin() + i;
			supportVector->erase(it);
			delete (*it);
			i--;
			size--;
		}
	}

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
