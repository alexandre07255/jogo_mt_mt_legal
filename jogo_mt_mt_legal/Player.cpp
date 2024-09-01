#include "Player.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "LevelSave.h"
#include "AttackHitbox.h"
#include "Level.h"
#include "SpriteManager.h"

#include <iostream>
using namespace std;
using namespace Managers;
using namespace Entities::Characters;
using namespace Scenes;
using namespace Entities::Hitboxes;


Player::Player(const bool isPlayer2, const int health) :
	Hittable(1, health),
	jumpBuffer(0),
	isStillJumping(0),
	jumpLength(0),
	player2(isPlayer2),
	attackBuffer(0),
	wasAttackPressed(0),
	attackCounter(0),
	hasAttacked(0),
	attackStartup{24, 24, 24},
	attackHitboxDuration{12, 18, 18},
	attackEndLag{18, 18, 24}
{
	//setSize(sf::Vector2f(108.f, 132.f));
	//Base 36 / 44
	setSize(sf::Vector2f(22.f * 3, 30.f * 3));

	SpriteManager* spInstance = SpriteManager::getInstance();
	if (!isPlayer2)
		spriteMatrixIndex = spInstance->getMatrixIndex("Samurai1");
	else
		spriteMatrixIndex = spInstance->getMatrixIndex("Samurai2");

	spInstance->getTexture(this, spriteMatrixIndex, 0, 0);
	
	
	//hp = 1;
	//if (pTexture)
		//pTexture->setRepeated(1);

	pShape->setOrigin(width / 2.f, 0);

	//setSize(sf::Vector2f(21.f * 3, 30.f * 3));
	pShape->setTextureRect(sf::IntRect(0, 14, 22, 30));
	//pShape->setScale(-1.f, 1.f);
	//pShape->setScale(1.f, 1.f);
	//pShape->setTextureRect(sf::IntRect(0, -44, 36, 44));
}

Player::~Player() {}

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
	default:
		executeFREE();
		break;
	}

	SpriteManager* spInstance = SpriteManager::getInstance();
	if (frameCont >= 6)
	{
		spInstance->next(this, spriteMatrixIndex, spriteX, spriteY);
		frameCont = 0;
	}
	else
	{
		spInstance->getTexture(this, spriteMatrixIndex, spriteX, spriteY);
		frameCont++;
	}

	if (fireRemaining)
	{
		setFillColor(sf::Color::Color(sf::Uint32(4286578943)));
		if (fireCont > 40)
		{
			hp--;
			fireRemaining--;
			fireCont = 0;

			if (!fireRemaining)
				setFillColor(sf::Color::White);
		}
		else
			fireCont++;
	}
}

