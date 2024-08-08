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

    EntityList* updatables;
    EntityList* drawables;

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

    updatables->pushBack(player);
    updatables->pushBack(player2);

    drawables->pushBack(player);
    drawables->pushBack(player2);
    drawables->pushBack(parede);
    drawables->pushBack(plataforma);

    level->setUpdatables(updatables);
    level->setDrawables(drawables);
}

void update(Player* player, Player* player2, sf::Keyboard* bosta) {
    player->movement();
    player2->movement();
}
void draw(MyDrawable* parede, MyDrawable* chao, MyDrawable* player, MyDrawable* player2, sf::RenderWindow* window) {
    window->draw(*player);
    window->draw(*player2);
    window->draw(*parede);
    window->draw(*chao);
}

int main()
{   
    Graphics gerenciadorGrafico;
    sf::RenderWindow* window = gerenciadorGrafico.getWindow();   
    

    window->setFramerateLimit(60);



    while (gerenciadorGrafico.isWindowOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        update(player, player2, bosta);

        window->clear(sf::Color::Black);
        draw(parede,plataforma,player, player2, window);
        window->display();

        cout << player->getPosition().x << " : " << player->getPosition().y << endl;
    }

    return 0;
}
