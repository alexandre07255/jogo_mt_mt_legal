#include "Enemy.h"
#include"CollisionManager.h"

Enemy::Enemy() :Alive(false, 10) {
	isWorth = 0;
	setPosition(sf::Vector2f(10, 10));
	setSize(sf::Vector2f(100, 100));
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