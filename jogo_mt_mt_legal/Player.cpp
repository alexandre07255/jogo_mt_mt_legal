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
	isStillJumping(0),
	player2(isPlayer2),
	attackBuffer(0),
	wasAttackPressed(0),
	friction(1),
	attackCounter(0),
	hasAttacked(0),
	attackStartup{20, 15, 15},
	attackHitboxDuration{5, 5, 5},
	attackEndLag{20, 15, 15}
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
	case ATTACK:
		movementATTACK();
		break;
	}
	
	collisionInstance->testCollison(this);
}

void Player::movementFREE()
{
	//Só para mostrar os states
	if (player2)
		setFillColor(sf::Color::Magenta);
	else
		setFillColor(sf::Color::Cyan);


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
		verticalSpeed = -JUMP_STRENGTH;
		jumpBuffer = 0;
		onAir = 1;
	}

	if (attackBuffer)
	{
		hasAttacked = 0;
		attackCounter = 0;
		attackBuffer = 0;
		state = ATTACK;
		stun = attackStartup[attackCounter] + attackHitboxDuration[attackCounter] + attackEndLag[attackCounter];
	}

	verticalSpeed += 1;

	vetorDesloc.x *= horizontalSpeed;

	vetorDesloc.y *= verticalSpeed;

	move(vetorDesloc);
}

void Player::movementATKCANCEL()
{
	if (stun > 0)
	{
		setFillColor(sf::Color::Green);
		if (attackBuffer)
		{
			if (attackCounter < 3)
			{
				state = ATTACK;
				stun = attackStartup[attackCounter] + attackHitboxDuration[attackCounter] + attackEndLag[attackCounter] + 1;
				attackBuffer = 0;
				hasAttacked = 0;
			}
		}
		stun--;
	}
	else
		state = FREE;
}

void Player::movementATTACK()
{
	if (stun > 0)
	{
		setFillColor(sf::Color::Blue);

		if (!hasAttacked && (attackCounter < 3) && (stun == (attackHitboxDuration[attackCounter] + attackEndLag[attackCounter])))
		{
			attack();
			hasAttacked = 1;
		}
		stun--;
	}
	else
		state = FREE;
}

void Player::attack()
{
	AttackHitbox* hitbox = new AttackHitbox();

	hitbox->setTarget(0);
	hitbox->setOwner(this);
	hitbox->setBoundedTo(this);
	hitbox->setDuration(attackHitboxDuration[attackCounter]);
	int horKnock = 0;

	switch (attackCounter)
	{
	case 0:
		hitbox->setSize(sf::Vector2f(50, 100));
		hitbox->setVerKnockback(-10);
		hitbox->setDamage(1);
		hitbox->setHitstun(15);
		horKnock = 30;
		if (facingRight)
		{
			hitbox->setRelativePosition(sf::Vector2f(getSize().x - 10, 0));
			hitbox->setHorKnockback(horKnock);
		}
		else
		{
			int relX = hitbox->getSize().x;
			hitbox->setRelativePosition(sf::Vector2f(-relX + 10, 0));
			hitbox->setHorKnockback(-horKnock);
		}
		break;
	case 1:
		hitbox->setSize(sf::Vector2f(100, 50));
		hitbox->setVerKnockback(-10);
		hitbox->setDamage(1);
		hitbox->setHitstun(35);
		horKnock = 60;
		if (facingRight)
		{
			hitbox->setRelativePosition(sf::Vector2f(getSize().x - 10, 25));
			hitbox->setHorKnockback(horKnock);
		}
		else
		{
			int relX = hitbox->getSize().x;
			hitbox->setRelativePosition(sf::Vector2f(-relX + 10, 25));
			hitbox->setHorKnockback(-horKnock);
		}
		break;
	case 2:
		hitbox->setSize(sf::Vector2f(100, 100));
		hitbox->setVerKnockback(-30);
		hitbox->setDamage(1);
		hitbox->setHitstun(50);
		horKnock = 40;
		if (facingRight)
		{
			hitbox->setRelativePosition(sf::Vector2f(getSize().x - 10, -50));
			hitbox->setHorKnockback(horKnock);
		}
		else
		{
			int relX = hitbox->getSize().x;
			hitbox->setRelativePosition(sf::Vector2f(-relX + 10, -50));
			hitbox->setHorKnockback(-horKnock);
		}
		break;
	}
	attackCounter++;
}

const int Player::MAX_JUMP_BUFFER(8);
const int Player::JUMP_STRENGTH(20);

const int Player::MAX_HORIZONTAL_SPEED(10);
const int Player::MAX_VERTICAL_SPEED(15);
const int Player::ACCELARATION(2);

const int Player::MAX_HP(20);

const int Player::MAX_ATTACK_BUFFER(20);