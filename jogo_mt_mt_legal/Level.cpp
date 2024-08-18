#include "Level.h"
#include "graphics.h"
#include "Player.h"
#include "CollisionManager.h"
#include "EnemyMelee.h"

Level* Level::active(NULL);

Level::Level(): drawables(NULL), updatables(NULL), aliveList(NULL), collidables(NULL), pPlayer1(NULL), pPlayer2(NULL), endingOnRight(1), endX(0)
{
    drawables = new list<MyDrawable*>;
    updatables = new list<Updatable*>;
    aliveList = new list<Alive*>;
    collidables = new list<Collidable*>;
}

Level::~Level() //TODO
{

}

void Level::setDrawables(list<MyDrawable*>* drawlist) {
	drawables = drawlist;
}

list<MyDrawable*>* Level::getDrawables() const
{
	return drawables;
}

void Level::setUpdatables(list<Updatable*>* updatelist) {
	updatables = updatelist;
}

list<Updatable*>* Level::getUpdatables() const
{
	return updatables;
}

void Level::draw(sf::RenderWindow* window) {
	list<MyDrawable*>::iterator itCurrent = drawables->begin();
	if (drawables->size() > 1)
	{
		list<MyDrawable*>::iterator itNext = itCurrent;
		itNext++;
		while (itNext != drawables->end())
		{
			window->draw(*(*itCurrent));
			itCurrent = itNext;
			itNext++;
		}
		window->draw(*(*itCurrent));
	}
	else if (drawables->size() == 1)
		window->draw(*(*itCurrent));
}

void Level::update()
{
	list<Updatable*>::iterator itCurrent = updatables->begin();
	if (updatables->size() > 1)
	{
		list<Updatable*>::iterator itNext = itCurrent;
		itNext++;
		while (itNext != updatables->end())
		{
			(*itCurrent)->movement();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->movement();
	}
	else if (updatables->size() == 1)
		(*itCurrent)->movement();

	if (endingOnRight)
	{
		if (pPlayer1->getPosition().x + pPlayer1->getSize().x / 2 > endX)
			levelCompleteHandler();
		else if (pPlayer2 != NULL)
			if (pPlayer2->getPosition().x + pPlayer2->getSize().x / 2 > endX)
				levelCompleteHandler();
	}
	else
	{
		if (pPlayer1->getPosition().x + pPlayer1->getSize().x / 2 < endX)
			levelCompleteHandler();
		else if (pPlayer2 != NULL)
			if (pPlayer2->getPosition().x + pPlayer2->getSize().x / 2 < endX)
				levelCompleteHandler();
	}
}

Level* Level::getActive()
{
	return active;
}

void Level::setActive(Level* pL) //Usar em algum outro lugar (tipo gerenciador/pilha de states)
{
	active = pL;
}

void Level::addUpdatable(Updatable* pU)
{
	updatables->push_back(pU);
}

void Level::addDrawable(Entity* pD) {
	drawables->push_back(pD);
}

