#pragma once
#include "Save.h"
#include "Level.h"
#include "GraphicManager.h"

class ScoreSave : public Save
{
private:
	static Managers::GraphicManager* pGraphic;
	std::string* name;
	bool keyPressed;
public:
	ScoreSave();
	void savePlayer(int score);
	void addScore(std::string name, int score);
	void appendLetter();
	std::string* getName();
	void setName(std::string* nm);
};

