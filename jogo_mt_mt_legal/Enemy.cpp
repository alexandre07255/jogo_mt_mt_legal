#include "Enemy.h"
#include"CollisionManager.h"
#include <math.h>
#include "Level.h"
#include "Collidable.h"

Enemy::Enemy() :Alive(false, 10) {
	isWorth = 0;
	setPosition(sf::Vector2f(10, 10));
	setSize(sf::Vector2f(100, 100));
	sightSize = 750;
}

void Enemy::movement() {
	CollisionManager* instance = CollisionManager::getInstance();
	
	switch (state)
	{
	case Alive::FREE:
		movementFREE();
	case Alive::HITSTUN:
		movementHITSTUN();
	}

	instance->testCollison(this);
}

void Enemy::movementFREE()
{
	int friccao = 1;

	sf::Vector2f vetorDesloc(1, 1);

	if (getPosition().x >= 100) {
		horizontalSpeed -= 1;
	}
	else {
		horizontalSpeed += 1;
	}

	//friccao
	if (abs(horizontalSpeed) > friccao) {
		horizontalSpeed -= ((horizontalSpeed > 0) - (horizontalSpeed < 0)) * friccao;
	}
	else
		horizontalSpeed = 0;

	verticalSpeed += 1;

	vetorDesloc.x *= horizontalSpeed;
	vetorDesloc.y *= verticalSpeed;

	move(vetorDesloc);

	raycasting();
}

void Enemy::raycasting() {
	CollisionManager* instance = CollisionManager::getInstance();
	Level* nivel = Level::getActive();

	const double PI = 3.1415;
	const double rayStep = 50;
	EntityList* collidables = instance->getCollidables();
	list<Alive*>* alive = instance->getAliveList();
	int flag = 1;

	sf::Vector2f rayPos;

	double xCenter = getPosition().x + getSize().x / 2;
	double yCenter = getPosition().y + getSize().y;
	
	double yFinal;
	double xFinal;

	for (double i = 3*PI/2;i <  2*PI ;i += 0.1) {
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

			collidables->start();
			for (int k = 0;k < collidables->getSize();k++) {
				Entity* current = collidables->getCurrent();
				if (ret.intersects(current->getGlobalBounds())) {
					flag = 0;
				}
				collidables->next();
			}
			collidables->start();
		}

		Collidable* vertice = new Collidable();
		vertice->setSize(sf::Vector2f(5, 5));
		vertice->setPosition(sf::Vector2f(xFinal, yFinal));

		nivel->addDrawable(vertice);
	}
	
}
void Enemy::movementHITSTUN()
{
	if (stun <= 0)
	{
		state = Alive::FREE;
		setFillColor(sf::Color::White);
	}
	else
	{
		stun--;
		setFillColor(sf::Color::Red);
	}
}