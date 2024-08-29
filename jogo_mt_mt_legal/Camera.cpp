#include "LevelSave.h"
#include "Camera.h"
#include <iostream>
using namespace Entities::Characters;
using namespace Entities;


Camera::Camera(sf::RenderWindow* renderer) :
	player1(NULL),
	player2(NULL)
{
	setWindow(renderer);
	xDefault = renderer->getSize().x/2;
	yDefault = renderer->getSize().y / 2;
	view.setSize((sf::Vector2f)window->getSize());
	//setSize(sf::Vector2f(xDefault, yDefault));
	//setViewport(sf::FloatRect(0, 0, 0.5f, 0.5f));
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

void Camera::execute()
{
	if (player2){
		int x = (player1->left() + player2->left())/2;
		int y = (player1->top() + player2->top()) / 2;
		view.setCenter(sf::Vector2f(x,y));
		//por enquanto so da account ao player 1 sair de vista, ajustar melhor ainda esta tremelique
		if ((player1->right() + 200 > view.getCenter().x + view.getSize().x / 2 || player1->left() - 200 < view.getCenter().x - view.getSize().x / 2) != (player2->right() + 200 > view.getCenter().x + view.getSize().x / 2 || player2->left() - 200 < view.getCenter().x - view.getSize().x / 2))
		{
			while ((player1->right() + 200 > view.getCenter().x + view.getSize().x / 2 || player1->left() - 200 < view.getCenter().x - view.getSize().x / 2) != (player2->right() + 200 > view.getCenter().x + view.getSize().x / 2 || player2->left() - 200 < view.getCenter().x - view.getSize().x / 2)) {
				view.zoom(1.001f);
			}
		}
		else if (view.getSize().x > window->getSize().x && !(player1->right() + 250 > view.getCenter().x + view.getSize().x / 2 || player1->left() - 250 < view.getCenter().x - view.getSize().x / 2) != (player2->right() + 200 > view.getCenter().x + view.getSize().x / 2 || player2->left() - 200 < view.getCenter().x - view.getSize().x / 2)) {
			while (view.getSize().x > window->getSize().x && !(player1->right() + 250 > view.getCenter().x + view.getSize().x / 2 || player1->left() - 250 < view.getCenter().x - view.getSize().x / 2) != (player2->right() + 200 > view.getCenter().x + view.getSize().x / 2 || player2->left() - 200 < view.getCenter().x - view.getSize().x / 2))
				view.zoom(0.999f);
		}
	}

	else if (player1) {
		view.setCenter(player1->getXPosition(), player1->getYPosition());
	}

	//setSize((sf::Vector2f)window->getSize());
	window->setView(view);
}

void Camera::save(LevelSave* save) { }