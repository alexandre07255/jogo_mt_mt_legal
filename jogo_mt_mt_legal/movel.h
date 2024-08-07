#pragma once
#include "MyDrawable.h"

class movel: public MyDrawable
{
private:
	int horizontalSpeed;
	int verticalSpeed;
	sf::Vector2f deslocamento;
public:
	movel() :MyDrawable(), horizontalSpeed(1), verticalSpeed(1) { deslocamento.x = 0; deslocamento.y = 0; }
	int getNormaDeslocamento(){
		return sqrt(deslocamento.x * deslocamento.x + deslocamento.y * deslocamento.y);
	}

	sf::Vector2f getDeslocamento() { return deslocamento; }

	void setDeslocamento(sf::Vector2f vetor) { deslocamento = vetor; }
};

