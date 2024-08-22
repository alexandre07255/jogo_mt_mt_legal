#pragma once
#include <SFML/Graphics.hpp>

#include <string>
using namespace std;

class MyDrawable : public sf::RectangleShape
{
protected:
	static int idCont;
	int id;
public:
	MyDrawable(string path, sf::Vector2f size, sf::Vector2f pos);
	MyDrawable();
	virtual ~MyDrawable();
	void setTextura(string path);
	int getId();
};



