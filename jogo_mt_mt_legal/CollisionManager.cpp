#include "CollisionManager.h"

CollisionManager* CollisionManager::instance(NULL);

CollisionManager::CollisionManager():
	collidables(NULL)
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

	sf::FloatRect playerBounds;
	sf::FloatRect collidableBounds;

	int x, y;

	int size = collidables->getSize();
	collidables->start();

	Entity* current = NULL;
	playerBounds = pE->getGlobalBounds();

	for (int i = 0; i < size; i++)
	{
		//cu
		current = collidables->getCurrent();
		collidableBounds = current->getGlobalBounds();

		if (isColliding(collidableBounds,playerBounds)) {
			//temos colisao
			if (playerBounds.getPosition().x + playerBounds.width < collidableBounds.getPosition().x + collidableBounds.width) {
				//se player colidiu pela direita
				x = playerBounds.getPosition().x + playerBounds.width - collidableBounds.getPosition().x;
			}
			else {
				//se player colidiu pela esquerda
				x = collidableBounds.getPosition().x + collidableBounds.width - playerBounds.getPosition().x;
			}

			if (playerBounds.getPosition().y + playerBounds.height < collidableBounds.getPosition().y + collidableBounds.height) {
				//se player coldiu por cima
				y = playerBounds.getPosition().y + playerBounds.height - collidableBounds.getPosition().y;
			}
			else {
				//se player colidiu por baixo
				y = collidableBounds.getPosition().y + collidableBounds.height - playerBounds.getPosition().y;
			}

			if (y < x) {
				pE->move(sf::Vector2f(0, -y));
				pE->setVerticalVelocity(0);
			}
			else {
				pE->move(sf::Vector2f(-x, 0));
				pE->setHorizontalVelocity(0);
			}


		}
		collidables->next();
	}
}

void CollisionManager::setCollidables(EntityList* pC)
{
	collidables = pC;
}

const bool CollisionManager::isColliding(sf::FloatRect one, sf::FloatRect other){
	return (one.intersects(other));
}