#pragma once
#include "Level.h"

class Level1 : public Level
{
private:
	void levelCompleteHandler();
public:
	Level1(bool isPlayer2);
	~Level1();
};

