#include "Level1.h"
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
#include "SpriteManager.h"
#include "TextContainer.h"
using namespace Scenes;
using namespace Managers;
using namespace Entities::Obstacles;
using namespace Entities;
using namespace Entities::Characters;


Level1::Level1(bool isPlayer2, bool isBeingLoaded):Level(), endX(0), endingOnRight(1),player1Hp(NULL),player2Hp(NULL) {
    GraphicManager* instance = GraphicManager::getInstance();
    sf::RenderWindow* window = instance->getWindow();
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();

    srand(time(NULL));

    SpriteManager* spInstance = SpriteManager::getInstance();

    int index = spInstance->getMatrixIndex("Background");
    Background* trueBackground = new Background;
    trueBackground->setSize(320.f * SCALE/ 21, 180.f * SCALE/ 21);

    spInstance->getTexture(trueBackground, index, 0, 0);

    //trueBackground->setPosition(0.f, 0.f);
    entityList->push_back(trueBackground);


    sf::Texture* background = new sf::Texture();
    background->loadFromFile("HizaSprites/Environment/fase1EBA.png");

    float x = background->getSize().x * SCALE/16;
    float y = background->getSize().y * SCALE/16;

    Background* backgroundAndLevel = new Background;

    backgroundAndLevel->setSize(sf::Vector2f(x, y));
    backgroundAndLevel->setTexture(background);
    entityList->push_back(backgroundAndLevel);




    loadTerrains();

    if (!isBeingLoaded)
        createFromScratch(isPlayer2);
    
    player1Hp = new TextContainer;
    entityList->push_back(player1Hp);
    player1Hp->setSize(SCALE/2, SCALE/2);
    index = spInstance->getMatrixIndex("SamuraiRedIcon");
    player1Hp->setTextFillColor(sf::Color::Black);
    spInstance->getTexture(player1Hp,index,0,0);
    if (isPlayer2) {
        player2Hp = new TextContainer;
        player2Hp->setSize(SCALE/2, SCALE/2);
        entityList->push_back(player2Hp);
        index = spInstance->getMatrixIndex("SamuraiBlueIcon");
        player2Hp->setTextFillColor(sf::Color::Black);
        spInstance->getTexture(player2Hp, index, 0, 0);
    }

    Camera* view;
    view = new Camera(window, trueBackground,player1Hp,player2Hp);
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

    endingOnRight = 1;
    endX = 1440 * SCALE / 16 - SCALE;

    level2 = false;
}

TextContainer* Level1::getTextContainer(bool isPlayer2) {
    if (isPlayer2) {
        return player2Hp;
    }
    return player1Hp;
}

Level1::~Level1() {

}

void Level1::loadTerrains()
{
    createTerrain(0, 0, 7 * SCALE, 26 * SCALE, 1.f); //leftWall
    createTerrain(7 * SCALE, 26 * SCALE, 89 * SCALE, 2 * SCALE, 1.f); //floor
    createTerrain(14 * SCALE, 24 * SCALE, 7 * SCALE, 2 * SCALE, 1.f); //firstTerrain
    createTerrain(27 * SCALE, 25 * SCALE, 3 * SCALE, 1 * SCALE, 1.f); //secondTerrain
    createTerrain(44 * SCALE, 25 * SCALE, 1 * SCALE, 1 * SCALE, 1.f); //littleBlock
    createTerrain(45 * SCALE, 23 * SCALE, 45 * SCALE, 3 * SCALE, 1.f); //megaRetangulo
    createTerrain(54 * SCALE, 22 * SCALE, 18 * SCALE, 1 * SCALE, 1.f); //thirdTerrain
    createTerrain(61 * SCALE, 21 * SCALE, 8 * SCALE, 1 * SCALE, 1.f); //fourthTerrain
    createTerrain(79 * SCALE, 21 * SCALE, 1 * SCALE, 2 * SCALE, 1.f); //fifthTerrain
    createTerrain(84 * SCALE, 22 * SCALE, 6 * SCALE, 1 * SCALE, 1.f); //sixthTerrain
    createTerrain(86 * SCALE, 21 * SCALE, 1 * SCALE, 1 * SCALE, 1.f); //seventhTerrain
    createTerrain(90 * SCALE, 6 * SCALE, 1 * SCALE, 30 * SCALE, 1.f); //rightWall
}

