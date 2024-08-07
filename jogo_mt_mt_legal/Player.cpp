#include "Player.h"
#include "inputManager.h"

void Player::movement() {
	float friccao = 0.1;
	sf::Vector2f vetorDesloc(1,0);
	inputManager* inputInstance = inputManager::getInstance();
	
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

	vetorDesloc.x *= horizontalSpeed;

	vetorDesloc.y += 3;

	if (getPosition().y > 250)
		vetorDesloc.y = 0;

	if (inputInstance->isUpPressed(player2))
	{
		vetorDesloc.y -= 10;
	}

	move(vetorDesloc);
}

float Player::MAX_HORIZONTAL_SPEED(10);
float Player::MAX_VERTICAL_SPEED(10);
float Player::ACCELARATION(0.2);