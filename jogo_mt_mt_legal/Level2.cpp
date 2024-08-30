#include "Level2.h"
#include"GraphicManager.h"
#include "EnemyMelee.h"
#include "EnemyRanged.h"
#include "Terrain.h"
#include "CollisionManager.h"
#include "Level2.h"
#include "SceneManager.h"
#include "Support.h"
#include "Spike.h"
#include "Fire.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Background.h"
using namespace Scenes;
using namespace Managers;
using namespace Entities::Obstacles;
using namespace Entities;
using namespace Entities::Characters;



Level2::Level2(bool isPlayer2, bool isBeingLoaded) :Level(), isBossAlive(1) {
    GraphicManager* instance = GraphicManager::getInstance();
    sf::RenderWindow* window = instance->getWindow();
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();

    srand(time(NULL));

    sf::Texture* background = new sf::Texture();
    background->loadFromFile("spritesheets/fase2EBA.png");


    float x = background->getSize().x * SCALE / 16;
    float y = background->getSize().y * SCALE / 16;

    Background* backgroundAndLevel = new Background;

    backgroundAndLevel->setSize(sf::Vector2f(x, y));
    backgroundAndLevel->setTexture(background);
    entityList->push_back(backgroundAndLevel);

    loadTerrains();

    if (!isBeingLoaded)
    {
        createFromScratch(isPlayer2);
    }
    



    Camera* view;
    view = new Camera(window);
    camera = view;
    view->setPlayer1(pPlayer1);
    if (isPlayer2)
        view->setPlayer2(pPlayer2);

    CollisionManager* cInstance = CollisionManager::getInstance();

    cInstance->setPlayer1(pPlayer1);
    cInstance->setPlayer2(pPlayer2);
    cInstance->setEnemyVector(enemyVector);
    cInstance->setSupportVector(supportVector);
    cInstance->setCollidables(collidables);
    cInstance->setObstacleList(obstacleList);

    level2 = true;
}

Level2::~Level2() {

}

void Level2::loadTerrains()
{
    createTerrain(0, 0, 7 * SCALE, 25 * SCALE, 1.f); //leftWall
    createTerrain(7 * SCALE, 26 * SCALE, 89 * SCALE, 2 * SCALE, 1.f);//floor
    createTerrain(35 * SCALE, 22 * SCALE, 2 * SCALE, 1 * SCALE, 1.f);
    createTerrain(18 * SCALE, 24 * SCALE, 1 * SCALE, 2 * SCALE, 1.f); //firstPillar
    createTerrain(21 * SCALE, 23 * SCALE, 1 * SCALE, 3 * SCALE, 1.f); //secondPillar
    createTerrain(27 * SCALE, 24 * SCALE, 25 * SCALE, 2 * SCALE, 1.f); //bigRetangulo
    createTerrain(28 * SCALE, 23 * SCALE, 24 * SCALE, 1 * SCALE, 1.f); //tripa
    createTerrain(44 * SCALE, 21 * SCALE, 3 * SCALE, 2 * SCALE, 1.f); //retangulo
    createTerrain(63 * SCALE, 25 * SCALE, 5 * SCALE, 1 * SCALE, 1.f); //fourthTerrain
    createTerrain(64 * SCALE, 24 * SCALE, 4 * SCALE, 1 * SCALE, 1.f); //fifthTerrain
    createTerrain(65 * SCALE, 23 * SCALE, 3 * SCALE, 1 * SCALE, 1.f); //sixthTerrain
    createTerrain(66 * SCALE, 22 * SCALE, 2 * SCALE, 1 * SCALE, 1.f); //seventhTerrain
    createTerrain(90 * SCALE, 0 * SCALE, 6 * SCALE, 26 * SCALE, 1.f); //rightWall
}

void Level2::createFromScratch(const bool isPlayer2)
{
    createFire(22 * SCALE, 25 * SCALE, 5 * SCALE, 1 * SCALE);
    createFire(48 * SCALE, 22 * SCALE, 3 * SCALE, 1 * SCALE);
    createFire(57 * SCALE, 25 * SCALE, 3 * SCALE, 1 * SCALE);
    if (rand() % 2)
        createFire(29 * SCALE, 22 * SCALE, 1 * SCALE, 1 * SCALE);
    if (rand() % 2)
        createFire(19 * SCALE, 25 * SCALE, 2 * SCALE, 1 * SCALE);
    if (rand() % 2)
        createFire(67 * SCALE, 21 * SCALE, 1 * SCALE, 1 * SCALE);


    createPlatform(30 * SCALE, 20 * SCALE, 3 * SCALE, SCALE);
    createPlatform(39 * SCALE, 21 * SCALE, 2 * SCALE, SCALE);
    createPlatform(53 * SCALE, 24 * SCALE, 3 * SCALE, SCALE);
    if (rand() % 2)
        createPlatform(13 * SCALE, 24 * SCALE, 2 * SCALE, SCALE);
    if (rand() % 2)
        createPlatform(46 * SCALE, 19 * SCALE, SCALE, SCALE);
    if (rand() % 2)
        createPlatform(51 * SCALE, 21 * SCALE, SCALE, SCALE);


    createPlayer1(8 * SCALE, 20 * SCALE, 0);

    if (isPlayer2)
        createPlayer2(9 * SCALE, 20 * SCALE, 0);

    createEnemyMelee(31 * SCALE, 22 * SCALE, 0);
    createEnemyMelee(44 * SCALE, 20 * SCALE, 0);
    createEnemyMelee(54 * SCALE, 23 * SCALE, 0);

    createEnemyRanged(21 * SCALE, 22 * SCALE, 0);
    createEnemyRanged(36 * SCALE, 21 * SCALE, 0);
    createEnemyRanged(46 * SCALE, 20 * SCALE, 0);
}

void Level2::levelCompleteHandler()
{
    Level2* level2 = new Level2(pPlayer2 != NULL,false);
    SceneManager* sceneManInstance = SceneManager::getInstance();
    sceneManInstance->pop();
    //Deletar Level2
    sceneManInstance->push(level2);
}

void Level2::setIsBossAlive(const bool ba)
{
    isBossAlive = ba;
}

void Level2::levelCompleteChecker()
{
    
}