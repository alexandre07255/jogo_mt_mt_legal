#include "EnemyBoss.h"
#include "LevelSave.h"
#include "AttackHitbox.h"
#include "SceneManager.h"
#include "Level2.h"
using namespace Entities::Characters;
using namespace Entities::Hitboxes;
using namespace Managers;
using namespace Scenes;


EnemyBoss::EnemyBoss(Player* p1, Player* p2):
	Enemy(),
	targetPlayer{ p1, p2 },
	hitboxes{ NULL, NULL},
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
	attacking(0)
{
	setSize(240.f, 480.f);
	setFillColor(sf::Color::White);
	hp = 40;
}

EnemyBoss::~EnemyBoss()
{
	hitboxes[0] = NULL;
	hitboxes[1] = NULL;
}

void EnemyBoss::execute()
{
	if (!triggered)
	{
		checkTrigger();
		if (!triggered)
		{
			move(0, GRAVITY);
			return;
		}
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

	if (fireRemaining)
	{
		if (fireCont > 4)
		{
			hp--;
			fireRemaining--;
			fireCont = 0;
		}
		else
			fireCont++;
	}

	if (hp <= 0) {
		SceneManager* sinstance = SceneManager::getInstance();
		Level2* level = static_cast<Level2*>(sinstance->top());

		level->setIsBossAlive(0);
		level->removeEntity(this);
		level->removeEnemy(this);

		delete this;
	}
}

void EnemyBoss::executeGROUNDED()
{
	if (tiredCont)
	{
		tiredCont--;
		horizontalVelocity = 0;
		verticalVelocity = 0;
		return;
	}

	if (attacking)
	{
		if (attackTimer)
		{
			attackTimer--;
		}
		else
		{
			attackPart = ASCENDING;
			attackTimer = ASCENSION_DURATION;
			onAir = 1;
			attacking = 0;
		}
	}
	else
	{
		if (!attackTimer)
		{
			attacking = 1;
			attackTimer = startup;
		}
		else
		{
			attackTimer--;
		}
	}

	if (abs(horizontalVelocity) > frictionFelt) {
		horizontalVelocity -= ((horizontalVelocity > 0) - (horizontalVelocity < 0)) * frictionFelt;
	}
	else
		horizontalVelocity = 0;

	verticalVelocity += 1;

	move(horizontalVelocity, verticalVelocity);
}

void EnemyBoss::executeASCENDING()
{
	if (attackTimer)
	{
		if (xMid() < targetPlayer[followingPlayer2]->xMid())
			horizontalVelocity = HORIZONTAL_VELOCITY;
		else
			horizontalVelocity = -HORIZONTAL_VELOCITY;
		verticalVelocity = -ASCENDING_VELOCITY + GRAVITY;
		attackTimer--;
	}
	else
	{
		attackPart = DESCENDING;
		setPosition(targetPlayer[followingPlayer2]->xMid() - getXSize(), getYPosition());
		horizontalVelocity = 0;
		verticalVelocity = 0;
	}

	move(horizontalVelocity, verticalVelocity);
}

void EnemyBoss::executeDESCENDING()
{
	if (onAir)
	{
		verticalVelocity = DESCENDING_VELOCITY + GRAVITY;
		if (!attacking)
		{
			attack();
			attacking = 1;
		}
	}
	else
	{
		stopAttack();
		attacking = 0;
		attackPart = GROUNDED;
		stompCont++;
		if (stompCont >= stompMax)
		{
			stompMax = rand() % 3 + 2;
			tiredCont = TIREDNESS_DURATION;
			stompCont = 0;
		}
		if (targetPlayer[!followingPlayer2])
		{
			followingPlayer2 = !followingPlayer2;
		}
	}
	move(horizontalVelocity, verticalVelocity);
}

void EnemyBoss::attack()
{
	for (int i = 0; i < 2; i++)
	{
		hitboxes[i] = new AttackHitbox();

		hitboxes[i]->setTarget(1);
		hitboxes[i]->setOwner(this);
		hitboxes[i]->setBoundedTo(this);
		hitboxes[i]->setSize(sf::Vector2f(getXSize() / 2, getYSize() / 10));
		hitboxes[i]->setVerKnockback(-10.0f);
		hitboxes[i]->setDamage(5);
		hitboxes[i]->setHitstun(15);
		hitboxes[i]->setIsPersistent(1);
		float horKnock = .0f;
		float horRel = .0f;
		if (!i)
		{
			horKnock = -40.f;
			horRel = 0.f;
		}
		else
		{
			horKnock = 40.f;
			horRel = getXSize() / 2;
		}
		hitboxes[i]->setRelativePosition(sf::Vector2f(horRel, getYSize() * 9 / 10));
		hitboxes[i]->setHorKnockback(horKnock);
	}
}

void EnemyBoss::stopAttack()
{
	for (int i = 0; i < 2; i++)
	{
		if (hitboxes[i])
		{
			delete hitboxes[i];
			hitboxes[i] = NULL;
		}
	}
}

void EnemyBoss::checkTrigger()
{
	for (int i = 0; i < 2; i++)
	{
		if (targetPlayer[i] && abs(targetPlayer[i]->xMid() - xMid()) < triggerRange)
		{
			triggered = 1;
			return;
		}
	}
}

void EnemyBoss::save(LevelSave* save)
{

}

const int EnemyBoss::TIREDNESS_DURATION(300);
const int EnemyBoss::ASCENSION_DURATION(30);
const float EnemyBoss::HORIZONTAL_VELOCITY(0.f);
const float EnemyBoss::ASCENDING_VELOCITY(48.f);
const float EnemyBoss::DESCENDING_VELOCITY(46.f);
