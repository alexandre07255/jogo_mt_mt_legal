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

int main()
{   
    Graphics* gerenciadorGrafico = Graphics::getInstance();
    sf::RenderWindow* window = gerenciadorGrafico->getWindow();   
    Level* level;
    Level* levelActive;
    level = new Level(false,Level::LEVEL_1);

    levelActive = Level::getActive();

    window->setFramerateLimit(60);
    //window->setVerticalSyncEnabled(true);

    while (gerenciadorGrafico->isWindowOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        levelActive->update();
        window->clear(sf::Color::Black);
        levelActive->draw(window);
        window->display();

    }

    return 0;
}
