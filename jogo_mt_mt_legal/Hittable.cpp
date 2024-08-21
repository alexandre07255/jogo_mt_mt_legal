#include "Hittable.h"

Hittable::Hittable(const bool ally, const int health):
	isAlly(ally),
	hp(health),
	stun(0),
	state(FREE),
	facingRight(1)
{

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