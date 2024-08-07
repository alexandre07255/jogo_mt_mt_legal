#include <iostream>

#include "graphics.h"
#include "MyDrawable.h"
#include "Player.h"
#include "inputManager.h"

void update(Player* player, sf::Keyboard* bosta) {
    player->movement();
}
void draw(MyDrawable* player, sf::RenderWindow* window) {
    window->draw(*player);
}

int main()
{   
    Graphics gerenciadorGrafico;
    sf::RenderWindow* window = gerenciadorGrafico.getWindow();
    Player* player;
    sf::Keyboard* bosta;

    bosta = new sf::Keyboard;


    player = new Player();
    player->setTextura("kirby.png");
    player->setSize(sf::Vector2f(1, 1));
    player->setOrigin(sf::Vector2f(0, 0));

    player->setSize(sf::Vector2f(100,100));

    

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
        draw(player,window);
        window->display();
    }

    return 0;
}
