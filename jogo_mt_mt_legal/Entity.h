#pragma once
#include "Being.h"

class LevelSave;

namespace Entities {
	class Entity : public Being
	{
	protected:
		bool onAir;
		float frictionFelt;
		static const float GRAVITY;

		float xPos;
		float yPos;
		
		float horizontalVelocity;
		float verticalVelocity;

		float height;
		float width;

		int frameCont;
		int spriteMatrixIndex;
		int spriteX;
		int spriteY;
	public:
		Entity();
		virtual ~Entity();

		const bool getOnAir() const;
		void setOnAir(const bool value);
		void setFriction(float fric);

		void setSize(const float x, const float y);
		void setSize(const sf::Vector2f& vec);
		const float getXSize() const;
		const float getYSize() const;

		void setPosition(const float x, const float y);
		void setPosition(const sf::Vector2f& vec);
		const float getXPosition() const;
		const float getYPosition() const;


		sf::FloatRect getGlobalBounds() const;

		void move(const float x, const float y);
		void move(const sf::Vector2f & vec);

		void setHorizontalVelocity(const float hV);
		void setVerticalVelocity(const float vV);

		const float right() const;
		const float left() const;
		const float top() const;
		const float bottom() const;
		const float xMid() const;
		const float yMid() const;

		void setFillColor(const sf::Color & col);

		virtual void save(LevelSave* save) = 0;
		virtual void execute() = 0;
	};
}

