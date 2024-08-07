#include <iostream>

#include "graphics.h"
#include "MyDrawable.h"
#include "movel.h"

void update(MyDrawable* player, sf::Keyboard* bosta) {
    if (bosta->isKeyPressed(sf::Keyboard::D)) {
        player->move(sf::Vector2f(1, 0));
    }
    if (bosta->isKeyPressed(sf::Keyboard::A)) {
        player->move(sf::Vector2f(-1, 0));
    }
    if (bosta->isKeyPressed(sf::Keyboard::S)) {
        player->move(sf::Vector2f(0, 1));
    }
    if (bosta->isKeyPressed(sf::Keyboard::W)) {
        player->move(sf::Vector2f(0, -1));
    }

}
void draw(MyDrawable* player, sf::RenderWindow* window) {
    window->draw(*player);
}

int main()
{   
    Graphics gerenciadorGrafico;
    sf::RenderWindow* window = gerenciadorGrafico.getWindow();
    movel* player;
    sf::Keyboard* bosta;

    bosta = new sf::Keyboard;


    player = new movel();
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
