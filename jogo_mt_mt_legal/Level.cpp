#include "Level.h"
#include "graphics.h"
#include "Player.h"
#include "CollisionManager.h"
#include "EnemyMelee.h"

Level* Level::active(NULL);

Level::Level(): aliveList(NULL),collidables(NULL)
{
    aliveList = new list<Alive*>;
    collidables = new list<Collidable*>;
}

Level::~Level() //TODO
{

}

Level* Level::getActive()
{
	return active;
}

void Level::setActive(Level* pL) //Usar em algum outro lugar (tipo gerenciador/pilha de states)
{
	active = pL;
}

