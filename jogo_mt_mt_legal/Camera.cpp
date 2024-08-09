#include "Camera.h"

Camera::Camera() :
	player1(NULL),
	player2(NULL)
{

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

void Camera::movement()
{

}