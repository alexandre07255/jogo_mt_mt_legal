#include "EnemyMelee.h"
#include <stdlib.h>
#include "CollisionManager.h"
#include "SceneManager.h"
#include <time.h>
#include "Level.h"
#include "AttackHitbox.h"

EnemyMelee::EnemyMelee():Enemy(),walkingBuffer(0),waitBuffer(0),direction(0), attacking(0),
attackStartup(72), attackHitboxDuration(5), attackEndLag(20), attackTriggerRange(10.0f), attackTriggerYRange(10.0f){
    sightSize = 700.;
    setPoints(10);
    hp = 20;
}

void EnemyMelee::movementPATROLLING() {
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
            if (horizontalSpeed < WALK_MAX_HORIZONTAL_SPEED) {
                horizontalSpeed += WALK_ACCELARATION;
            }
            else {
                horizontalSpeed = WALK_MAX_HORIZONTAL_SPEED;
            }
            facingRight = 1;
        }
        else {
            //decidiu andar para a esquerda
            if (horizontalSpeed > -WALK_MAX_HORIZONTAL_SPEED) {
                horizontalSpeed -= WALK_ACCELARATION;
            }
            else {
                horizontalSpeed = -WALK_MAX_HORIZONTAL_SPEED;
            }
            facingRight = 0;
        }
        walkingBuffer--;
    }

    if (abs(horizontalSpeed) > frictionFelt) {
        horizontalSpeed -= ((horizontalSpeed > 0) - (horizontalSpeed < 0)) * frictionFelt;
    }
    else
        horizontalSpeed = 0;

    verticalSpeed += 1;

    if (!onAir && checkOnLedge()) {
        horizontalSpeed = 0;
    }

    vetorDesloc.x *= horizontalSpeed;
    vetorDesloc.y *= verticalSpeed;

    move(vetorDesloc);

    followingPlayer = searchPlayer();

    if (followingPlayer) {
        state = FOLLOWING;
    }
}

void EnemyMelee::movement() {
    CollisionManager* instance = CollisionManager::getInstance();

    switch (state)
    {
    case PATROLLING:
        setFillColor(sf::Color::White);
        movementPATROLLING();
        break;
    case HITSTUN:
        movementHITSTUN();
        break;
    case FOLLOWING:
        setFillColor(sf::Color::Color(sf::Uint32(4286578943)));
        movementFOLLOWING();
        break;
    case ATKCANCEL:
        setFillColor(sf::Color::Green);
        movementATKCANCEL();
        break;
    }

    instance->testCollison(this);
    
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

void EnemyMelee::movementFOLLOWING() {

    sf::Vector2f vetorDesloc(1, 1);

    if (followingPlayer->getPosition().x > getPosition().x + getSize().x) {
        if (horizontalSpeed < FOLLOW_MAX_HORIZONTAL_SPEED) {
            horizontalSpeed += FOLLOW_ACCELARATION;
        }
        else {
            horizontalSpeed = FOLLOW_MAX_HORIZONTAL_SPEED;
        }
        //facingRight = 1;
    }
    else if (followingPlayer->getPosition().x + followingPlayer->getSize().x < getPosition().x){
        if (horizontalSpeed > -FOLLOW_MAX_HORIZONTAL_SPEED) {
            horizontalSpeed -= FOLLOW_ACCELARATION;
        }
        else {
            horizontalSpeed = -FOLLOW_MAX_HORIZONTAL_SPEED;
        }
        //facingRight = 0;
    }
    facingRight = (followingPlayer->getPosition().x + followingPlayer->getSize().x / 2 > getPosition().x + getSize().x / 2);


    if (!attacking && (followingPlayer->getPosition().y + followingPlayer->getSize().y) < (getPosition().y + getSize().y)) {
        if (!onAir)
        {
            verticalSpeed = -JUMP_STRENGTH;
            onAir = 1;
        }
        else {
            onAir = 0;
        }
    }

    if (abs(horizontalSpeed) > frictionFelt) {
        horizontalSpeed -= ((horizontalSpeed > 0) - (horizontalSpeed < 0)) * frictionFelt;
    }
    else
        horizontalSpeed = 0;

    verticalSpeed += 1;

    if (attacking && stun < attackEndLag)
        horizontalSpeed = 0;

    move(horizontalSpeed - (attacking * 0.85f) * horizontalSpeed, verticalSpeed);

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

void EnemyMelee::movementATKCANCEL()
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
    List<Collidable>* collidables = level->getCollidable();

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

    for (ListIterator<Collidable> it = collidables->begin(); (it != collidables->end()); it++) {
        if (ret.intersects((*it)->getBounds()))
            return false;
    }

    return true;

}

const float EnemyMelee::FOLLOW_MAX_HORIZONTAL_SPEED(10.0f);
const float EnemyMelee::FOLLOW_ACCELARATION(2.0f);

const float EnemyMelee::WALK_ACCELARATION(1.5f);
const float EnemyMelee::WALK_MAX_HORIZONTAL_SPEED(6.0f);

const float EnemyMelee::JUMP_STRENGTH(20.0f);