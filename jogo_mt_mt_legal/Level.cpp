#include "Level.h"
#include "GraphicManager.h"
#include "Player.h"
#include "CollisionManager.h"
#include "EnemyMelee.h"
#include "EnemyRanged.h"
#include "EnemyBoss.h"
#include "SceneManager.h"
#include "PauseMenu.h"
#include "inputManager.h"
#include "Platform.h"
#include "Spike.h"
#include "Fire.h"
#include "Terrain.h"
#include "LevelSave.h"
using namespace std;
using namespace Scenes;
using namespace Managers;
using namespace Entities::Characters;
using namespace Entities;
using namespace Lists;
using namespace Entities::Obstacles;



Level::Level(): enemyVector(NULL),collidables(NULL), pPlayer1(NULL), pPlayer2(NULL), supportVector(NULL), obstacleList(NULL)
{
    enemyVector = new vector<Enemy*>;
    collidables = new list<Collidable*>;
	supportVector = new vector<Support*>;
	obstacleList = new list<Obstacle*>;
}

Level::~Level() //TODO
{
}

void Level::execute()
{
	entityList->traverse();
	manageCollisions();
	levelCompleteChecker();
	escChecker();
}

void Level::escResolver()
{
	PauseMenu* pMenu = new PauseMenu(this);
	SceneManager::getInstance()->push(pMenu);
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
			i--;
			size--;
		}
	}

}


Player* Level::getPlayer1() const { return pPlayer1; }

Player* Level::getPlayer2() const { return pPlayer2; }


void Level::stackPauseMenu() {
	SceneManager* instance = SceneManager::getInstance();

	PauseMenu* pMenu;
	pMenu = new PauseMenu(this);

	instance->push(pMenu);
	
	GraphicManager* graph = GraphicManager::getInstance();
	sf::RenderWindow* window = graph->getWindow();

	window->setView(window->getDefaultView());
}

void Level::save() {
	LevelSave* save = new LevelSave(this);

	entityList->saveAll(save);

	save->saveFinal();
}

void Level::createEnemyMelee(const float x, const float y, const int points)
{
	EnemyMelee* enemy = new EnemyMelee;
	enemy->setPosition(x, y);
	enemy->setPoints(points);
	entityList->push_back(enemy);
	enemyVector->push_back(enemy);
}

void Level::createEnemyRanged(const float x, const float y, const int points)
{
	EnemyRanged* enemy = new EnemyRanged;
	enemy->setPosition(x, y);
	enemy->setPoints(points);
	entityList->push_back(enemy);
	enemyVector->push_back(enemy);
}

void Level::createEnemyBoss(const float x, const float y, const int points)
{
	//EnemyBoss* enemy = new EnemyBoss;
	//enemy->setPosition(x, y);
	//enemy->setPoints(points);
	//entityList->push_back(enemy);
	//enemyVector->push_back(enemy);
}

void Level::createPlatform(const float x, const float y, const float xSize, const float ySize)
{
	Platform* obst = new Platform(x, y, xSize, ySize);
	entityList->push_back(obst);
	obstacleList->push_back(obst);
	collidables->push_back(obst);
}

void Level::createSpike(const float x, const float y, const float xSize, const float ySize)
{
	Spike* obst = new Spike;
	obst->setPosition(x, y);
	obst->setSize(xSize, ySize);
	entityList->push_back(obst);
	obstacleList->push_back(obst);
}

void Level::createFire(const float x, const float y, const float xSize, const float ySize)
{
	Fire* obst = new Fire;
	obst->setPosition(x, y);
	obst->setSize(xSize, ySize);
	entityList->push_back(obst);
	obstacleList->push_back(obst);
}

void Level::createTerrain(const float x, const float y, const float xSize, const float ySize, const float frict)
{
	Terrain* ter = new Terrain(frict);
	ter->setPosition(x, y);
	ter->setSize(xSize, ySize);
	entityList->push_back(ter);
	collidables->push_back(ter);
}

void Level::createPlayer1(const float x, const float y, const int points, const int hp)
{
	if (pPlayer1) { return; }
	
	Player* player1 = new Player(0, hp);
	pPlayer1 = player1;
	entityList->push_back(player1);
}

void Level::createPlayer1(const float x, const float y, const int points)
{
	if (pPlayer1) { return; }

	Player* player1 = new Player(0);
	player1->setPosition(8 * SCALE, 25 * SCALE);
	pPlayer1 = player1;
	entityList->push_back(player1);
}

void Level::createPlayer2(const float x, const float y, const int points, const int hp)
{
	if (pPlayer2) { return; }

	Player* player2 = new Player(1, hp);
	player2->setPosition(9 * SCALE, 25 * SCALE);
	pPlayer2 = player2;
	entityList->push_back(player2);
}

void Level::createPlayer2(const float x, const float y, const int points)
{
	if (pPlayer2) { return; }

	Player* player2 = new Player(1);
	pPlayer2 = player2;
	entityList->push_back(player2);
}

const float Level::SCALE(16 * 5.33333f);