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
#include "Level1.h"
#include "SceneManager.h"
#include "MainMenu.h"

int main()
{   
    Graphics* gerenciadorGrafico = Graphics::getInstance();
    sf::RenderWindow* window = gerenciadorGrafico->getWindow();   
    //Level1* level;
    MainMenu* menu = new MainMenu;
    SceneManager* sceneManInstance = SceneManager::getInstance();
    //level = new Level1(false);

    //sceneManInstance->push(level);
    sceneManInstance->push(menu);

    window->setFramerateLimit(60);
    //window->setVerticalSyncEnabled(true);

    sceneManInstance->setWindow(window);
    while (gerenciadorGrafico->isWindowOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        sceneManInstance->step();
    }

    return 0;
}
