#include "Level1.h"
#include"graphics.h"
#include "EnemyMelee.h"
#include "CollisionManager.h"

Level1::Level1(bool isPlayer2):Level() {
    Graphics* instance = Graphics::getInstance();
    sf::RenderWindow* window = instance->getWindow();

    Camera* view;
    view = new Camera(window);
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();

    Player* player;
    Player* player2 = NULL;
    Collidable* plataforma, * parede, * teto;
    EnemyMelee* inimigo;

    plataforma = new Collidable;
    parede = new Collidable;
    teto = new Collidable;

    plataforma->setPosition(sf::Vector2f(0, 1000));
    plataforma->setFillColor(sf::Color::Red);
    plataforma->setSize(sf::Vector2f(3000, 100));

    parede->setPosition(sf::Vector2f(300, 500));
    parede->setFillColor(sf::Color::Green);
    parede->setSize(sf::Vector2f(100, 300));

    teto->setPosition(sf::Vector2f(0, 400));
    teto->setFillColor(sf::Color::Blue);
    teto->setSize(sf::Vector2f(1000, 100));

    collidables->push_back(plataforma);
    collidables->push_back(parede);
    collidables->push_back(teto);

    gerenciadorColisao->setCollidables(collidables);

    player = new Player(0, 1, 10);
    player->setFillColor(sf::Color::Cyan);
    player->setSize(sf::Vector2f(1, 1));
    player->setOrigin(sf::Vector2f(0, 0));
    player->setSize(sf::Vector2f(100, 100));


    if (isPlayer2) {
        player2 = new Player(1, 1, 10);
        player2->setFillColor(sf::Color::Magenta);
        player2->setSize(sf::Vector2f(1, 1));
        player2->setOrigin(sf::Vector2f(0, 0));
        player2->setSize(sf::Vector2f(100, 100));
    }

    inimigo = new EnemyMelee;
    inimigo->setPosition(1000, 900);

    aliveList->push_back(player);
    if (isPlayer2)
        aliveList->push_back(player2);
    aliveList->push_back(inimigo);

    gerenciadorColisao->setAliveList(aliveList);

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

    Level::setActive(this);

    view->setPlayer1(player);
    if (isPlayer2)
        view->setPlayer2(player2);
}

Level1::~Level1() {

}