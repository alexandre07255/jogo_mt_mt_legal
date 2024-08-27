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

Level1::Level1(bool isPlayer2):Level() {
    GraphicManager* instance = GraphicManager::getInstance();
    sf::RenderWindow* window = instance->getWindow();
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();

    sf::Texture* background = new sf::Texture();
    background->loadFromFile("spritesheets/fase1EBA.png");

    sf::Texture* spikeText = new sf::Texture();
    spikeText->loadFromFile("spritesheets/s_spike.png");

    float scale = 5.33333;
    float x = background->getSize().x * scale;
    float y = background->getSize().y * scale;

    backgroundAndLevel = new MyDrawable();
    backgroundAndLevel->setSize(sf::Vector2f(x, y));
    backgroundAndLevel->setTexture(background);
    drawables->push_back(backgroundAndLevel);
    backgroundAndLevel->setOutlineThickness(2.f);
    backgroundAndLevel->setOutlineColor(sf::Color::Red);

    Terrain* leftWall = new Terrain(1.f);
    leftWall->setPosition(0, 0);
    leftWall->setSize(sf::Vector2f(7 * scale * 16, scale * 26 * 16));
    collidables->push_back(leftWall);

    Terrain* floor = new Terrain(1.f);
    floor->setPosition(7*16*scale, scale * 26 * 16);
    floor->setSize(sf::Vector2f(89 * 16 * scale,2 * 16* scale));
    collidables->push_back(floor);


    Terrain* firstTerrain = new Terrain(1.f);
    firstTerrain->setPosition(14*16 * scale , 24*16 * scale);
    firstTerrain->setSize(sf::Vector2f(scale * 16 * 7, scale * 2 * 16));
    collidables->push_back(firstTerrain);

    Terrain* secondTerrain = new Terrain(1.f);
    secondTerrain->setPosition(27 * 16 * scale, 25 * 16 * scale);
    secondTerrain->setSize(sf::Vector2f(scale * 16 * 3, scale * 1 * 16));
    collidables->push_back(secondTerrain);

    Terrain* littleBlock = new Terrain(1.f);
    littleBlock->setPosition(44 * 16 * scale, 25 * 16 * scale);
    littleBlock->setSize(sf::Vector2f(scale * 16 * 1, scale * 1 * 16));
    collidables->push_back(littleBlock);

    Terrain* megaRetangulo = new Terrain(1.f);
    megaRetangulo->setPosition(45 * 16 * scale, 23 * 16 * scale);
    megaRetangulo->setSize(sf::Vector2f(scale * 16 * 45, scale * 3 * 16));
    collidables->push_back(megaRetangulo);

    Terrain* thirdTerrain = new Terrain(1.f);
    thirdTerrain->setPosition(54 * 16 * scale, 22 * 16 * scale);
    thirdTerrain->setSize(sf::Vector2f(scale * 16 * 18, scale * 1 * 16));
    collidables->push_back(thirdTerrain);

    Terrain* fourthTerrain = new Terrain(1.f);
    fourthTerrain->setPosition(61 * 16 * scale, 21 * 16 * scale);
    fourthTerrain->setSize(sf::Vector2f(scale * 16 * 8, scale * 1 * 16));
    collidables->push_back(fourthTerrain);

    Terrain* fifthTerrain = new Terrain(1.f);
    fifthTerrain->setPosition(79 * 16 * scale, 21 * 16 * scale);
    fifthTerrain->setSize(sf::Vector2f(scale * 16 * 1, scale * 2 * 16));
    collidables->push_back(fifthTerrain);

    Terrain* sixthTerrain = new Terrain(1.f);
    sixthTerrain->setPosition(84 * 16 * scale, 22 * 16 * scale);
    sixthTerrain->setSize(sf::Vector2f(scale * 16 * 6, scale * 1 * 16));
    collidables->push_back(sixthTerrain);

    Terrain* seventhTerrain = new Terrain(1.f);
    seventhTerrain->setPosition(86 * 16 * scale, 21 * 16 * scale);
    seventhTerrain->setSize(sf::Vector2f(scale * 16 * 1, scale * 1 * 16));
    collidables->push_back(seventhTerrain);

    Terrain* rightWall = new Terrain(1.f);
    rightWall->setPosition(90 * 16 * scale, 6 * 16 * scale);
    rightWall->setSize(sf::Vector2f(scale * 16 * 1, scale * 30 * 16));
    collidables->push_back(rightWall);

    Spike* spike1;
    spike1 = new Spike;
    spike1->setPosition(33 * 16 * scale, 25 * 16 * scale);
    spike1->setSize(sf::Vector2f(3 * 16 * scale, 1 * 6 * scale));
    drawables->push_back(spike1);
    updatables->push_back(spike1);
    spike1->setTexture(spikeText, false);

    Spike* spike2;
    spike2 = new Spike;
    spike2->setPosition(57 * 16 * scale, 21 * 16 * scale);
    spike2->setSize(sf::Vector2f(4 * 16 * scale, 1 * 6 * scale));
    drawables->push_back(spike2);
    updatables->push_back(spike2);
    spike2->setTexture(spikeText, false);

    Spike* spike3;
    spike3 = new Spike;
    spike3->setPosition(65 * 16 * scale, 20 * 16 * scale);
    spike3->setSize(sf::Vector2f(3 * 16 * scale, 1 * 6 * scale));
    drawables->push_back(spike3);
    updatables->push_back(spike3);
    spike3->setTexture(spikeText, false);


    Platform* fallPlatform;
    fallPlatform = new Platform(37*16*scale,23*16*scale,3*16*scale,16*scale);
    collidables->push_back(fallPlatform);
    drawables->push_back(fallPlatform);
    updatables->push_back(fallPlatform);


    Platform* fallPlatform2;
    fallPlatform2 = new Platform(49 * 16 * scale, 20 * 16 * scale, 3 * 16 * scale, 16 * scale);
    collidables->push_back(fallPlatform2);
    drawables->push_back(fallPlatform2);
    updatables->push_back(fallPlatform2);


    Platform* fallPlatform3;
    fallPlatform3 = new Platform(70 * 16 * scale, 19 * 16 * scale, 2 * 16 * scale, 16 * scale);
    collidables->push_back(fallPlatform3);
    drawables->push_back(fallPlatform3);
    updatables->push_back(fallPlatform3);


    Player* player;
    player = new Player(0, 1, 10);
    player->setFillColor(sf::Color::Cyan);
    player->setOrigin(0, 0);
    player->setSize(sf::Vector2f(80, 80));
    player->setPosition(8 * 16 * scale, 20 * 16 * scale);
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
        player2->setSize(sf::Vector2f(80, 80));
        player2->setPosition(9 * 16 * scale, 20 * 16 * scale);
        pPlayer2 = player2;
        hittableList->push_back(player2);
        updatables->push_back(player2);
        drawables->push_back(player2);

    }

    EnemyMelee* inimigoMelee1;
    inimigoMelee1 = new EnemyMelee;
    inimigoMelee1->setPosition(23*16*scale, 25*16*scale);
    hittableList->push_back(inimigoMelee1);
    updatables->push_back(inimigoMelee1);
    drawables->push_back(inimigoMelee1);

    EnemyMelee* inimigoMelee2;
    inimigoMelee2 = new EnemyMelee;
    inimigoMelee2->setPosition(47 * 16 * scale, 22 * 16 * scale);
    hittableList->push_back(inimigoMelee2);
    updatables->push_back(inimigoMelee2);
    drawables->push_back(inimigoMelee2);

    EnemyMelee* inimigoMelee3;
    inimigoMelee3 = new EnemyMelee;
    inimigoMelee3->setPosition(75 * 16 * scale, 22 * 16 * scale);
    hittableList->push_back(inimigoMelee3);
    updatables->push_back(inimigoMelee3);
    drawables->push_back(inimigoMelee3);


    EnemyRanged* inimigoRanged1;
    inimigoRanged1 = new EnemyRanged;
    inimigoRanged1->setPosition(31 * 16 * scale, 24 * 16 * scale);
    hittableList->push_back(inimigoRanged1);
    updatables->push_back(inimigoRanged1);
    drawables->push_back(inimigoRanged1);

    EnemyRanged* inimigoRanged2;
    inimigoRanged2 = new EnemyRanged;
    inimigoRanged2->setPosition(55 * 16 * scale, 20 * 16 * scale);
    hittableList->push_back(inimigoRanged2);
    updatables->push_back(inimigoRanged2);
    drawables->push_back(inimigoRanged2);

    EnemyRanged* inimigoRanged3;
    inimigoRanged3 = new EnemyRanged;
    inimigoRanged3->setPosition(75 * 16 * scale, 20 * 16 * scale);
    hittableList->push_back(inimigoRanged3);
    updatables->push_back(inimigoRanged3);
    drawables->push_back(inimigoRanged3);

    Camera* view;
    view = new Camera(window);
    updatables->push_back(view);
    view->setPlayer1(player);
    if (isPlayer2)
        view->setPlayer2(player2);

    endingOnRight = 1;
    endX = x - 16*scale;
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