#pragma once
#include "Player.h"

class Camera : public sf::View
{
private:
	Player* player1;
	Player* player2;
public:
	Camera();
	~Camera();
	void setPlayer1(Player* p1);
	void setPlayer2(Player* p2);
	void movement();
};

