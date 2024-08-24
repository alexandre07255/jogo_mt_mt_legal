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
	List<Collidable>* collidables = level->getCollidable();

	if (collidables == NULL)
		return;

	sf::FloatRect targetBounds;
	sf::FloatRect collidableBounds;

	float x, y;

	int size = collidables->size();
	ListIterator<Collidable> it = collidables->begin();

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
			it++;
		}
		if (!collided || !collidedDown)
			pE->setOnAir(1);
	}
}

const bool CollisionManager::isColliding(sf::FloatRect one, sf::FloatRect other){
	return (one.intersects(other));
}

void CollisionManager::testHit(const bool target, Hitbox* hitbox)
{
	SceneManager* instance = SceneManager::getInstance();
	Level* level = static_cast<Level*>(instance->top());
	List<Hittable>* hittableList = level->getHittableList();

	if (hitbox == NULL) { return; }
	bool neutral = (hitbox->getOwner() == NULL);
	//Fazer neutral
	if (hittableList == NULL) { cout << "No one is hittable" << endl; return; }
	ListIterator<Hittable> it = hittableList->begin();
	int size = hittableList->size();

	sf::FloatRect hitboxBounds = hitbox->getGlobalBounds();
	sf::FloatRect hittableBounds;

	for (int i = 0; i < size; i++)
	{
		if ((target == (*it)->getIsAlly()) || neutral)
		{
			hittableBounds = (*it)->getGlobalBounds();
			if (isColliding(hitboxBounds, hittableBounds))
			{
				hitbox->hitSolution((*it));
			}
		}
		it++;
	}
}

float CollisionManager::nearestCollidable(MyDrawable* relativeTo, float maxHeight) const
//Returns maxHeight + relativeTo->bottom() if it doesn't find a collidable
{
	SceneManager* LevelInstance = SceneManager::getInstance();
	Level* level = static_cast<Level*>(LevelInstance->top());

	const double PI = 3.1415;
	const double rayStep = 50;

	List<Collidable>* collidables = level->getCollidable();

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

		for (ListIterator<Collidable> it = collidables->begin(); (it != collidables->end()); it++) {
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