void Player::executeFREE()
{
	//Só para mostrar os states
	
	InputManager* inputInstance = InputManager::getInstance();
	//Movement input
	if (inputInstance->isRightPressed(player2)) {
		if (horizontalVelocity < MAX_HORIZONTAL_VELOCITY) {
			horizontalVelocity += ACCELARATION;
		}
		else {
			horizontalVelocity = MAX_HORIZONTAL_VELOCITY;
		}

		if (spriteY != 2)
		{
			frameCont = 0;
			spriteX = 0;
			spriteY = 2;
		}

		facingRight = 1;
		pShape->setScale(1.f, 1.f);
	}
	else if (inputInstance->isLeftPressed(player2)) {
		if (horizontalVelocity > -MAX_HORIZONTAL_VELOCITY) {
			horizontalVelocity -= ACCELARATION;
		}
		else {
			horizontalVelocity = -MAX_HORIZONTAL_VELOCITY;
		}

		if (spriteY != 2)
		{
			frameCont = 0;
			spriteX = 0;
			spriteY = 2;
		}

		facingRight = 0;
		pShape->setScale(-1.f, 1.f);
	}
	else if (spriteY != 0 && !onAir)
	{
		frameCont = 0;
		spriteX = 0;
		spriteY = 0;
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

	if (onAir)
	{
		frameCont = 0;
		spriteY = 1;
		if (verticalVelocity > 0)
			spriteX = 2;
		else
			spriteX = 3;
	}

	if (attackBuffer)
	{
		hasAttacked = 0;
		attackCounter = 0;
		attackBuffer = 0;

		frameCont = 0;
		spriteX = 0;
		spriteY = 3;

		setSize(sf::Vector2f(36.f * 3, 44.f * 3));
		pShape->setTextureRect(sf::IntRect(0, 0, 36, 44));
		
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
		if (attackBuffer)
		{
			if (attackCounter < 3)
			{
				frameCont = 0;
				spriteY = 3 + attackCounter;
				spriteX = 0;

				state = ATTACK;
				stun = attackStartup[attackCounter] + attackHitboxDuration[attackCounter] + attackEndLag[attackCounter] + 1;
				attackBuffer = 0;
				hasAttacked = 0;
			}
		}
		stun--;
	}
	else
	{
		state = FREE;

		frameCont = 0;
		spriteX = 0;
		spriteY = 0;

		float prevHeight = height;
		setSize(sf::Vector2f(22.f * 3, 30.f * 3));
		move(0, prevHeight - height);
		pShape->setTextureRect(sf::IntRect(0, 14, 22, 30));
	}
}

void Player::executeATTACK()
{
	if (stun > 0)
	{
		if (!hasAttacked && (attackCounter < 3) && (stun == (attackHitboxDuration[attackCounter] + attackEndLag[attackCounter])))
		{
			attack();
			hasAttacked = 1;
		}
		stun--;
	}
	else
	{
		state = FREE;

		frameCont = 0;
		spriteX = 0;
		spriteY = 0;

		float prevHeight = height;
		setSize(sf::Vector2f(22.f * 3, 30.f * 3));
		move(0, prevHeight - height);
		pShape->setTextureRect(sf::IntRect(0, 14, 22, 30));
	}
	move((float) horizontalVelocity * 0.15f, (float) (++verticalVelocity) * 0.85f);
	//move(sf::Vector2f(horizontalVelocity*0.15, (++verticalVelocity)*0.85));
}

void Player::executeHITSTUN()
{
	if (stun <= 0)
	{
		state = FREE;

		frameCont = 0;
		spriteX = 0;
		spriteY = 0;

		float prevHeight = height;
		setSize(sf::Vector2f(22.f * 3, 30.f * 3));
		move(0, prevHeight - height);
		pShape->setTextureRect(sf::IntRect(0, 14, 22, 30));

		setFillColor(sf::Color::White);
	}
	else
	{
		frameCont--;
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
		hitbox->setSize(sf::Vector2f(23.f * 5, height));
		hitbox->setVerKnockback(-10.0);
		hitbox->setDamage(3);
		hitbox->setHitstun(24);
		horKnock = 30.0;
		if (facingRight)
		{
			hitbox->setRelativePosition(sf::Vector2f(10.f, 0.0));
			hitbox->setHorKnockback(horKnock);
		}
		else
		{
			float relX = hitbox->getXSize();
			hitbox->setRelativePosition(sf::Vector2f((-relX) - 10, 0.0));
			hitbox->setHorKnockback(-horKnock);
		}
		break;
	case 1:
		hitbox->setSize(sf::Vector2f(200.f, 50.0));
		hitbox->setVerKnockback(-10.0);
		hitbox->setDamage(3);
		hitbox->setHitstun(24);
		horKnock = 60.0;
		if (facingRight)
		{
			hitbox->setRelativePosition(sf::Vector2f(10.f, 25.0));
			hitbox->setHorKnockback(horKnock);
		}
		else
		{
			float relX = hitbox->getXSize();
			hitbox->setRelativePosition(sf::Vector2f(-relX - 10, 25.0f));
			hitbox->setHorKnockback(-horKnock);
		}
		break;
	case 2:
		hitbox->setSize(sf::Vector2f(200.0f, 200.0f));
		hitbox->setVerKnockback(-30.0);
		hitbox->setDamage(3);
		hitbox->setHitstun(32);
		horKnock = 10.0;
		if (facingRight)
		{
			hitbox->setRelativePosition(sf::Vector2f(10.f, -120));
			hitbox->setHorKnockback(horKnock);
		}
		else
		{
			float relX = hitbox->getXSize();
			hitbox->setRelativePosition(sf::Vector2f(-relX - 10, -120));
			hitbox->setHorKnockback(-horKnock);
		}
		break;
	}
	attackCounter++;
}

const int Player::MAX_JUMP_BUFFER(8);
const float Player::JUMP_STRENGTH(2.2f);
const int Player::MAX_JUMP_PERIOD(15);

const float Player::MAX_HORIZONTAL_VELOCITY(10.0f);
const float Player::MAX_VERTICAL_VELOCITY(15.0f);
const float Player::ACCELARATION(2.0f);

const int Player::MAX_HP(30);

const int Player::MAX_ATTACK_BUFFER(20);

void Player::save(LevelSave* save) {
	save->addPlayer(this, player2);
}