#pragma once
#include "Player.h"
#include "Background.h"

class Camera : public Being
{
private:
	Entities::Characters::Player* player1;
	Entities::Characters::Player* player2;
	sf::View view;
	sf::RenderWindow* window;
	Entities::Background* background;
	bool firstStep;
public:
	Camera(sf::RenderWindow* renderer, Entities::Background* pBackground);
	~Camera();
	void setWindow(sf::RenderWindow* renderer);
	void setPlayer1(Entities::Characters::Player* p1);
	void setPlayer2(Entities::Characters::Player* p2);
	void execute();
};


