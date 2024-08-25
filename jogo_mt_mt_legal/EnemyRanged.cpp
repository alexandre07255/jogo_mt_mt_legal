#include "EnemyRanged.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "Level.h"

EnemyRanged::EnemyRanged() : walkingBuffer(0), waitBuffer(0), direction(0),
attackStartup(30),
attackEndLag(40),
heightStrip(10.f),
attackTriggerRange(150.f),
attackTriggerYRange(10.f),
idealHeight(200.f),
cycleLenght(6),
contCycle(0),
cooldownCont(0),
attackTriggerStrip(20.0f)
{
    sightSize = 1000.f;
	upperLimitMultR = 5.0 / 2;
	lesserLimitMultR = 7.0 / 4;
	upperLimitMultL = 5.0 / 4;
	lesserLimitMultL = 1.0 / 2;
}

void EnemyRanged::movement()
{
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
    case ATTACK:
        movementATTACK();
        break;
    }
    if (cooldownCont > 0) { cooldownCont--; }

    instance->testCollison(this);

    if (hp <= 0) {
        SceneManager* sinstance = SceneManager::getInstance();
        Level* level = static_cast<Level*>(sinstance->top());

        level->removeDrawable(this);
        level->removeHittable(this);
        level->removeUpdatable(this);

        delete this;
    }
}

void EnemyRanged::movementPATROLLING()
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

    if (abs(horizontalSpeed) > friccao) {
        horizontalSpeed -= ((horizontalSpeed > 0) - (horizontalSpeed < 0)) * friccao;
    }
    else
        horizontalSpeed = 0;

    //verticalSpeed += 1;

    float floorY = cInstance->nearestCollidable(this, MAX_HEIGHT);
    if (floorY - bottom() > idealHeight + heightStrip)
        verticalSpeed += FLY_STRENGTH;
    else if (floorY - bottom() < idealHeight - heightStrip)
        verticalSpeed -= FLY_STRENGTH;
    else
        verticalSpeed = 0;
    //cout << floorY << endl;


    vetorDesloc.x *= horizontalSpeed;
    vetorDesloc.y *= verticalSpeed;

    move(vetorDesloc);

    followingPlayer = searchPlayer();

    if (followingPlayer) {
        state = FOLLOWING;
    }
}

void EnemyRanged::projectileCalculations(Projectile* proj, const float absHorSpeed, Hittable* target)
{
    float height = target->yMid() - yMid();
    float length = target->xMid() - xMid();
    
    float verSpeed = (height / abs(length)) * absHorSpeed - (GRAVITY / 2) * (abs(length) / absHorSpeed);

    proj->setHorizontalVelocity(absHorSpeed * ((length > 0) - (length < 0)));
    proj->setVerticalVelocity(verSpeed);
}

void EnemyRanged::movementFOLLOWING()
{
    CollisionManager* cInstance = CollisionManager::getInstance();

    int friccao = 1;

    sf::Vector2f vetorDesloc(1, 1);

    if ((!cooldownCont) || (abs(xMid() - followingPlayer->xMid()) > attackTriggerRange + attackTriggerStrip))
    {
        if (followingPlayer->left() > right()) {
            if (horizontalSpeed < FOLLOW_MAX_HORIZONTAL_SPEED) {
                horizontalSpeed += FOLLOW_ACCELARATION;
            }
            else {
                horizontalSpeed = FOLLOW_MAX_HORIZONTAL_SPEED;
            }
            //facingRight = 1;
        }
        else if (followingPlayer->right() < left()) {
            if (horizontalSpeed > -FOLLOW_MAX_HORIZONTAL_SPEED) {
                horizontalSpeed -= FOLLOW_ACCELARATION;
            }
            else {
                horizontalSpeed = -FOLLOW_MAX_HORIZONTAL_SPEED;
            }
            //facingRight = 0;
        }
    }
    else if (abs(xMid() - followingPlayer->xMid()) < attackTriggerRange - attackTriggerStrip)
    {
        if (followingPlayer->left() < right()) {
            if (horizontalSpeed < FOLLOW_MAX_HORIZONTAL_SPEED) {
                horizontalSpeed += FOLLOW_ACCELARATION;
            }
            else {
                horizontalSpeed = FOLLOW_MAX_HORIZONTAL_SPEED;
            }
            //facingRight = 1;
        }
        else if (followingPlayer->right() > left()) {
            if (horizontalSpeed > -FOLLOW_MAX_HORIZONTAL_SPEED) {
                horizontalSpeed -= FOLLOW_ACCELARATION;
            }
            else {
                horizontalSpeed = -FOLLOW_MAX_HORIZONTAL_SPEED;
            }
            //facingRight = 0;
        }
    }
    else
        horizontalSpeed = 0;

    facingRight = (followingPlayer->xMid() > xMid());

    float floorY = cInstance->nearestCollidable(this, MAX_HEIGHT);
    if (floorY - bottom() > idealHeight + heightStrip)
        verticalSpeed += FLY_STRENGTH;
    else if (floorY - bottom() < idealHeight - heightStrip)
        verticalSpeed -= FLY_STRENGTH;
    else
        verticalSpeed = 0;

    if (abs(horizontalSpeed) > friccao) {
        horizontalSpeed -= ((horizontalSpeed > 0) - (horizontalSpeed < 0)) * friccao;
    }
    else
        horizontalSpeed = 0;


    move(horizontalSpeed, verticalSpeed);

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

void EnemyRanged::movementATTACK()
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
                projectile->setPosition(xMid(), yMid());
                projectile->setHorKnockback(horKnock);
            }
            else
            {
                projectile->setPosition(xMid(), yMid());
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

void EnemyRanged::movementATKCANCEL()
{
    state = PATROLLING;
}

const int EnemyRanged::COOLDOWN(120);
const float EnemyRanged::MAX_HEIGHT(350.f);
const float EnemyRanged::FLY_STRENGTH(0.5f);
const float EnemyRanged::FOLLOW_MAX_HORIZONTAL_SPEED(5.f);
const float EnemyRanged::FOLLOW_ACCELARATION(2.0f);
const float EnemyRanged::WALK_ACCELARATION(1.5f);
const float EnemyRanged::WALK_MAX_HORIZONTAL_SPEED(3.f);