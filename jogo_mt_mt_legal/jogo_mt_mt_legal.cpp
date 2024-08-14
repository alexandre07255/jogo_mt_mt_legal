#include <iostream>

#include "graphics.h"
#include "MyDrawable.h"
#include "Player.h"
#include "inputManager.h"
#include "Collidable.h"
#include "CollisionManager.h"
#include "Level.h"
#include "Camera.h"
#include "Enemy.h"
#include "EnemyMelee.h"

void InicializarCoisas(Level* level) {
    Graphics* instance = Graphics::getInstance();
    sf::RenderWindow* window = instance->getWindow();
    Camera* view;
    view = new Camera(window);
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();

    list<Updatable*>* updatables;
    EntityList* drawables;
    list<Alive*>* alives;
    updatables = new list<Updatable*>;
    drawables = new EntityList;
    alives = new list<Alive*>;

    Player* player;
    //Player* player2;
    Collidable* plataforma, * parede, * teto;
    EntityList* colisionaveis;
    EnemyMelee* inimigo;

    colisionaveis = new EntityList;
    plataforma = new Collidable;
    parede = new Collidable;
    teto = new Collidable;

    colisionaveis->pushBack(plataforma);
    colisionaveis->pushBack(parede);
    colisionaveis->pushBack(teto);

    plataforma->setPosition(sf::Vector2f(0, 1000));
    plataforma->setFillColor(sf::Color::Red);
    plataforma->setSize(sf::Vector2f(3000, 100));

    parede->setPosition(sf::Vector2f(300, 500));
    parede->setFillColor(sf::Color::Green);
    parede->setSize(sf::Vector2f(100, 300));

    teto->setPosition(sf::Vector2f(0,400));
    teto->setFillColor(sf::Color::Blue);
    teto->setSize(sf::Vector2f(1000, 100));

    gerenciadorColisao->setCollidables(colisionaveis);

    player = new Player(0,1,10);
    player->setFillColor(sf::Color::Cyan);
    player->setSize(sf::Vector2f(1, 1));
    player->setOrigin(sf::Vector2f(0, 0));
    player->setSize(sf::Vector2f(100, 100));

    //player2 = new Player(1,1,10);
    //player2->setFillColor(sf::Color::Magenta);
    //player2->setSize(sf::Vector2f(1, 1));
    //player2->setOrigin(sf::Vector2f(0, 0));
    //player2->setSize(sf::Vector2f(100, 100));

    inimigo = new EnemyMelee;
    inimigo->setPosition(1000, 900);

    alives->push_back(player);
    //alives->push_back(player2);
    alives->push_back(inimigo);

    gerenciadorColisao->setAliveList(alives);

    updatables->push_back(player);
    //updatables->push_back(player2);
    updatables->push_back(view);
    updatables->push_back(inimigo);

    drawables->pushBack(player);
    //drawables->pushBack(player2);
    drawables->pushBack(parede);
    drawables->pushBack(plataforma);
    drawables->pushBack(inimigo);
    drawables->pushBack(teto);


    level->setUpdatables(updatables);
    level->setDrawables(drawables);

    Level::setActive(level);

    view->setPlayer1(player);
    //view->setPlayer2(player2);
}

int main()
{   
    Graphics* gerenciadorGrafico = Graphics::getInstance();
    sf::RenderWindow* window = gerenciadorGrafico->getWindow();   
    Level* level;

    level = new Level;

    InicializarCoisas(level);

    //window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(true);

    while (gerenciadorGrafico->isWindowOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        level->update();
        window->clear(sf::Color::Black);
        level->draw(window);
        window->display();

    }

    return 0;
}
