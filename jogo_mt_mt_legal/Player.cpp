#include "Player.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "Hitbox.h"
#include "Level.h"

Player::Player(const bool isPlayer2) :
	jumpBuffer(0),
	player2(isPlayer2)
{

}

void Player::movement() {
	int friccao = 1;
	sf::Vector2f vetorDesloc(1,1);
	InputManager* inputInstance = InputManager::getInstance();
	CollisionManager* collisionInstance = CollisionManager::getInstance();
	
	if (inputInstance->isRightPressed(player2)) {
		if (horizontalSpeed < MAX_HORIZONTAL_SPEED) {
			horizontalSpeed += ACCELARATION;
		}
		else {
			horizontalSpeed = MAX_HORIZONTAL_SPEED;
		}
	}
	else if (inputInstance->isLeftPressed(player2)) {
		if (horizontalSpeed > -MAX_HORIZONTAL_SPEED) {
			horizontalSpeed -= ACCELARATION;
		}
		else {
			horizontalSpeed = -MAX_HORIZONTAL_SPEED;
		}
	}
	//friccao
	if (abs(horizontalSpeed) > friccao) {
		horizontalSpeed -= ((horizontalSpeed > 0) - (horizontalSpeed < 0)) * friccao;
	}
	else
		horizontalSpeed = 0;

	if (inputInstance->isUpPressed(player2))
	{
		jumpBuffer = MAX_JUMP_BUFFER;
	}

	if (!onAir && jumpBuffer)
	{
		verticalSpeed = -JUMP_STREGTH;
		jumpBuffer = 0;
		onAir = 1;
	}
	else if (jumpBuffer > 0)
		jumpBuffer--;

	verticalSpeed += 1;

	vetorDesloc.x *= horizontalSpeed;

	vetorDesloc.y *= verticalSpeed;


	if (inputInstance->isDownPressed(player2))
	{
		Hitbox* hitbox = new Hitbox(1, this, 0);
		hitbox->setFillColor(sf::Color::Yellow);
		hitbox->setPosition(getPosition());
		hitbox->setSize(sf::Vector2f(100, 100));
		Level* level = Level::getActive();
		EntityList* drawables = level->getDrawables();
		drawables->pushBack(hitbox);
	}


	move(vetorDesloc);

	collisionInstance->testCollison(this);
}

const int Player::MAX_JUMP_BUFFER(8);
const int Player::JUMP_STREGTH(20);

const int Player::MAX_HORIZONTAL_SPEED(10);
const int Player::MAX_VERTICAL_SPEED(15);
const int Player::ACCELARATION(2);