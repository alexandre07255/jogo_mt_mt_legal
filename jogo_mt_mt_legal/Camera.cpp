#include "LevelSave.h"
#include "Camera.h"
#include <iostream>
#include "SpriteManager.h"
#include "SceneManager.h"
using namespace Entities::Characters;
using namespace Entities;
using namespace Managers;


Camera::Camera(sf::RenderWindow* renderer, Background* pBackground,TextContainer* p1H, TextContainer* p2H) :
	player1(NULL),
	player2(NULL),
	background(pBackground),
	p1Health(p1H),
	p2Health(p2H)
{
	setWindow(renderer);
	//view.setSize((sf::Vector2f)window->getSize());
	view.setSize((float)window->getSize().x / 1.5, (float)window->getSize().y / 1.5);
}

Camera::~Camera()
{
	player1 = NULL;
	player2 = NULL;
	background = NULL;
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
		background->setSize(view.getSize());
		p2Health->write(std::to_string(player2->getHp()));
	}

	else if (player1) {
		view.setCenter(player1->getXPosition(), player1->bottom() - 45);
	}
	p1Health->write(std::to_string(player1->getHp()));

	background->setPosition(view.getCenter().x - background->getXSize() / 2, view.getCenter().y - background->getYSize() / 2);
	p1Health->setTextPosition(view.getCenter().x - view.getSize().x / 2 + 5.3333*16, view.getCenter().y - view.getSize().y / 2);
	p1Health->setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2);
	if (player2) {
		p2Health->setTextPosition(view.getCenter().x - view.getSize().x / 2 + 5.3333 * 16, view.getCenter().y - view.getSize().y / 2 + 50.f);
		p2Health->setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 + 50.f);
	}

	//setSize((sf::Vector2f)window->getSize());
	window->setView(view);
}

