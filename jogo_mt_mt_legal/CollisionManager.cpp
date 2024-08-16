#include "CollisionManager.h"
#include <iostream>
using namespace std;

CollisionManager* CollisionManager::instance(NULL);

CollisionManager::CollisionManager():
	collidables(NULL),
	aliveList(NULL)
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
	if (collidables == NULL)
		return;

	sf::FloatRect targetBounds;
	sf::FloatRect collidableBounds;

	int x, y;

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
				pE->move(sf::Vector2f(0, (y*directionY)));
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

void CollisionManager::setCollidables(list<Collidable*>* pC)
{
	collidables = pC;
}

const bool CollisionManager::isColliding(sf::FloatRect one, sf::FloatRect other){
	return (one.intersects(other));
}

void CollisionManager::setAliveList(list<Alive*>* Alist)
{
	aliveList = Alist;
}

void CollisionManager::testHit(const bool target, Hitbox* hitbox)
{
	if (hitbox == NULL) { return; }
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

list<Collidable*>* CollisionManager::getCollidables() {
	return collidables;
}

list<Alive*>* CollisionManager::getAliveList() {
	return aliveList;
}