#pragma once
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

class Game
{
private:
	Managers::SceneManager* pSM;
	Managers::GraphicManager* pGM;
	static sf::Event* event;
	void createManagers();
	void createMenu();
public:
	Game();
	~Game();
	static sf::Event* getEvent();
	void run();
};

