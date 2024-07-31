#pragma once
#include <SFML/Graphics.hpp>

#include <string>
using namespace std;

class MyDrawable : public sf::RectangleShape
{
public:
	MyDrawable(string path, sf::Vector2f size, sf::Vector2f pos);
};



