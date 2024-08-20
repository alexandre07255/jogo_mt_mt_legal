#include "CollisionManager.h"
#include "SceneManager.h"
#include "Level.h"
#include <iostream>
#include "SceneManager.h"
using namespace std;

CollisionManager* CollisionManager::instance(NULL);

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

CollisionManager* CollisionManager::getInstance()
{
	if (instance == NULL)
		instance = new CollisionManager;
	return instance;
}

void CollisionManager::testCollison(Entity* pE)
{
	SceneManager* instance = SceneManager::getInstance();
	Level* level = static_cast<Level*>(instance->top());
	list<Collidable*>* collidables = level->getCollidable();

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
		//cu
		collidableBounds = (*it)->getGlobalBounds();

		if (isColliding(collidableBounds,targetBounds)) {
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
				pE->move(0, (y*directionY));
				pE->setVerticalVelocity(0);
				if (directionY == -1)
					pE->setOnAir(0);
			}
			else {
				pE->move(sf::Vector2f((x*directionX), 0));
				pE->setHorizontalVelocity(0);
			}
			targetBounds = pE->getGlobalBounds();

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
	SceneManager* instance = SceneManager::getInstance();
	Level* level = static_cast<Level*>(instance->top());
	list<Alive*>* aliveList = level->getAliveList();

	if (hitbox == NULL) { return; }
	bool neutral = 0;
	//Fazer neutral
	if (aliveList == NULL) { cout << "No one is alive" << endl; return; }
	list<Alive*>::iterator it = aliveList->begin();
	int size = aliveList->size();

	sf::FloatRect hitboxBounds = hitbox->getGlobalBounds();
	sf::FloatRect aliveBounds;

	for (int i = 0; i < size; i++)
	{
		if (target == (*it)->getIsAlly())
		{
			aliveBounds = (*it)->getGlobalBounds();
			if (isColliding(hitboxBounds, aliveBounds))
			{
				hitbox->hitSolution((*it));
			}
		}
		it++;
	}
}
