#pragma once
#include "Player.h"
#include "Background.h"
#include "TextContainer.h"

class Camera : public Being
{
private:
	Entities::Characters::Player* player1;
	Entities::Characters::Player* player2;
	sf::View view;
	sf::RenderWindow* window;
	Entities::Background* background;
	bool firstStep;
	Entities::TextContainer* p1Health;
	Entities::TextContainer* p2Health;

public:
	Camera(sf::RenderWindow* renderer, Entities::Background* pBackground, Entities::TextContainer* p1H, Entities::TextContainer* p2H);
	~Camera();
	void setWindow(sf::RenderWindow* renderer);
	void setPlayer1(Entities::Characters::Player* p1);
	void setPlayer2(Entities::Characters::Player* p2);
	void execute();
};


