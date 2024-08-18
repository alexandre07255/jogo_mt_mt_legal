#pragma once
#include "Button.h"
#include "Scene.h"
#include <list>

class Menu: public Scene
{
private:
	list<Button*>* buttonList;
	sf::Vector2f size;
public:
	Menu();
	void setSize(sf::Vector2f _size);

};

