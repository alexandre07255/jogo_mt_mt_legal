#pragma once
#include "Button.h"
#include "Scene.h"
#include <list>

class Menu: public Scene
{
protected:
	list<Button*>* buttonList;
	sf::Vector2f size;
public:
	Menu();
	void setSize(sf::Vector2f _size);

};

