#include "LevelSave.h"
#include "Level1.h"
#include "Level2.h"
#include "SceneManager.h"

LevelSave::LevelSave(Scenes::Level* bound) {
	boundLevel = bound;
	//saveJson["isPlayer2"].push_back(false);
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
		//saveJson["isPlayer2"].push_back(true);
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
	bool isPlayer2 = false;
	
	if (level2) {
		saveJson = readJson("saveLevel2.json");
	}
	else {
		saveJson = readJson("saveLevel1.json");
	}
	//if (saveJson["isPlayer2"]) {
	//	isPlayer2 = true;
	//}

	if (level2) {
		Scenes::Level2* level = new Scenes::Level2(isPlayer2, true);

		for (auto it = saveJson["EnemyMeleeList"].begin(); it != saveJson["EnemyMeleeList"].end();it++) {
			level->createEnemyMelee((*it)["x"], (*it)["y"], (*it)["points"]);
		}
		for (auto it = saveJson["EnemyRangedList"].begin(); it != saveJson["EnemyRangedList"].end();it++) {
			level->createEnemyRanged((*it)["x"], (*it)["y"], (*it)["points"]);
		}
		for (auto it = saveJson["PlatformList"].begin(); it != saveJson["PlatformList"].end();it++) {
			level->createPlatform((*it)["x"], (*it)["y"], (*it)["width"], (*it)["height"]);
		}
		for (auto it = saveJson["FireList"].begin(); it != saveJson["FireList"].end();it++) {
			level->createFire((*it)["x"], (*it)["y"], (*it)["width"], (*it)["height"]);
		}

		level->createPlayer1(saveJson["player1"][0]["x"], saveJson["player1"][0]["y"], saveJson["player1"][0]["points"]);

		if (isPlayer2) {
			level->createPlayer2(saveJson["player2"][0]["x"], saveJson["player2"][0]["y"], saveJson["player2"][0]["points"]);
		}

		Managers::SceneManager* sInstance = Managers::SceneManager::getInstance();
		sInstance->push(level);
		level->setEverything();
	}
	else {
		Scenes::Level1* level = new Scenes::Level1(isPlayer2, true);

		for (auto it = saveJson["EnemyMeleeList"].begin(); it != saveJson["EnemyMeleeList"].end();it++) {
			level->createEnemyMelee((*it)["x"], (*it)["y"], (*it)["points"]);
		}
		for (auto it = saveJson["EnemyRangedList"].begin(); it != saveJson["EnemyRangedList"].end();it++) {
			level->createEnemyRanged((*it)["x"], (*it)["y"], (*it)["points"]);
		}
		for (auto it = saveJson["SpikeList"].begin(); it != saveJson["SpikeList"].end();it++) {
			level->createSpike((*it)["x"], (*it)["y"], (*it)["width"], (*it)["height"]);
		}
		for (auto it = saveJson["PlatformList"].begin(); it != saveJson["PlatformList"].end();it++) {
			level->createPlatform((*it)["x"], (*it)["y"], (*it)["width"], (*it)["height"]);
		}

		level->createPlayer1(saveJson["player1"][0]["x"], saveJson["player1"][0]["y"], saveJson["player1"][0]["points"]);

		if (isPlayer2) {
			level->createPlayer2(saveJson["player2"][0]["x"], saveJson["player2"][0]["y"], saveJson["player2"][0]["points"]);
		}

		Managers::SceneManager* sInstance = Managers::SceneManager::getInstance();
		sInstance->push(level);
		level->setEverything();
	}

}