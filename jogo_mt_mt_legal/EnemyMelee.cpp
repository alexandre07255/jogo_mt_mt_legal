#include "EnemyMelee.h"
#include <stdlib.h>
#include "CollisionManager.h"
#include "SceneManager.h"
#include <time.h>
#include "Level.h"
#include "AttackHitbox.h"
using namespace Managers;
using namespace Entities::Characters;
using namespace Scenes;
using namespace Entities::Hitboxes;

EnemyMelee::EnemyMelee():Enemy(),walkingBuffer(0),waitBuffer(0),direction(0), attacking(0),
attackStartup(72), attackHitboxDuration(5), attackEndLag(20), attackTriggerRange(10.0f), attackTriggerYRange(10.0f){
    sightSize = 700.;
    setPoints(10);
    hp = 20;
}

void EnemyMelee::executePATROLLING() {
    srand(time(NULL));

    sf::Vector2f vetorDesloc(1, 1);

    if (walkingBuffer <= 0) {

        if (waitBuffer <= 0) {
            if (rand()%2) {
                //50% de chance de andar uma certa quantia, determindada pelo walking buffer
                walkingBuffer = 10 + rand() % 10;
                direction = rand() % 2;
            }
            else {
                waitBuffer = 50;
            }
        }
        else {
            waitBuffer--;
        }
    }
    else {
        if (direction) {
            //decidiu andar para direita
            if (horizontalVelocity < WALK_MAX_HORIZONTAL_VELOCITY) {
                horizontalVelocity += WALK_ACCELARATION;
            }
            else {
                horizontalVelocity = WALK_MAX_HORIZONTAL_VELOCITY;
            }
            facingRight = 1;
        }
        else {
            //decidiu andar para a esquerda
            if (horizontalVelocity > -WALK_MAX_HORIZONTAL_VELOCITY) {
                horizontalVelocity -= WALK_ACCELARATION;
            }
            else {
                horizontalVelocity = -WALK_MAX_HORIZONTAL_VELOCITY;
            }
            facingRight = 0;
        }
        walkingBuffer--;
    }

    if (abs(horizontalVelocity) > frictionFelt) {
        horizontalVelocity -= ((horizontalVelocity > 0) - (horizontalVelocity < 0)) * frictionFelt;
    }
    else
        horizontalVelocity = 0;

    verticalVelocity += 1;

    if (!onAir && checkOnLedge()) {
        horizontalVelocity = 0;
    }

    vetorDesloc.x *= horizontalVelocity;
    vetorDesloc.y *= verticalVelocity;

    move(vetorDesloc);

    followingPlayer = searchPlayer();

    if (followingPlayer) {
        state = FOLLOWING;
    }
}

void EnemyMelee::execute() {
    CollisionManager* instance = CollisionManager::getInstance();

    switch (state)
    {
    case PATROLLING:
        setFillColor(sf::Color::White);
        executePATROLLING();
        break;
    case HITSTUN:
        executeHITSTUN();
        break;
    case FOLLOWING:
        setFillColor(sf::Color::Color(sf::Uint32(4286578943)));
        executeFOLLOWING();
        break;
    case ATKCANCEL:
        setFillColor(sf::Color::Green);
        executeATKCANCEL();
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
        Level* level = static_cast<Level*>(sinstance->top());

        level->removeDrawable(this);
        level->removeHittable(this);
        level->removeUpdatable(this);

        delete this;
    }
}

