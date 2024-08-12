#pragma once
#include "Enemy.h"
#include "Player.h"

class EnemyMelee : public Enemy
{
private:
	Player* isSeeing;
	void follow();

public:
	
};

