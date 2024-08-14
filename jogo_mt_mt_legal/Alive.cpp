#include "Alive.h"

Alive::Alive(const bool ally, const int health):
	isAlly(ally),
	hp(health),
	stun(0),
	state(FREE),
	facingRight(1)
{

}

const bool Alive::getIsAlly() const
{
	return isAlly;
}

void Alive::setStun(const int st)
{
	stun = st;
}

const int Alive::getStun() const
{
	return stun;
}

void Alive::setState(const int st)
{
	state = st;
}

const int Alive::getState() const
{
	return state;
}

void Alive::dealDamage(const int dmg)
{
	hp -= dmg;
}