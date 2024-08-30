#include "EnemyRanged.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "LevelSave.h"
#include "Level.h"
using namespace Entities::Characters;
using namespace Managers;
using namespace Scenes;


EnemyRanged::EnemyRanged() : walkingBuffer(0), waitBuffer(0), direction(0),
attackStartup(30),
attackEndLag(40),
heightStrip(10.f),
attackTriggerRange(250.f),
attackTriggerYRange(10.f),
idealHeight(200.f),
cycleLenght(6),
contCycle(0),
cooldownCont(0),
attackTriggerStrip(20.0f),
nearestCollidableCont(NEAREST_COLLIDABLE_COOLDOWN)
{
    hp = 20;
    sightSize = 1000.0;
	upperLimitMultR = 5.0 / 2;
	lesserLimitMultR = 7.0 / 4;
	upperLimitMultL = 5.0 / 4;
	lesserLimitMultL = 1.0 / 2;
}

void EnemyRanged::execute()
{
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
    case ATTACK:
        executeATTACK();
        break;
    }
    if (cooldownCont > 0) { cooldownCont--; }


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

        level->removeEntity(this);
        level->removeEnemy(this);

        //level->removeHittable(this);      

        delete this;
    }
}

void EnemyRanged::executePATROLLING()
{
    CollisionManager* cInstance = CollisionManager::getInstance();

    srand(time(NULL));

    int friccao = 1;
    sf::Vector2f vetorDesloc(1, 1);

    if (walkingBuffer <= 0) {

        if (waitBuffer <= 0) {
            if (rand() % 2) {
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

    if (abs(horizontalVelocity) > friccao) {
        horizontalVelocity -= ((horizontalVelocity > 0) - (horizontalVelocity < 0)) * friccao;
    }
    else
        horizontalVelocity = 0;

    //verticalVelocity += 1;

    if (nearestCollidableCont > 0)
    {
        nearestCollidableCont--;
    }
    else
    {
        nearestCollidableCont = NEAREST_COLLIDABLE_COOLDOWN;
        float floorY = cInstance->nearestCollidable(this, MAX_HEIGHT);
        if (floorY >= bottom() + MAX_HEIGHT)
            verticalVelocity += FLY_STRENGTH * 2 + GRAVITY - GRAVITY;
        else if (floorY - bottom() > idealHeight + heightStrip)
            verticalVelocity += FLY_STRENGTH + GRAVITY - GRAVITY;
        else if (floorY - bottom() < idealHeight - heightStrip)
            verticalVelocity -= FLY_STRENGTH + GRAVITY - GRAVITY;
        //else
            //verticalVelocity = 0;
    }
    //cout << floorY << endl;


    vetorDesloc.x *= horizontalVelocity;
    vetorDesloc.y *= verticalVelocity;

    move(vetorDesloc);

    if (!isInSearchPlayerCooldown())
        followingPlayer = searchPlayer();

    if (followingPlayer) {
        state = FOLLOWING;
    }
}

void EnemyRanged::projectileCalculations(Projectile* proj, const float absHorVelocity, Hittable* target)
{
    float height = target->yMid() - yMid();
    float length = target->xMid() - (left() + getXSize() * facingRight);
    
    float verVelocity = (height / abs(length)) * absHorVelocity - (GRAVITY / 2) * (abs(length) / absHorVelocity);

    proj->setHorizontalVelocity(absHorVelocity * ((length > 0) - (length < 0)));
    proj->setVerticalVelocity(verVelocity);
}

void EnemyRanged::executeFOLLOWING()
{
    CollisionManager* cInstance = CollisionManager::getInstance();

    int friccao = 1;

    sf::Vector2f vetorDesloc(1, 1);

    if ((!cooldownCont) || (abs(xMid() - followingPlayer->xMid()) > attackTriggerRange + attackTriggerStrip))
    {
        if (followingPlayer->left() > right()) {
            if (horizontalVelocity < FOLLOW_MAX_HORIZONTAL_VELOCITY) {
                horizontalVelocity += FOLLOW_ACCELARATION;
            }
            else {
                horizontalVelocity = FOLLOW_MAX_HORIZONTAL_VELOCITY;
            }
            //facingRight = 1;
        }
        else if (followingPlayer->right() < left()) {
            if (horizontalVelocity > -FOLLOW_MAX_HORIZONTAL_VELOCITY) {
                horizontalVelocity -= FOLLOW_ACCELARATION;
            }
            else {
                horizontalVelocity = -FOLLOW_MAX_HORIZONTAL_VELOCITY;
            }
            //facingRight = 0;
        }
    }
    else if (abs(xMid() - followingPlayer->xMid()) < attackTriggerRange - attackTriggerStrip)
    {
        if (followingPlayer->left() < right()) {
            if (horizontalVelocity < FOLLOW_MAX_HORIZONTAL_VELOCITY) {
                horizontalVelocity += FOLLOW_ACCELARATION;
            }
            else {
                horizontalVelocity = FOLLOW_MAX_HORIZONTAL_VELOCITY;
            }
            //facingRight = 1;
        }
        else if (followingPlayer->right() > left()) {
            if (horizontalVelocity > -FOLLOW_MAX_HORIZONTAL_VELOCITY) {
                horizontalVelocity -= FOLLOW_ACCELARATION;
            }
            else {
                horizontalVelocity = -FOLLOW_MAX_HORIZONTAL_VELOCITY;
            }
            //facingRight = 0;
        }
    }
    else
        horizontalVelocity = 0;

    facingRight = (followingPlayer->xMid() > xMid());


    if (nearestCollidableCont > 0)
    {
        nearestCollidableCont--;
    }
    else
    {
        nearestCollidableCont = NEAREST_COLLIDABLE_COOLDOWN;
        float floorY = cInstance->nearestCollidable(this, MAX_HEIGHT);
        if (floorY - bottom() > idealHeight + heightStrip)
            verticalVelocity += FLY_STRENGTH;
        else if (floorY - bottom() < idealHeight - heightStrip)
            verticalVelocity -= FLY_STRENGTH;
        //else
            //verticalVelocity = 0;
    }

    if (abs(horizontalVelocity) > friccao) {
        horizontalVelocity -= ((horizontalVelocity > 0) - (horizontalVelocity < 0)) * friccao;
    }
    else
        horizontalVelocity = 0;


    move(horizontalVelocity, verticalVelocity);

    if (!isInSearchPlayerCooldown())
        followingPlayer = searchPlayer();

    if (!followingPlayer) {
        if (facingRight) {
            facingRight = 0;
        }
        else
            facingRight = 1;
        state = PATROLLING;
    }
    else if (!cooldownCont)
    {
        if (facingRight)
        {
            if (followingPlayer->left() - right() < attackTriggerRange)
            {
                state = ATTACK;
                stun = attackStartup+ attackEndLag;
            }
        }
        else
        {
            if (followingPlayer->right() - left() > -attackTriggerRange)
            {
                state = ATTACK;
                stun = attackStartup + attackEndLag;
            }
        }
    }
}

void EnemyRanged::executeATTACK()
{
    if (stun > 0)
    {
        setFillColor(sf::Color::Blue);
        facingRight = (followingPlayer->xMid() > xMid());

        if (stun == attackEndLag)
        {
            Projectile* projectile = new Projectile;

            projectileCalculations(projectile, 15.f, followingPlayer);

            projectile->setTarget(1);
            projectile->setOwner(this);
            float horKnock = 0.0;
            projectile->setSize(sf::Vector2f(30.0f, 30.0f));
            projectile->setVerKnockback(-10.0);
            projectile->setDamage(3);
            projectile->setHitstun(25);
            horKnock = 30.0;
            if (facingRight)
            {
                projectile->setPosition(right(), yMid());
                projectile->setHorKnockback(horKnock);
            }
            else
            {
                projectile->setPosition(left(), yMid());
                projectile->setHorKnockback(-horKnock);
            }
        }
        stun--;
    }
    else
    {
        cooldownCont = COOLDOWN;

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

void EnemyRanged::executeATKCANCEL()
{
    state = PATROLLING;
}

const int EnemyRanged::NEAREST_COLLIDABLE_COOLDOWN(3);
const int EnemyRanged::COOLDOWN(120);
const float EnemyRanged::MAX_HEIGHT(350.f);
const float EnemyRanged::FLY_STRENGTH(0.5f);
const float EnemyRanged::FOLLOW_MAX_HORIZONTAL_VELOCITY(5.f);
const float EnemyRanged::FOLLOW_ACCELARATION(2.0f);
const float EnemyRanged::WALK_ACCELARATION(1.5f);
const float EnemyRanged::WALK_MAX_HORIZONTAL_VELOCITY(3.f);

void EnemyRanged::save(LevelSave* save) {
    save->addRangedEnemy(this);
}
