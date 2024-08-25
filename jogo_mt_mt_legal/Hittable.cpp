#include "Hittable.h"

Hittable::Hittable(const bool ally, const int health):
	isAlly(ally),
	hp(health),
	stun(0),
	state(FREE),
	facingRight(1),
	fireRemaining(0),
	fireCont(0),
	points(0)
{

}

void Hittable::setFireRemaining(const int cont)
{
	fireRemaining = cont;
}

const bool Hittable::getIsAlly() const
{
	return isAlly;
}

void Hittable::setStun(const int st)
{
	stun = st;
}

const int Hittable::getStun() const
{
	return stun;
}

void Hittable::setState(const int st)
{
	state = st;
}

const int Hittable::getState() const
{
	return state;
}

void Hittable::dealDamage(const int dmg)
{
	hp -= dmg;
}

int Hittable::getHp() {
	return hp;
}

int Hittable::getPoints() {
	return points;
}

void Hittable::setPoints(int p) {
	points = p;
}