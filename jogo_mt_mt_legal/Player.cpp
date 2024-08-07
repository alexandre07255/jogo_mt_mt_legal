#include "Player.h"
#include "inputManager.h"

void Player::movement() {
	float friccao = 0.1;
	sf::Vector2f vetorDesloc(1,0);
	inputManager* inputInstace = inputManager::getInstance();
	
	if (inputInstace->isRightPressed(player2)) {
		if (horizontalSpeed < MAX_HORIZONTAL_SPEED) {
			horizontalSpeed += ACCELARATION;
		}
		else {
			horizontalSpeed = MAX_HORIZONTAL_SPEED;
		}
	}
	else if (inputInstace->isLeftPressed(player2)) {
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

	move(vetorDesloc);
}

float Player::MAX_HORIZONTAL_SPEED(1);
float Player::MAX_VERTICAL_SPEED(1);
float Player::ACCELARATION(0.2);