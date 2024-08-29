#include "Player.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "LevelSave.h"
#include "AttackHitbox.h"
#include "Level.h"

#include <iostream>
using namespace std;
using namespace Managers;
using namespace Entities::Characters;
using namespace Scenes;
using namespace Entities::Hitboxes;


Player::Player(const bool isPlayer2, const int health) :
	Hittable(1, MAX_HP),
	jumpBuffer(0),
	isStillJumping(0),
	jumpLength(0),
	player2(isPlayer2),
	attackBuffer(0),
	wasAttackPressed(0),
	attackCounter(0),
	hasAttacked(0),
	attackStartup{20, 15, 15},
	attackHitboxDuration{5, 5, 5},
	attackEndLag{20, 15, 15}
{
	setSize(sf::Vector2f(80, 80));

}

void Player::execute() {

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
	else
	{
		isStillJumping = 0;
		if (jumpBuffer > 0)
			jumpBuffer--;
	}

	switch (state)
	{
	case FREE:
		executeFREE();
		break;
	case ATKCANCEL:
		executeATKCANCEL();
		break;
	case ATTACK:
		executeATTACK();
		break;
	case HITSTUN:
		executeHITSTUN();
		break;
	}

	if (fireRemaining)
	{
		if (fireCont > 4)
		{
			hp--;
			fireRemaining--;
			fireCont = 0;
		}
		else
			fireCont++;
	}
}

void Player::executeFREE()
{
	//Só para mostrar os states
	if (player2)
		setFillColor(sf::Color::Magenta);
	else
		setFillColor(sf::Color::Cyan);

	
	InputManager* inputInstance = InputManager::getInstance();
	//Movement input
	if (inputInstance->isRightPressed(player2)) {
		if (horizontalVelocity < MAX_HORIZONTAL_VELOCITY) {
			horizontalVelocity += ACCELARATION;
		}
		else {
			horizontalVelocity = MAX_HORIZONTAL_VELOCITY;
		}
		facingRight = 1;
	}
	else if (inputInstance->isLeftPressed(player2)) {
		if (horizontalVelocity > -MAX_HORIZONTAL_VELOCITY) {
			horizontalVelocity -= ACCELARATION;
		}
		else {
			horizontalVelocity = -MAX_HORIZONTAL_VELOCITY;
		}
		facingRight = 0;
	}

	//friction
	if (abs(horizontalVelocity) > frictionFelt) {
		horizontalVelocity -= ((horizontalVelocity > 0) - (horizontalVelocity < 0)) * frictionFelt;
	}
	else
		horizontalVelocity = 0;

	if (isStillJumping)
	{
		if (jumpLength < MAX_JUMP_PERIOD)
		{
			verticalVelocity -= JUMP_STRENGTH;
			jumpLength++;
		}
	}

	if (!onAir && jumpBuffer)
	{
		verticalVelocity = -JUMP_STRENGTH;
		jumpBuffer = 0;
		onAir = 1;
		isStillJumping = 1;
		jumpLength = 0;
	}

	if (attackBuffer)
	{
		hasAttacked = 0;
		attackCounter = 0;
		attackBuffer = 0;
		state = ATTACK;
		stun = attackStartup[attackCounter] + attackHitboxDuration[attackCounter] + attackEndLag[attackCounter];
	}

	verticalVelocity += 1;

	move(horizontalVelocity, verticalVelocity);
}

void Player::executeATKCANCEL()
{
	if (stun > 0)
	{
		horizontalVelocity = 0;
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

void Player::executeATTACK()
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
	move((float) horizontalVelocity * 0.15, (float) (++verticalVelocity) * 0.85);
	//move(sf::Vector2f(horizontalVelocity*0.15, (++verticalVelocity)*0.85));
}

void Player::executeHITSTUN()
{
	if (stun <= 0)
	{
		state = FREE;
	}
	else
	{
		stun--;
		setFillColor(sf::Color::Red);
	}
}

void Player::attack()
{
	AttackHitbox* hitbox = new AttackHitbox();

	hitbox->setTarget(0);
	hitbox->setOwner(this);
	hitbox->setBoundedTo(this);
	hitbox->setDuration(attackHitboxDuration[attackCounter]);
	float horKnock = 0.0;

	switch (attackCounter)
	{
	case 0:
		hitbox->setSize(sf::Vector2f(50.0, 100.0));
		hitbox->setVerKnockback(-10.0);
		hitbox->setDamage(3);
		hitbox->setHitstun(15);
		horKnock = 30.0;
		if (facingRight)
		{
			hitbox->setRelativePosition(sf::Vector2f(getSize().x - 10, 0.0));
			hitbox->setHorKnockback(horKnock);
		}
		else
		{
			float relX = hitbox->getSize().x;
			hitbox->setRelativePosition(sf::Vector2f(-relX + 10, 0.0));
			hitbox->setHorKnockback(-horKnock);
		}
		break;
	case 1:
		hitbox->setSize(sf::Vector2f(100.0, 50.0));
		hitbox->setVerKnockback(-10.0);
		hitbox->setDamage(3);
		hitbox->setHitstun(35);
		horKnock = 60.0;
		if (facingRight)
		{
			hitbox->setRelativePosition(sf::Vector2f(getSize().x - 10, 25.0));
			hitbox->setHorKnockback(horKnock);
		}
		else
		{
			float relX = hitbox->getSize().x;
			hitbox->setRelativePosition(sf::Vector2f(-relX + 10.0, 25.0));
			hitbox->setHorKnockback(-horKnock);
		}
		break;
	case 2:
		hitbox->setSize(sf::Vector2f(100.0, 100.0));
		hitbox->setVerKnockback(-30.0);
		hitbox->setDamage(3);
		hitbox->setHitstun(50);
		horKnock = 10.0;
		if (facingRight)
		{
			hitbox->setRelativePosition(sf::Vector2f(getSize().x - 10, -50));
			hitbox->setHorKnockback(horKnock);
		}
		else
		{
			float relX = hitbox->getSize().x;
			hitbox->setRelativePosition(sf::Vector2f(-relX + 10, -50));
			hitbox->setHorKnockback(-horKnock);
		}
		break;
	}
	attackCounter++;
}

const int Player::MAX_JUMP_BUFFER(8);
const float Player::JUMP_STRENGTH(2.2);
const int Player::MAX_JUMP_PERIOD(15);

const float Player::MAX_HORIZONTAL_VELOCITY(10.0);
const float Player::MAX_VERTICAL_VELOCITY(15.0);
const float Player::ACCELARATION(2.0);

const int Player::MAX_HP(20);

const int Player::MAX_ATTACK_BUFFER(20);

void Player::save(LevelSave* save) {
	save->addPlayer(this, player2);
}