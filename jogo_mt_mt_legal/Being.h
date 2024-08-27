#pragma once
#include "GraphicManager.h"


class Being
{
protected:
	int id;
	static int idCont;
	static GraphicManager* pGG;
	sf::RectangleShape* pShape;
	sf::Texture* pTexture;
public:
	Being();
	~Being();
	virtual void execute() = 0;
	virtual void draw();
	sf::RectangleShape* getShape();
	void setShape(sf::RectangleShape* rect);
	sf::Texture* getTexture();
	void setTextureBeing(sf::Texture* ptext);
};

