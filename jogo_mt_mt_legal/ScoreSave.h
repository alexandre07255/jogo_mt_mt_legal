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
	~ScoreSave();
	void savePlayer(int score);
	void addScore(std::string name, int score);
	const bool appendLetter();
	std::string* getName();
	void setName(std::string* nm);
};

