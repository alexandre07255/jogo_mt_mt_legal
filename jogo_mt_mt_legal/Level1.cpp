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
using namespace Scenes;
using namespace Managers;


Level1::Level1(bool isPlayer2):Level() {
    GraphicManager* instance = GraphicManager::getInstance();
    sf::RenderWindow* window = instance->getWindow();
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();

 

    Terrain* plataforma;
    plataforma = new Terrain(1.f);
    plataforma->setPosition(0, 1000);
    plataforma->setFillColor(sf::Color::Red);
    plataforma->setSize(sf::Vector2f(2050, 100));
    collidables->push_back(plataforma);
    drawables->push_back(plataforma);


    Terrain* parede;
    parede = new Terrain(1.f);
    parede->setPosition(300, 500);
    parede->setFillColor(sf::Color::Green);
    parede->setSize(sf::Vector2f(100, 300));
    collidables->push_back(parede);
    drawables->push_back(parede);


    Terrain* teto;
    teto = new Terrain(1.f);
    teto->setPosition(0, 400);
    teto->setFillColor(sf::Color::Blue);
    teto->setSize(sf::Vector2f(1000, 100));
    collidables->push_back(teto);
    drawables->push_back(teto);

    Spike* spike;
    spike = new Spike;
    spike->setPosition(1200.f, 400.f);
    spike->setSize(sf::Vector2f(100.f, 50.f));
    //drawables->push_back(spike);
    updatables->push_back(spike);



    Platform* fallPlatform;
    fallPlatform = new Platform(400, 800, 100, 50);
    collidables->push_back(fallPlatform);
    drawables->push_back(fallPlatform);
    updatables->push_back(fallPlatform);


    Platform* fallPlatform2;
    fallPlatform2 = new Platform(600, 900, 200, 50);
    collidables->push_back(fallPlatform2);
    drawables->push_back(fallPlatform2);
    updatables->push_back(fallPlatform2);


    Platform* fallPlatform3;
    fallPlatform3 = new Platform(800.f, 850.f, 200.f, 50.f);
    collidables->push_back(fallPlatform3);
    drawables->push_back(fallPlatform3);
    updatables->push_back(fallPlatform3);


    Player* player;
    player = new Player(0, 1, 10);
    player->setFillColor(sf::Color::Cyan);
    //player->setSize(sf::Vector2f(1, 1));
    player->setOrigin(0, 0);
    player->setSize(sf::Vector2f(100, 100));
    player->setPosition(0, 900);
    pPlayer1 = player;
    hittableList->push_back(player);
    updatables->push_back(player);
    drawables->push_back(player);


    Player* player2 = NULL;
    if (isPlayer2) {
        player2 = new Player(1, 1, 10);
        player2->setFillColor(sf::Color::Magenta);
        //player2->setSize(sf::Vector2f(1, 1));
        player2->setOrigin(0, 0);
        player2->setSize(sf::Vector2f(100, 100));
        player2->setPosition(100, 900);
        pPlayer2 = player2;
        hittableList->push_back(player2);
        updatables->push_back(player2);
        drawables->push_back(player2);

    }

    //EnemyMelee* inimigoMelee;
    //inimigo = new EnemyMelee;
    //inimigo->setPosition(1000, 900);
    //hittableList->push_back(inimigoMelee);
    //updatables->push_back(inimigoMelee);
    //drawables->push_back(inimigoMelee);


    EnemyRanged* inimigoRanged;
    inimigoRanged = new EnemyRanged;
    inimigoRanged->setPosition(1000, 900);
    hittableList->push_back(inimigoRanged);
    updatables->push_back(inimigoRanged);
    drawables->push_back(inimigoRanged);

 
    Camera* view;
    view = new Camera(window);
    updatables->push_back(view);
    view->setPlayer1(player);
    if (isPlayer2)
        view->setPlayer2(player2);



    //SceneManager::getInstance()->push(this);



    endingOnRight = 1;
    endX = 2000;
}

Level1::~Level1() {

}

void Level1::levelCompleteHandler()
{
    Level2* level2 = new Level2(pPlayer2 != NULL);
    SceneManager* sceneManInstance = SceneManager::getInstance();
    sceneManInstance->pop();
    //Deletar level1
    sceneManInstance->push(level2);
}