void EnemyMelee::executeFOLLOWING() {

    sf::Vector2f vetorDesloc(1, 1);

    if (followingPlayer->getPosition().x > getPosition().x + getSize().x) {
        if (horizontalVelocity < FOLLOW_MAX_HORIZONTAL_VELOCITY) {
            horizontalVelocity += FOLLOW_ACCELARATION;
        }
        else {
            horizontalVelocity = FOLLOW_MAX_HORIZONTAL_VELOCITY;
        }
        //facingRight = 1;
    }
    else if (followingPlayer->getPosition().x + followingPlayer->getSize().x < getPosition().x){
        if (horizontalVelocity > -FOLLOW_MAX_HORIZONTAL_VELOCITY) {
            horizontalVelocity -= FOLLOW_ACCELARATION;
        }
        else {
            horizontalVelocity = -FOLLOW_MAX_HORIZONTAL_VELOCITY;
        }
        //facingRight = 0;
    }
    facingRight = (followingPlayer->getPosition().x + followingPlayer->getSize().x / 2 > getPosition().x + getSize().x / 2);


    if (!attacking && (followingPlayer->getPosition().y + followingPlayer->getSize().y) < (getPosition().y + getSize().y)) {
        if (!onAir)
        {
            verticalVelocity = -JUMP_STRENGTH;
            onAir = 1;
        }
        else {
            onAir = 0;
        }
    }

    if (abs(horizontalVelocity) > frictionFelt) {
        horizontalVelocity -= ((horizontalVelocity > 0) - (horizontalVelocity < 0)) * frictionFelt;
    }
    else
        horizontalVelocity = 0;

    verticalVelocity += 1;

    if (attacking && stun < attackEndLag)
        horizontalVelocity = 0;

    move(horizontalVelocity - (attacking * 0.85f) * horizontalVelocity, verticalVelocity);

    if (attacking && stun <= 0)
        attacking = 0;

    if (!attacking)
    {
        followingPlayer = searchPlayer();
        if (!followingPlayer) {
            if (facingRight) {
                facingRight = 0;
            }
            else
                facingRight = 1;
            state = PATROLLING;
        }
        else if (abs((followingPlayer->getPosition().y + followingPlayer->getSize().y) - (getPosition().y + getSize().y)) < attackTriggerYRange)
        {
            if (facingRight)
            {
                if (followingPlayer->getPosition().x - (getPosition().x + getSize().x) < attackTriggerRange)
                {
                    attacking = 1;
                    stun = attackStartup + attackHitboxDuration + attackEndLag;
                }
            }
            else
            {
                if (followingPlayer->getPosition().x + followingPlayer->getSize().x - getPosition().x > -attackTriggerRange)
                {
                    attacking = 1;
                    stun = attackStartup + attackHitboxDuration + attackEndLag;
                }
            }
        }
            
    }
    else
    {
        setFillColor(sf::Color::Blue);

        if ((stun == (attackHitboxDuration + attackEndLag)))
        {
            AttackHitbox* hitbox = new AttackHitbox();

            hitbox->setTarget(1);
            hitbox->setOwner(this);
            hitbox->setBoundedTo(this);
            hitbox->setDuration(attackHitboxDuration);
            float horKnock = 0.0;
            hitbox->setSize(sf::Vector2f(110.0, 100.0));
            hitbox->setVerKnockback(-10.0);
            hitbox->setDamage(3);
            hitbox->setHitstun(25);
            horKnock = 30.0;
            if (facingRight)
            {
                hitbox->setRelativePosition(sf::Vector2f(getSize().x - 10, 0.0));
                hitbox->setHorKnockback(horKnock);
            }
            else
            {
                float relX = hitbox->getSize().x;
                hitbox->setRelativePosition(sf::Vector2f(-relX + 10, 0.0));
                hitbox->setHorKnockback(-horKnock);
            }
        }
        stun--;
    }
}

void EnemyMelee::executeATKCANCEL()
{
    if (stun > 0)
    {
        stun--;
    }
    else
    {
        followingPlayer = searchPlayer();
        if (!followingPlayer) {
            if (facingRight) {
                facingRight = 0;
            }
            else
                facingRight = 1;
            state = PATROLLING;
        }
        else
        {
            state = FOLLOWING;
        }
    }
}

const bool EnemyMelee::checkOnLedge() const{
    CollisionManager* instance = CollisionManager::getInstance();

    SceneManager* LevelInstance = SceneManager::getInstance();
    Level* level = static_cast<Level*>(LevelInstance->top());
    list<Collidable*>* collidables = level->getCollidable();

    sf::FloatRect ret;

    ret.width = 1;
    ret.height = 1;

    ret.top = getPosition().y + getSize().y + 1;

    if (facingRight){
        ret.left = getPosition().x + getSize().x;
    }
    else {
        ret.left = getPosition().x;
    }

    for (list<Collidable*>::iterator it = collidables->begin(); (it != collidables->end()); it++) {
        if (ret.intersects((*it)->getBounds()))
            return false;
    }

    return true;

}

const float EnemyMelee::FOLLOW_MAX_HORIZONTAL_VELOCITY(10.0f);
const float EnemyMelee::FOLLOW_ACCELARATION(2.0f);

const float EnemyMelee::WALK_ACCELARATION(1.5f);
const float EnemyMelee::WALK_MAX_HORIZONTAL_VELOCITY(6.0f);

const float EnemyMelee::JUMP_STRENGTH(20.0f);

void EnemyMelee::save(LevelSave* save) {
    save->addMeleeEnemy(this);
}