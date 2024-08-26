#include "Enemy.h"
#include"CollisionManager.h"
#include <math.h>
#include "Level.h"
#include "Terrain.h"
#include <iostream>
#include "SceneManager.h"

Enemy::Enemy() :Hittable(false, 10), upperLimitMultR(9.0 / 4),
lesserLimitMultR(3.0/2), upperLimitMultL(3.0/2), lesserLimitMultL(3.0/4){
	setPosition(sf::Vector2f(10, 10));
	setSize(sf::Vector2f(100, 100));
	sightSize = 500.0;
	followingPlayer = NULL;
	state = PATROLLING;
	timer = 0;
}

Player* Enemy::searchPlayer() const{
	CollisionManager* instance = CollisionManager::getInstance();
	SceneManager* LevelInstance = SceneManager::getInstance();
	Level* level = static_cast<Level*>(LevelInstance->top());

	const double PI = 3.1415;
	const double rayStep = 50;



	List<Collidable>* collidables = level->getCollidable();
	List<Hittable>* hittable = level->getHittableList();

	int flag = 1;

	sf::Vector2f rayPos;

	double xCenter = getPosition().x + getSize().x / 2;
	double yCenter = getPosition().y + getSize().y;
	
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

			for (List<Hittable>::Iterator it = hittable->begin();it != hittable->end();it++) {
				if (ret.intersects((*it)->getGlobalBounds()) && (*it)->getIsAlly()) {
					//std::cout << "player achado" << endl;
					return (Player*)*it;
				}
			}

			for (List<Collidable>::Iterator it = collidables->begin(); (it != collidables->end()) && flag; it++) {
				if (ret.intersects((*it)->getBounds()))
					flag = 0;
			}
		}

		/*Terrain* vertice = new Terrain();
		vertice->setSize(sf::Vector2f(5, 5));
		vertice->setPosition(sf::Vector2f(xFinal, yFinal));

		nivel->addDrawable(vertice);*/
	}
	return NULL;
}

void Enemy::movementHITSTUN()
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