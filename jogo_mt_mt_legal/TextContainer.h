#pragma once
#include "Entity.h"

namespace Entities {
	class TextContainer : public Entity
	{
	private:
		sf::Text* text;
		static sf::Font font;
		static sf::Font getFont();
	public:
		TextContainer();
		~TextContainer();
		void draw();
		void execute();
		void save(LevelSave* save);
		void write(std::string sText);
		void setTextPosition(float x, float y);
		void setTextFillColor(sf::Color col);
	};
}

