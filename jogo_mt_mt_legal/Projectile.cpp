#include "Projectile.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "LevelSave.h"
#include <iostream>
using namespace std;
using namespace sf;
using namespace Entities;
using namespace Managers;
using namespace Scenes;
using namespace Entities::Hitboxes;
using namespace Entities::Characters;


Projectile::Projectile():
	hitbox(NULL),
    firstStep(1),
    hitstun(0),
    hasHit(0)
{
    Scene* activeScene = SceneManager::getInstance()->top();

    hitbox = new AttackHitbox;

    hitbox->setBoundedTo(this);
    hitbox->setIsInfinite(1);
    hitbox->setDoesATKCANCEL(0);

    setFillColor(Color::Blue);
   
    activeScene->addEntity(this);
}

void Projectile::setOwner(Hittable* own)
{
     hitbox->setOwner(own);
}

void Projectile::setHorKnockback(const float horKnock)
{
    hitbox->setHorKnockback(horKnock);
}

void Projectile::setVerKnockback(const float verKnock)
{
    hitbox->setVerKnockback(verKnock);
}

void Projectile::setDamage(const int dmg)
{
    hitbox->setDamage(dmg);
}

void Projectile::setHitstun(const int stun)
{
    hitbox->setHitstun(stun);
    hitstun = stun + 1;
}

void Projectile::setTarget(const bool tar)
{
    hitbox->setTarget(tar);
}

void Projectile::setRelativePosition(sf::Vector2f rel)
{
    hitbox->setRelativePosition(rel);
}

void Projectile::execute()
{
    CollisionManager* cInstance = CollisionManager::getInstance();

    bool gone = 0;

	if (firstStep)
	{
        hitbox->setSize(getXSize(), getYSize());
        firstStep = 0;
	}

    if (hasHit || hitbox->getHasHit())
    {
        hasHit = 1;
        if (hitstun > 0)
            hitstun--;
        else
            gone = 1;
    }
    else
    {
        verticalVelocity += GRAVITY;

        move(horizontalVelocity, verticalVelocity);

        Vector2f preColli(getXPosition(), getYPosition());

        cInstance->testCollison(this);

        Vector2f posColli(getXPosition(), getYPosition());

        if (preColli != posColli)
            gone = 1;
    }

    if (gone)
    {
        hitbox->setDuration(0);
        Scene* activeScene = SceneManager::getInstance()->top();
        activeScene->removeEntity(this);
        delete this;
        return;
    }
}

void Projectile::save(LevelSave* save){}