void Level1::createFromScratch(const bool isPlayer2)
{
    createSpike(33 * SCALE, 25 * SCALE, 3 * SCALE, 1 * SCALE / 2);
    createSpike(57 * SCALE, 21 * SCALE, 4 * SCALE, 1 * SCALE / 2);
    createSpike(65 * SCALE, 20 * SCALE, 3 * SCALE, 1 * SCALE / 2);
    if (rand() % 2)
        createSpike(28 * SCALE, 24 * SCALE, 1 * SCALE, 1 * SCALE / 2);
    if (rand() % 2)
        createSpike(84 * SCALE, 21 * SCALE, 2 * SCALE, 1 * SCALE / 2);
    if (rand() % 2)
        createSpike(79 * SCALE, 20 * SCALE, 1 * SCALE, 1 * SCALE / 2);


    createPlatform(37 * SCALE, 23 * SCALE, 3 * SCALE, SCALE);
    createPlatform(49 * SCALE, 19 * SCALE, 3 * SCALE, SCALE);
    createPlatform(70 * SCALE, 18 * SCALE, 2 * SCALE, SCALE);
    if (rand() % 2)
        createPlatform(28 * SCALE, 23 * SCALE, 1 * SCALE, SCALE);
    if (rand() % 2)
        createPlatform(62 * SCALE, 18 * SCALE, 2 * SCALE, SCALE);
    if (rand() % 2)
        createPlatform(81 * SCALE, 19 * SCALE, SCALE, SCALE);


    createPlayer1(8 * SCALE, 20 * SCALE, 0);

    if (isPlayer2)
        createPlayer2(9 * SCALE, 20 * SCALE, 0);

    createEnemyMelee(23 * SCALE, 25 * SCALE, 0);
    createEnemyMelee(47 * SCALE, 22 * SCALE, 0);
    createEnemyMelee(75 * SCALE, 22 * SCALE, 0);
    if (rand() % 2)
        createEnemyMelee(17 * SCALE, 23 * SCALE, 5);
    if (rand() % 2)
        createEnemyMelee(63 * SCALE, 20 * SCALE, 5);

    createEnemyRanged(31 * SCALE, 24 * SCALE, 0);
    createEnemyRanged(55 * SCALE, 20 * SCALE, 0);
    createEnemyRanged(75 * SCALE, 20 * SCALE, 0);
    if (rand() % 2)
        createEnemyRanged(86 * SCALE, 20 * SCALE, 20);
    if (rand() % 2)
        createEnemyRanged(28 * SCALE, 23 * SCALE, 20);
}

void Level1::levelCompleteHandler()
{
    int p2Points = 0;
    if (pPlayer2)
        p2Points = pPlayer2->getPoints();
    Level2* level2 = new Level2(pPlayer2 != NULL,false, pPlayer1->getPoints(), p2Points);
    SceneManager* sceneManInstance = SceneManager::getInstance();
    sceneManInstance->pop();
    //Deletar level1
    sceneManInstance->push(level2);
}

void Level1::levelCompleteChecker()
{
    bool completed = 0;
    if (pPlayer1)
    {
        if (endingOnRight)
        {
            if (pPlayer1->getXPosition() >= endX)
                completed = 1;
        }
        else if (pPlayer1->getXPosition() <= endX)
            completed = 1;
    }

    if (pPlayer2)
    {
        if (endingOnRight)
        {
            if (pPlayer2->getXPosition() >= endX)
                completed = 1;
        }
        else if (pPlayer2->getXPosition() <= endX)
            completed = 1;
    }

    if (completed)
        levelCompleteHandler();
}