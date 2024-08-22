#include "Support.h"
#include "CollisionManager.h"
#include "Level.h"
#include "SceneManager.h"
#include <iostream>

Support::Support(Platform* plat):Hittable(false,MAXHEALTH),boundedTo(NULL) {
	boundedTo = plat;

	if (boundedTo) {
		SceneManager* instance = SceneManager::getInstance();
		
		Level* active = static_cast<Level*>(instance->top());
		List<Collidable>* collidables = active->getCollidable();

		float positionY = boundedTo->getPosition().y + boundedTo->getSize().y;
		float positionX = boundedTo->getPosition().x + boundedTo->getSize().x / 2;
		setPosition(positionX, positionY);

		int flag = 1;
		float yFinal;

		for (int j = 0;flag;j += 1) {
			//vai caminhandinho com o raio 
			yFinal = positionY + j;

			//cria um rect infinitesimal e testa pra ver se colide com algo
			sf::FloatRect ret;
			ret.height = 1;
			ret.width = 1;

			ret.left = positionX;
			ret.top = yFinal;

			for (ListIterator<Collidable> it = collidables->begin(); (it != collidables->end()) && flag; it++) {
				if (ret.intersects((*it)->getBounds()))
					flag = 0;
			}
		}

		setSize(sf::Vector2f(10.0, yFinal));
	}
}

void Support::setPlatform(Platform* plat) {
	boundedTo = plat;
}

void Support::movement() {
	if (hp <= 0) {
		//remover coisas hehehe
		boundedTo->setOnAir(true);
		SceneManager* sinstance = SceneManager::getInstance();
		Level* level = static_cast<Level*>(sinstance->top());

		level->removeDrawable(this);
		level->removeHittable(this);
		level->removeUpdatable(this);

		delete this;
	}
	std::cout << hp << endl;
}

int Support::MAXHEALTH(10);