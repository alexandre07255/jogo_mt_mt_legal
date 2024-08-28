#include "CollisionManager.h"
#include "SceneManager.h"
#include "Level.h"
#include <iostream>
#include "SceneManager.h"
#include <list>
using namespace std;
using namespace Managers;
using namespace Entities;
using namespace Scenes;
using namespace Entities::Hitboxes;
using namespace Entities::Characters;
using namespace Entities::Obstacles;





CollisionManager* CollisionManager::instance(NULL);

CollisionManager::CollisionManager():
	enemyVector(NULL),
	supportVector(NULL),
	collidables(NULL),
	obstaclelist(NULL),
	player1(NULL),
	player2(NULL)
{

}

CollisionManager::~CollisionManager()
{

}

void CollisionManager::testHittableToObstacleCollisions()
{
	if (!obstaclelist) { return; }

	int size = obstaclelist->size();
	list<Obstacle*>::iterator it = obstaclelist->begin();

	for (int i = 0; i < size; i++)
	{
		(*it)->toObstacle();
		it++;
	}
}



void CollisionManager::testPlayerToEnemyCollision()
{
	if (enemyVector == NULL)
		return;

	sf::FloatRect targetBounds;
	sf::FloatRect hittableBounds;

	float x, y;

	int size = enemyVector->size();
	vector<Enemy*>::iterator it = enemyVector->begin();

	int directionX = 0;
	int directionY = 0;

	Player* target[2] = { player1, player2 };

	for (int j = 0; j < 2; j++)
	{
		if (target[j])
		{
			targetBounds = target[j]->getGlobalBounds();

			for (int i = 0; i < size; i++)
			{
				
				hittableBounds = (*it)->getGlobalBounds();

				if (isColliding(hittableBounds, targetBounds)) {
					//temos colisao
					if (targetBounds.getPosition().x + targetBounds.width < hittableBounds.getPosition().x + hittableBounds.width) {
						//se target colidiu pela direita
						x = targetBounds.getPosition().x + targetBounds.width - hittableBounds.getPosition().x;
						directionX = -1;
					}
					else {
						//se target colidiu pela esquerda
						x = hittableBounds.getPosition().x + hittableBounds.width - targetBounds.getPosition().x;
						directionX = 1;
					}

					if (targetBounds.getPosition().y + targetBounds.height < hittableBounds.getPosition().y + hittableBounds.height) {
						//se target coldiu por baixo
						y = targetBounds.getPosition().y + targetBounds.height - hittableBounds.getPosition().y;
						directionY = -1;
					}
					else {
						//se target colidiu por cima
						y = hittableBounds.getPosition().y + hittableBounds.height - targetBounds.getPosition().y;
						directionY = 1;
					}

					if (y < x) {
						target[j]->move(0, (y * directionY));
						target[j]->setVerticalVelocity(10.f * (directionY));
					}
					else {
						target[j]->move(sf::Vector2f((x * directionX), 0));
						target[j]->setHorizontalVelocity(10.f * (directionX));
					}
					targetBounds = target[j]->getGlobalBounds();
				}
				
				it++;
			}
		}
	}
}

void CollisionManager::testHittableToCollidableCollisions()
{
	Player* target[2] = { player1, player2 };

	for (int i = 0; i < 2; i++)
		if (target[i])
			testCollison(target[i]);

	if (enemyVector)
	{
		int size = enemyVector->size();
		for (int i = 0; i < size; i++)
			testCollison(enemyVector->at(i));
	}
}


CollisionManager* CollisionManager::getInstance()
{
	if (instance == NULL)
		instance = new CollisionManager;
	return instance;
}

