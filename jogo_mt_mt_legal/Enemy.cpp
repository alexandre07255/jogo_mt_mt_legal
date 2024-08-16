#include "Enemy.h"
#include"CollisionManager.h"
#include <math.h>
#include "Level.h"
#include "Collidable.h"
#include <iostream>

Enemy::Enemy() :Alive(false, 10) {
	isWorth = 0;
	setPosition(sf::Vector2f(10, 10));
	setSize(sf::Vector2f(100, 100));
	sightSize = 500;
	followingPlayer = NULL;
	state = PATROLLING;
	timer = 0;
}

void Enemy::movement() {
	CollisionManager* instance = CollisionManager::getInstance();

	switch (state)
	{
	case PATROLLING:
		movementPATROLLING();
		break;
	case HITSTUN:
		movementHITSTUN();
		break;
	case FOLLOWING:
		movementFOLLOWING();
		break;
	}

	instance->testCollison(this);

	//std::cout << state << endl;
}

void Enemy::movementPATROLLING()
{
	int friccao = 1;
	int timeCycle = 60;

	sf::Vector2f vetorDesloc(1, 1);

	if (timer < timeCycle/2) {
		if (horizontalSpeed > -MAX_HORIZONTAL_SPEED) {
			horizontalSpeed -= ACCELARATION;
		}
		else {
			horizontalSpeed = -MAX_HORIZONTAL_SPEED;
		}
		facingRight = 0;
		timer++;
	}
	else if (timer == timeCycle/2)
	{
		horizontalSpeed = 0;
		timer++;
	}
	else if (timer < timeCycle) {
		if (horizontalSpeed < MAX_HORIZONTAL_SPEED) {
			horizontalSpeed += ACCELARATION;
		}
		else {
			horizontalSpeed = MAX_HORIZONTAL_SPEED;
		}
		facingRight = 1;
		timer++;
	}
	else {
		horizontalSpeed = 0;
		timer = 0;
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

	followingPlayer = searchPlayer();

	if (followingPlayer) {
		state = FOLLOWING;
	}
}

Player* Enemy::searchPlayer() {
	CollisionManager* instance = CollisionManager::getInstance();
	Level* nivel = Level::getActive();

	const double PI = 3.1415;
	const double rayStep = 50;
	list<Collidable*>* collidables = instance->getCollidables();
	list<Alive*>* alive = instance->getAliveList();
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
		upperLimit = 2 * PI;
		lesserLimit = 3 * PI / 2;
	}
	else {
		upperLimit = 3 * PI / 2;;
		lesserLimit = PI;
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

			for (list<Alive*>::iterator it = alive->begin();it != alive->end();it++) {
				if (ret.intersects((*it)->getGlobalBounds()) && (*it)->getIsAlly()) {
					//std::cout << "player achado" << endl;
					return (Player*)*it;
				}
			}

			for (list<Collidable*>::iterator it = collidables->begin(); (it != collidables->end()) && flag; it++) {
				if (ret.intersects((*it)->getGlobalBounds()))
					flag = 0;
			}
		}

		/*Collidable* vertice = new Collidable();
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
		state = Alive::PATROLLING;
		setFillColor(sf::Color::White);
	}
	else
	{
		stun--;
		setFillColor(sf::Color::Red);
	}
}

void Enemy::movementFOLLOWING() {
	int friccao = 1;

	sf::Vector2f vetorDesloc(1, 1);

	if (followingPlayer->getPosition().x > getPosition().x) {
		if (horizontalSpeed < MAX_HORIZONTAL_SPEED) {
			horizontalSpeed += ACCELARATION;
		}
		else {
			horizontalSpeed = MAX_HORIZONTAL_SPEED;
		}
		facingRight = 1;
	}
	else {
		if (horizontalSpeed > -MAX_HORIZONTAL_SPEED) {
			horizontalSpeed -= ACCELARATION;
		}
		else {
			horizontalSpeed = -MAX_HORIZONTAL_SPEED;
		}
		facingRight = 0;
	}

	if (abs(horizontalSpeed) > friccao) {
		horizontalSpeed -= ((horizontalSpeed > 0) - (horizontalSpeed < 0)) * friccao;
	}
	else
		horizontalSpeed = 0;

	verticalSpeed += 1;

	vetorDesloc.x *= horizontalSpeed;
	vetorDesloc.y *= verticalSpeed;

	move(vetorDesloc);

	followingPlayer = searchPlayer();

	if (!followingPlayer) {
		state = PATROLLING;
	}
}

const int Enemy::MAX_HORIZONTAL_SPEED(6);
const int Enemy::ACCELARATION(2);