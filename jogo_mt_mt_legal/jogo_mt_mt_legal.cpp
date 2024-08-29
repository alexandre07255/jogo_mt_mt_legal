#include <iostream>

#include "GraphicManager.h"
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
using namespace Scenes;
using namespace Managers;


int main()
{   
    GraphicManager* gerenciadorGrafico = GraphicManager::getInstance();
    sf::RenderWindow* window = gerenciadorGrafico->getWindow();   
    MainMenu* menu = new MainMenu;
    SceneManager* sceneManInstance = SceneManager::getInstance();
 
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
