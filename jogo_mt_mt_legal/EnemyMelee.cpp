#include "EnemyMelee.h"
#include <stdlib.h>
#include "CollisionManager.h"
#include "SceneManager.h"
#include <time.h>
#include "Level.h"

EnemyMelee::EnemyMelee():Enemy(),walkingBuffer(0),waitBuffer(0),direction(0){}

void EnemyMelee::movementPATROLLING() {
    srand(time(NULL));

    int friccao = 1;
    sf::Vector2f vetorDesloc(1, 1);

    if (walkingBuffer <= 0) {

        if (waitBuffer <= 0) {
            if (rand()%2) {
                //50% de chance de andar uma certa quantia, determindada pelo walking buffer
                walkingBuffer = rand() % 10;
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
            if (horizontalSpeed < MAX_HORIZONTAL_SPEED) {
                horizontalSpeed += ACCELARATION;
            }
            else {
                horizontalSpeed = MAX_HORIZONTAL_SPEED;
            }
            facingRight = 1;
        }
        else {
            //decidiu andar para a esquerda
            if (horizontalSpeed > -MAX_HORIZONTAL_SPEED) {
                horizontalSpeed -= ACCELARATION;
            }
            else {
                horizontalSpeed = -MAX_HORIZONTAL_SPEED;
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
        movementPATROLLING();
        break;
    case HITSTUN:
        movementHITSTUN();
        break;
    case FOLLOWING:
        movementFOLLOWING();
        break;
    }

    instance->testCollison(this);
    //std::cout << state << endl;
}

void EnemyMelee::movementFOLLOWING() {
    int friccao = 1;

    sf::Vector2f vetorDesloc(1, 1);

    if (followingPlayer->getPosition().x + followingPlayer->getSize().x > getPosition().x) {
        if (horizontalSpeed < MAX_HORIZONTAL_SPEED) {
            horizontalSpeed += ACCELARATION;
        }
        else {
            horizontalSpeed = MAX_HORIZONTAL_SPEED;
        }
        facingRight = 1;
    }
    else {
        if (horizontalSpeed > -MAX_HORIZONTAL_SPEED) {
            horizontalSpeed -= ACCELARATION;
        }
        else {
            horizontalSpeed = -MAX_HORIZONTAL_SPEED;
        }
        facingRight = 0;
    }

    if (followingPlayer->getPosition().y < getPosition().y) {
        if (!onAir)
        {
            verticalSpeed = -JUMP_STRENGTH;
            onAir = 1;
        }
        else {
            onAir = 0;
        }
    }

    if (abs(horizontalSpeed) > friccao) {
        horizontalSpeed -= ((horizontalSpeed > 0) - (horizontalSpeed < 0)) * friccao;
    }
    else
        horizontalSpeed = 0;

    verticalSpeed += 1;

    vetorDesloc.x *= horizontalSpeed;
    vetorDesloc.y *= verticalSpeed;

    move(vetorDesloc);

    followingPlayer = searchPlayer();

    if (!followingPlayer) {
        if (facingRight) {
            facingRight = 0;
        }
        else
            facingRight = 1;
        state = PATROLLING;
    }
}

const int EnemyMelee::JUMP_STRENGTH(15);

const bool EnemyMelee::checkOnLedge() {
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
        if (ret.intersects((*it)->getGlobalBounds()))
            return false;
    }

    return true;

}