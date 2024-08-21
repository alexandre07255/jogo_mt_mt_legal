#include "Level1.h"
#include"graphics.h"
#include "EnemyMelee.h"
#include "Terrain.h"
#include "CollisionManager.h"
#include "Level2.h"
#include "SceneManager.h"

Level1::Level1(bool isPlayer2):Level() {
    Graphics* instance = Graphics::getInstance();
    sf::RenderWindow* window = instance->getWindow();

    Camera* view;
    view = new Camera(window);
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();

    Player* player;
    Player* player2 = NULL;
    Terrain* plataforma, * parede, * teto;
    EnemyMelee* inimigo;

    plataforma = new Terrain;
    parede = new Terrain;
    teto = new Terrain;

    plataforma->setPosition(0, 1000);
    plataforma->setFillColor(sf::Color::Red);
    plataforma->setSize(sf::Vector2f(2050, 100));

    parede->setPosition(300, 500);
    parede->setFillColor(sf::Color::Green);
    parede->setSize(sf::Vector2f(100, 300));

    teto->setPosition(0, 400);
    teto->setFillColor(sf::Color::Blue);
    teto->setSize(sf::Vector2f(1000, 100));

    collidables->push_back(plataforma);
    collidables->push_back(parede);
    collidables->push_back(teto);

    player = new Player(0, 1, 10);
    player->setFillColor(sf::Color::Cyan);
    //player->setSize(sf::Vector2f(1, 1));
    player->setOrigin(0, 0);
    player->setSize(sf::Vector2f(100, 100));
    player->setPosition(0, 900);
    pPlayer1 = player;


    if (isPlayer2) {
        player2 = new Player(1, 1, 10);
        player2->setFillColor(sf::Color::Magenta);
        //player2->setSize(sf::Vector2f(1, 1));
        player2->setOrigin(0, 0);
        player2->setSize(sf::Vector2f(100, 100));
        player2->setPosition(100, 900);
        pPlayer2 = player2;
    }

    inimigo = new EnemyMelee;
    inimigo->setPosition(1000, 900);

    hittableList->push_back(player);
    if (isPlayer2)
        hittableList->push_back(player2);
    hittableList->push_back(inimigo);

    updatables->push_back(player);
    if (isPlayer2)
        updatables->push_back(player2);
    updatables->push_back(view);
    updatables->push_back(inimigo);

    drawables->push_back(player);
    if (isPlayer2)
        drawables->push_back(player2);
    drawables->push_back(parede);
    drawables->push_back(plataforma);
    drawables->push_back(inimigo);
    drawables->push_back(teto);

    SceneManager::getInstance()->push(this);

    view->setPlayer1(player);
    if (isPlayer2)
        view->setPlayer2(player2);

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