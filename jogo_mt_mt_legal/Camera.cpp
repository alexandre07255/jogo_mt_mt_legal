#include "Camera.h"

Camera::Camera(sf::RenderWindow* renderer) :
	player1(NULL),
	player2(NULL)
{
	setSize(sf::Vector2f(1000.f, 1000.f));
	setWindow(renderer);
}

Camera::~Camera()
{

}

void Camera::setPlayer1(Player* p1)
{
	player1 = p1;
}

void Camera::setPlayer2(Player* p2)
{
	player2 = p2;
}

void Camera::setWindow(sf::RenderWindow* renderer) { window = renderer; }

void Camera::movement()
{
	if (player2){
		int x = (player1->getPosition().x + player2->getPosition().x)/2;
		int y = (player1->getPosition().y + player2->getPosition().y) / 2;
		setCenter(sf::Vector2f(x,y));
	}

	else if (player1) {
		setCenter(player1->getPosition());
	}
	setSize((sf::Vector2f)window->getSize());
	window->setView(*this);
}