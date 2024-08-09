#include <iostream>

#include "graphics.h"
#include "MyDrawable.h"
#include "Player.h"
#include "inputManager.h"
#include "Collidable.h"
#include "CollisionManager.h"
#include "Level.h"

void InicializarCoisas(Level* level) {
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();

    list<Updatable*>* updatables;
    EntityList* drawables;
    updatables = new list<Updatable*>;
    drawables = new EntityList;

    Player* player;
    Player* player2;
    Collidable* plataforma, * parede;
    EntityList* colisionaveis;

    colisionaveis = new EntityList;
    plataforma = new Collidable;
    parede = new Collidable;

    colisionaveis->pushBack(plataforma);
    colisionaveis->pushBack(parede);

    plataforma->setPosition(sf::Vector2f(0, 500));
    plataforma->setFillColor(sf::Color::Red);
    plataforma->setSize(sf::Vector2f(3000, 100));

    parede->setPosition(sf::Vector2f(1000, 0));
    parede->setFillColor(sf::Color::Green);
    parede->setSize(sf::Vector2f(100, 1000));

    gerenciadorColisao->setCollidables(colisionaveis);

    player = new Player(0);
    player->setFillColor(sf::Color::Cyan);
    player->setSize(sf::Vector2f(1, 1));
    player->setOrigin(sf::Vector2f(0, 0));
    player->setSize(sf::Vector2f(100, 100));

    player2 = new Player(1);
    player2->setFillColor(sf::Color::Magenta);
    player2->setSize(sf::Vector2f(1, 1));
    player2->setOrigin(sf::Vector2f(0, 0));
    player2->setSize(sf::Vector2f(100, 100));

    updatables->push_back(player);
    updatables->push_back(player2);

    drawables->pushBack(player);
    drawables->pushBack(player2);
    drawables->pushBack(parede);
    drawables->pushBack(plataforma);

    level->setUpdatables(updatables);
    level->setDrawables(drawables);

    Level::setActive(level);
}

int main()
{   
    Graphics gerenciadorGrafico;
    sf::RenderWindow* window = gerenciadorGrafico.getWindow();   
    Level* level;

    level = new Level;

    InicializarCoisas(level);

    window->setFramerateLimit(60);

    while (gerenciadorGrafico.isWindowOpen())
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
