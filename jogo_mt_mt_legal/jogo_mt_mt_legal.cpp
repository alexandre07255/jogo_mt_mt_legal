#include <iostream>

#include "graphics.h"
#include "MyDrawable.h"
#include "Player.h"
#include "inputManager.h"
#include "Collidable.h"
#include "CollisionManager.h"

void update(Player* player, sf::Keyboard* bosta) {
    player->movement();
}
void draw(MyDrawable* parede, MyDrawable* chao, MyDrawable* player, sf::RenderWindow* window) {
    window->draw(*player);
    window->draw(*parede);
    window->draw(*chao);
}

int main()
{   
    Graphics gerenciadorGrafico;
    sf::RenderWindow* window = gerenciadorGrafico.getWindow();
    Player* player;
    sf::Keyboard* bosta;
    sf::Mouse* mouse;
    Collidable* plataforma, * parede;
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();
    EntityList* colisionaveis;
    sf::Vector2f posicaoMouse;
    
    colisionaveis = new EntityList;
    plataforma = new Collidable;
    parede = new Collidable;

    mouse = new sf::Mouse;

    colisionaveis->pushBack(plataforma);
    colisionaveis->pushBack(parede);

    plataforma->setOrigin(sf::Vector2f(900, 900));
    plataforma->setFillColor(sf::Color::Red);
    plataforma->setSize(sf::Vector2f(1000, 100));

    parede->setOrigin(sf::Vector2f(900,900));
    parede->setFillColor(sf::Color::Green);
    parede->setSize(sf::Vector2f(100, 1000));

    gerenciadorColisao->setCollidables(colisionaveis);

    bosta = new sf::Keyboard;


    player = new Player();
    player->setTextura("kirby.png");
    player->setSize(sf::Vector2f(1, 1));
    player->setOrigin(sf::Vector2f(0, 0));

    player->setSize(sf::Vector2f(100,100));

    window->setFramerateLimit(60);

    while (gerenciadorGrafico.isWindowOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        update(player,bosta);

        window->clear(sf::Color::Black);
        draw(parede,plataforma,player,window);
        window->display();

        cout << mouse->getPosition(*window).x << " : " << mouse->getPosition().y << endl;
    }

    return 0;
}
