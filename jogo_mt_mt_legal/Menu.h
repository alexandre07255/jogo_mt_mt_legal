#pragma once
#include "Button.h"
#include "Scene.h"
#include "List.h"
#include "List.h"

class Menu: public Scene
{
protected:
	List<Button>* buttonList;
	sf::Vector2f size;
public:
	Menu();
	void setSize(sf::Vector2f _size);
	void addButton(Button* but);

};

