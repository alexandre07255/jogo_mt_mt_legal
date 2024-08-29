#pragma once
#include "Save.h"
#include "Level.h"
#include "GraphicManager.h"

class ScoreSave : public Save
{
private:
	static Managers::GraphicManager* pGraphic;
public:
	ScoreSave();
	void savePlayer(int score);
	void addScore(std::string name, int score);
	std::string listen();
};

