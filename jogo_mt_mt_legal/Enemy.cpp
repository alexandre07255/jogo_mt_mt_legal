#include "Enemy.h"
#include"CollisionManager.h"
#include <math.h>
#include "Level.h"
#include "Terrain.h"
#include <iostream>
#include <list>
#include "SceneManager.h"
using namespace Scenes;
using namespace Managers;
using namespace Entities::Characters;


Enemy::Enemy() :Hittable(false, 10), upperLimitMultR(9.0 / 4),
lesserLimitMultR(3.0/2), upperLimitMultL(3.0/2), lesserLimitMultL(3.0/4), searchPlayerCont(SEARCH_PLAYER_COOLDOWN){
	setPosition(sf::Vector2f(10, 10));
	setSize(sf::Vector2f(80, 80));
	sightSize = 500.0;
	followingPlayer = NULL;
	state = PATROLLING;
	timer = 0;
}

Enemy::~Enemy()
{
	followingPlayer = NULL;
}

Player* Enemy::searchPlayer() const{
	CollisionManager* instance = CollisionManager::getInstance();
	SceneManager* LevelInstance = SceneManager::getInstance();
	Level* level = static_cast<Level*>(LevelInstance->top());

	const double PI = 3.1415;
	const double rayStep = 50;



	list<Collidable*>* collidables = level->getCollidables();
	Player* players[2] = { level->getPlayer1(), level->getPlayer2() };

	int flag = 1;

	sf::Vector2f rayPos;

	double xCenter = xMid();
	double yCenter = bottom();
	
	double yFinal;
	double xFinal;

	double upperLimit;
	double lesserLimit;
	//int sign;

	if (facingRight) {
		//sign = 1;
		upperLimit = upperLimitMultR * PI;
		lesserLimit = lesserLimitMultR * PI;
	}
	else {
		upperLimit = upperLimitMultL * PI;;
		lesserLimit = lesserLimitMultL * PI;
	}

	for (double i = lesserLimit;i <  upperLimit ;i += 0.1) {
		//fazer 360 graus
		flag = 1;
		for (double j = rayStep;j <= sightSize && flag;j += rayStep) {
			//vai caminhandinho com o raio 
			xFinal = xCenter + j * cos(i);
			yFinal = yCenter + j * sin(i);

			//cria um rect infinitesimal e testa pra ver se colide com algo
			sf::FloatRect ret;
			ret.height = 1;
			ret.width = 1;

			ret.left = xFinal;
			ret.top = yFinal;

			for (int j = 0; j < 2; j++) {
				if (players[j] && ret.intersects((players[j])->getGlobalBounds())) {
					//std::cout << "player achado" << endl;
					return players[j];
				}
			}

			for (list<Collidable*>::iterator it = collidables->begin(); (it != collidables->end()) && flag; it++) {
				if (ret.intersects((*it)->getBounds()))
					flag = 0;
			}
		}

		/*Background* vertice = new Background;
		vertice->setSize(sf::Vector2f(5, 5));
		vertice->setPosition(sf::Vector2f(xFinal, yFinal));
		vertice->setTexture(pTexture);
		SceneManager::getInstance()->top()->addEntity(vertice); */
	}
	return NULL;
}

void Enemy::executeHITSTUN()
{
	if (stun <= 0)
	{
		state = Hittable::PATROLLING;
		setFillColor(sf::Color::White);
	}
	else
	{
		stun--;
		setFillColor(sf::Color::Red);
	}
}

const bool Enemy::isInSearchPlayerCooldown()
{
	if (searchPlayerCont > 0)
	{
		searchPlayerCont--;
		return 1;
	}
	searchPlayerCont = SEARCH_PLAYER_COOLDOWN;
	return 0;
}

const int Enemy::SEARCH_PLAYER_COOLDOWN(30);
