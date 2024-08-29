#pragma once
#include "GraphicManager.h"

class Being
{
protected:
	int id;
	static int idCont;
	static Managers::GraphicManager* pGG;
	sf::RectangleShape* pShape;
	sf::Texture* pTexture;
public:
	Being();
	virtual ~Being();
	virtual void execute() = 0;
	virtual void draw();
	const int getId() const;
	sf::RectangleShape* getShape();
	void setShape(sf::RectangleShape* rect);
	sf::Texture* getTexture();
	void setTexture(sf::Texture* ptext);
	
};

