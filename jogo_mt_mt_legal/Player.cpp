#include "Player.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "AttackHitbox.h"
#include "Level.h"

#include <iostream>
using namespace std;

Player::Player(const bool isPlayer2, const bool ally, const int health) :
	Alive(1, MAX_HP),
	jumpBuffer(0),
	player2(isPlayer2),
	attackBuffer(0),
	wasAttackPressed(0),
	friction(1),
	attackCounter(0)
{
	
}

void Player::movement() {

	InputManager* inputInstance = InputManager::getInstance();
	CollisionManager* collisionInstance = CollisionManager::getInstance();
	
	//Attack input
	if (inputInstance->isAttackPressed(player2))
	{
		if (!wasAttackPressed)
			attackBuffer = MAX_ATTACK_BUFFER;
		else if (attackBuffer > 0)
			attackBuffer--;

		wasAttackPressed = 1;
	}
	else
	{
		if (attackBuffer > 0)
			attackBuffer--;

		wasAttackPressed = 0;
	}

	//Jump input
	if (inputInstance->isUpPressed(player2))
	{
		jumpBuffer = MAX_JUMP_BUFFER;
	}
	else if (jumpBuffer > 0)
		jumpBuffer--;

	switch (state)
	{
	case FREE:
		movementFREE();
		break;
	case ATKCANCEL:
		movementATKCANCEL();
		break;
	}
	

	if (inputInstance->isDownPressed(player2))
	{
		
	}

	collisionInstance->testCollison(this);
}

void Player::movementFREE()
{
	sf::Vector2f vetorDesloc(1, 1);
	
	InputManager* inputInstance = InputManager::getInstance();
	//Movement input
	if (inputInstance->isRightPressed(player2)) {
		if (horizontalSpeed < MAX_HORIZONTAL_SPEED) {
			horizontalSpeed += ACCELARATION;
		}
		else {
			horizontalSpeed = MAX_HORIZONTAL_SPEED;
		}
		facingRight = 1;
	}
	else if (inputInstance->isLeftPressed(player2)) {
		if (horizontalSpeed > -MAX_HORIZONTAL_SPEED) {
			horizontalSpeed -= ACCELARATION;
		}
		else {
			horizontalSpeed = -MAX_HORIZONTAL_SPEED;
		}
		facingRight = 0;
	}

	//friction
	if (abs(horizontalSpeed) > friction) {
		horizontalSpeed -= ((horizontalSpeed > 0) - (horizontalSpeed < 0)) * friction;
	}
	else
		horizontalSpeed = 0;



	if (!onAir && jumpBuffer)
	{
		verticalSpeed = -JUMP_STREGTH;
		jumpBuffer = 0;
		onAir = 1;
	}

	if (attackBuffer)
	{
		attackCounter = 0;

		if (facingRight)
		{
			AttackHitbox* hitbox = new AttackHitbox(0, this, this,
				sf::Vector2f(0, 0), 10, sf::Vector2f(100, 100));
			hitbox->setHorKnockback(20);
			hitbox->setVerKnockback(10);
			hitbox->setDamage(1);
			hitbox->setHitstun(10);
		}
	}

	verticalSpeed += 1;

	vetorDesloc.x *= horizontalSpeed;

	vetorDesloc.y *= verticalSpeed;

	move(vetorDesloc);
}

void Player::movementATKCANCEL()
{
	if (attackBuffer)
	{
		switch (attackCounter)
		{
		case 1:

			break;
		case 2:

			break;
		}
		AttackHitbox* hitbox = new AttackHitbox(0, this, this,
			sf::Vector2f(0, 0), 10, sf::Vector2f(100, 100));
		hitbox->setHorKnockback(20);
		hitbox->setVerKnockback(10);
		hitbox->setDamage(1);
		hitbox->setHitstun(10);
	}
}


const int Player::MAX_JUMP_BUFFER(8);
const int Player::JUMP_STREGTH(20);

const int Player::MAX_HORIZONTAL_SPEED(10);
const int Player::MAX_VERTICAL_SPEED(15);
const int Player::ACCELARATION(2);

const int Player::MAX_HP(20);

const int Player::MAX_ATTACK_BUFFER(3);