#pragma once
#include "Player.h"
#include "Updatable.h"

class Camera : public sf::View, public Updatable
{
private:
	Entities::Characters::Player* player1;
	Entities::Characters::Player* player2;
	sf::RenderWindow* window;
	float xDefault;
	float yDefault;
public:
	Camera(sf::RenderWindow* renderer);
	~Camera();
	void setWindow(sf::RenderWindow* renderer);
	void setPlayer1(Player* p1);
	void setPlayer2(Player* p2);
	void execute();
};