void CollisionManager::testCollison(Entity* pE)
{
	if (collidables == NULL)
		return;

	sf::FloatRect targetBounds;
	sf::FloatRect collidableBounds;

	float x, y;

	int size = collidables->size();
	list<Collidable*>::iterator it = collidables->begin();

	int directionX = 0;
	int directionY = 0;

	targetBounds = pE->getGlobalBounds();

	bool collided = 0;
	bool collidedDown = 0;
	for (int i = 0; i < size; i++)
	{
		if (pE->getId() != (*it)->getCollidableId()) {
			collidableBounds = (*it)->getBounds();

			if (isColliding(collidableBounds, targetBounds)) {
				(*it)->collisionSolution(pE);
				collided = 1;
				//temos colisao
				if (targetBounds.getPosition().x + targetBounds.width < collidableBounds.getPosition().x + collidableBounds.width) {
					//se player colidiu pela direita
					x = targetBounds.getPosition().x + targetBounds.width - collidableBounds.getPosition().x;
					directionX = -1;
				}
				else {
					//se player colidiu pela esquerda
					x = collidableBounds.getPosition().x + collidableBounds.width - targetBounds.getPosition().x;
					directionX = 1;
				}

				if (targetBounds.getPosition().y + targetBounds.height < collidableBounds.getPosition().y + collidableBounds.height) {
					//se player coldiu por baixo
					y = targetBounds.getPosition().y + targetBounds.height - collidableBounds.getPosition().y;
					directionY = -1;
					collidedDown = 1;
				}
				else {
					//se player colidiu por cima
					y = collidableBounds.getPosition().y + collidableBounds.height - targetBounds.getPosition().y;
					directionY = 1;
				}

				if (y < x) {
					pE->move(0, (y * directionY));
					pE->setVerticalVelocity(0);
					if (directionY == -1)
						pE->setOnAir(0);
				}
				else {
					pE->move(sf::Vector2f((x * directionX), 0));
					pE->setHorizontalVelocity(0);
				}
				targetBounds = pE->getGlobalBounds();

			}
			
			
		}
		it++;
		
	}
	if (!collided || !collidedDown)
		pE->setOnAir(1);
}

const bool CollisionManager::isColliding(sf::FloatRect one, sf::FloatRect other){
	return (one.intersects(other));
}

void CollisionManager::testHit(const bool target, Hitbox* hitbox)
{
	

	if (hitbox == NULL) { return; }
	bool neutral = (hitbox->getOwner() == NULL);
	//Fazer neutral

	sf::FloatRect hitboxBounds = hitbox->getGlobalBounds();
	sf::FloatRect hittableBounds;

	if (target || neutral)
	{
		if (player1)
		{
			hittableBounds = (player1)->getGlobalBounds();
			if (isColliding(hitboxBounds, hittableBounds))
			{
				hitbox->hitSolution(player1);
			}
		}
		if (player2)
		{
			hittableBounds = (player2)->getGlobalBounds();
			if (isColliding(hitboxBounds, hittableBounds))
			{
				hitbox->hitSolution(player2);
			}
		}
	}

	if (!target || neutral)
	{
		if (!enemyVector || !supportVector) { return; }

		int size = enemyVector->size();

		for (int i = 0; i < size; i++)
		{
			hittableBounds = (enemyVector->at(i))->getGlobalBounds();
			if (isColliding(hitboxBounds, hittableBounds))
			{
				hitbox->hitSolution(enemyVector->at(i));
			}
		}

		size = supportVector->size();
		for (int i = 0; i < size; i++)
		{
			hittableBounds = (supportVector->at(i))->getGlobalBounds();
			if (isColliding(hitboxBounds, hittableBounds))
			{
				hitbox->hitSolution(supportVector->at(i));
			}
		}
	}
}

float CollisionManager::nearestCollidable(Entity* relativeTo, float maxHeight) const
//Returns maxHeight + relativeTo->bottom() if it doesn't find a collidable
{
	const double PI = 3.1415;
	const double rayStep = 50;

	double xCenter = relativeTo->xMid();
	double yCenter = relativeTo->bottom();

	double yFinal;
	double xFinal;

	//Ray para baixo
	for (double j = rayStep; j <= maxHeight; j += rayStep) {
		//vai caminhandinho com o raio 
		xFinal = xCenter + j * cos(PI / 2);
		yFinal = yCenter + j * sin(PI / 2);

		//cria um rect infinitesimal e testa pra ver se colide com algo
		sf::FloatRect ret;
		ret.height = 1;
		ret.width = 1;

		ret.left = xFinal;
		ret.top = yFinal;

		for (list<Collidable*>::iterator it = collidables->begin(); (it != collidables->end()); it++) {
			sf::FloatRect colli = (*it)->getBounds();
			if (ret.intersects(colli))
				return colli.getPosition().y;
		}
	}

	/*Terrain* vertice = new Terrain();
	vertice->setSize(sf::Vector2f(5, 5));
	vertice->setPosition(sf::Vector2f(xFinal, yFinal));

	nivel->addDrawable(vertice);*/

	return maxHeight + relativeTo->bottom();
}