#include "Level.h"
#include "graphics.h"
#include "Player.h"
#include "CollisionManager.h"
#include "EnemyMelee.h"

Level::Level(): aliveList(NULL),collidables(NULL), endX(0), endingOnRight(1), pPlayer1(NULL), pPlayer2(NULL)
{
    aliveList = new list<Alive*>;
    collidables = new list<Collidable*>;
}

Level::~Level() //TODO
{
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



