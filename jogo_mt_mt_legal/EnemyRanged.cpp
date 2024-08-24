#include "EnemyRanged.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "Level.h"

EnemyRanged::EnemyRanged(): walkingBuffer(0), waitBuffer(0), direction(0),
	attackStartup(60),
	attackEndLag(40),
	heightStrip(10.f),
	attackTriggerRange(150.f),
	attackTriggerYRange(10.f),
    idealHeight(200.f)
{
	upperLimitMultR = 7.0 / 4;
	lesserLimitMultR = 5.0 / 2;
	upperLimitMultL = 5.0 / 4;
	lesserLimitMultL = 1.0 / 2;
}

void EnemyRanged::movement()
{
    CollisionManager* instance = CollisionManager::getInstance();

    state = PATROLLING;
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
    CollisionManager* instance = CollisionManager::getInstance();

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

    float floorY = instance->nearestCollidable(this, MAX_HEIGHT);
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

    //followingPlayer = searchPlayer();

    if (followingPlayer) {
        state = FOLLOWING;
    }
}

void EnemyRanged::movementFOLLOWING()
{

}

void EnemyRanged::movementATKCANCEL()
{
    state = PATROLLING;
}

const float EnemyRanged::MAX_HEIGHT(350.f);
const float EnemyRanged::FLY_STRENGTH(0.5f);
const float EnemyRanged::FOLLOW_MAX_HORIZONTAL_SPEED(5.f);
const float EnemyRanged::FOLLOW_ACCELARATION(2.0f);
const float EnemyRanged::WALK_ACCELARATION(1.5f);
const float EnemyRanged::WALK_MAX_HORIZONTAL_SPEED(3.f);