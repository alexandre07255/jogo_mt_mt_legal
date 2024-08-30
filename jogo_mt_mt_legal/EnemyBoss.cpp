#include "EnemyBoss.h"
#include "LevelSave.h"
using namespace Entities::Characters;

EnemyBoss::EnemyBoss(Player* p1, Player* p2):
	Enemy(),
	pPlayer1(p1),
	pPlayer2(p2),
	tiredCont(0),
	stompCont(0),
	stompMax(rand()%3 + 2),
	triggered(0),
	triggerRange(500.f),
	followingPlayer2(0),
	attackPart(0),
	attackTimer(0),
	startup(30),
	endLag(30),
	frameCont(0)
{
	setSize(240.f, 480.f);
	setFillColor(sf::Color::White);
}

EnemyBoss::~EnemyBoss()
{

}

void EnemyBoss::execute()
{
	if (!triggered)
	{
		checkTrigger();
		if (!triggered)
			return;
	}

	switch (attackPart)
	{
	case GROUNDED:
		executeGROUNDED();
		break;
	case ASCENDING:
		executeASCENDING();
		break;
	case DESCENDING:
		executeDESCENDING();
		break;
	}

}

void EnemyBoss::executeGROUNDED()
{

}

void EnemyBoss::executeASCENDING()
{

}

void EnemyBoss::executeDESCENDING()
{

}

void EnemyBoss::attack()
{

}

void EnemyBoss::stopAttack()
{

}

void EnemyBoss::checkTrigger()
{

}

void EnemyBoss::save(LevelSave* save)
{

}

const int EnemyBoss::TIREDNESS_DURATION(300);
const int EnemyBoss::ASCENSION_DURATION(60);
const float EnemyBoss::ASCENDING_VELOCITY(3.f);
const float EnemyBoss::DESCENDING_VELOCITY(2.f);
