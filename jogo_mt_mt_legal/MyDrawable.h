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
	
	const float bottom() const;
	const float top() const;
	const float left() const;
	const float right() const;
	const float xMid() const;
	const float yMid() const;

	virtual ~MyDrawable();
	void setTextura(string path);
	int getId();
};



