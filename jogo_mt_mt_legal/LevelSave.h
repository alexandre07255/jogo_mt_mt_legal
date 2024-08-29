#pragma once
#include "Save.h"
#include "Level.h"
#include "EnemyRanged.h"
#include "EnemyMelee.h"
#include "Spike.h"
#include "Fire.h"
#include "Platform.h"
#include "Player.h"

class LevelSave : public Save
{
private:
	Scenes::Level* boundLevel;
public:
	LevelSave(Scenes::Level* bound);
	~LevelSave();

	void addRangedEnemy(Entities::Characters::EnemyRanged* enemy);
	void addMeleeEnemy(Entities::Characters::EnemyMelee* enemy);

	void addSpike(Entities::Obstacles::Spike* obst);
	void addPlatform(Entities::Obstacles::Platform* obst);
	void addFire(Entities::Obstacles::Fire* obst);

	void addPlayer(Entities::Characters::Player* player, bool player2);

	void saveFinal();
};

