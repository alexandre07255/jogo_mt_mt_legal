#include "LevelSave.h"

LevelSave::LevelSave(Scenes::Level* bound) {
	boundLevel = bound;
}
LevelSave::LevelSave() {
	boundLevel = NULL;
}
LevelSave::~LevelSave() {
}

void LevelSave::addRangedEnemy(Entities::Characters::EnemyRanged* enemy) {
	saveJson["EnemyRangedList"].push_back({ {"x",enemy->getXPosition()},{"y",enemy->getYPosition()},{"hp",enemy->getHp()},{"points",enemy->getPoints()} });
}

void LevelSave::addMeleeEnemy(Entities::Characters::EnemyMelee* enemy) {
	saveJson["EnemyMeleeList"].push_back({ {"x",enemy->getXPosition()},{"y",enemy->getYPosition()},{"hp",enemy->getHp()},{"points",enemy->getPoints()} });
}

void LevelSave::addSpike(Entities::Obstacles::Spike* obst) {
	saveJson["SpikeList"].push_back({ {"x",obst->getXPosition()},{"y",obst->getYPosition()},{"height",obst->getYSize()},{"width",obst->getXSize()}});
}

void LevelSave::addPlatform(Entities::Obstacles::Platform* obst) {
	saveJson["PlatformList"].push_back({ {"x",obst->getXPosition()},{"y",obst->getYPosition()},{"height",obst->getYSize()},{"width",obst->getXSize()} });
}

void LevelSave::addFire(Entities::Obstacles::Fire* obst) {
	saveJson["FireList"].push_back({ {"x",obst->getXPosition()},{"y",obst->getYPosition()},{"height",obst->getYSize()},{"width",obst->getXSize()} });
}

void LevelSave::addPlayer(Entities::Characters::Player* player, bool player2) {
	if (player2) {
		saveJson["player2"].push_back({ {"x",player->getXPosition()},{"y",player->getYPosition()},{"hp",player->getHp()},{"points",player->getPoints()} });
	}
	else {
		saveJson["player1"].push_back({ {"x",player->getXPosition()},{"y",player->getYPosition()},{"hp",player->getHp()},{"points",player->getPoints()} });
	}
}

void LevelSave::saveFinal(bool level2) {
	if (level2) {
		writejson("saveLevel2.json", saveJson);
	}
	else {
		writejson("saveLevel1.json", saveJson);
	}
}

void LevelSave::loadLevel(bool level2) {
	if (level2) {
		saveJson = readJson("saveLevel2.json");
	}
	else {
		saveJson = readJson("saveLevel1.json");
	}
}