#include "Level.h"
#include "graphics.h"
#include "Player.h"
#include "CollisionManager.h"
#include "EnemyMelee.h"

Level::Level(): aliveList(NULL),collidables(NULL)
{
    aliveList = new list<Alive*>;
    collidables = new list<Collidable*>;
}

Level::~Level() //TODO
{

}



