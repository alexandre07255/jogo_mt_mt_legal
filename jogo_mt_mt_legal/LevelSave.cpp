#include "LevelSave.h"

LevelSave::LevelSave(Scenes::Level* bound) {
	boundLevel = bound;
}
LevelSave::~LevelSave() {
}

void LevelSave::addRangedEnemy(Entities::Characters::EnemyRanged* enemy) {
	saveJson["EnemyRangedList"].push_back({ {"x",enemy->getPosition().x},{"y",enemy->getPosition().y},{"hp",enemy->getHp()},{"points",enemy->getPoints()} });
}

void LevelSave::addMeleeEnemy(Entities::Characters::EnemyMelee* enemy) {
	saveJson["EnemyMeleeList"].push_back({ {"x",enemy->getPosition().x},{"y",enemy->getPosition().y},{"hp",enemy->getHp()},{"points",enemy->getPoints()} });
}

void LevelSave::addSpike(Entities::Obstacles::Spike* obst) {
	saveJson["SpikeList"].push_back({ {"x",obst->getPosition().x},{"y",obst->getPosition().y},{"height",obst->getSize().y},{"width",obst->getSize().x}});
}

void LevelSave::addPlatform(Entities::Obstacles::Platform* obst) {
	saveJson["PlatformList"].push_back({ {"x",obst->getPosition().x},{"y",obst->getPosition().y},{"height",obst->getSize().y},{"width",obst->getSize().x} });
}

void LevelSave::addFire(Entities::Obstacles::Fire* obst) {
	saveJson["FireList"].push_back({ {"x",obst->getPosition().x},{"y",obst->getPosition().y},{"height",obst->getSize().y},{"width",obst->getSize().x} });
}

void LevelSave::addPlayer(Entities::Characters::Player* player, bool player2) {
	if (player2) {
		saveJson["player2"].push_back({ {"x",player->getPosition().x},{"y",player->getPosition().y},{"hp",player->getHp()},{"points",player->getPoints()} });
	}
	else {
		saveJson["player1"].push_back({ {"x",player->getPosition().x},{"y",player->getPosition().y},{"hp",player->getHp()},{"points",player->getPoints()} });
	}
}

void LevelSave::saveFinal() {
	writejson("saveLevel1.json", saveJson);
}
