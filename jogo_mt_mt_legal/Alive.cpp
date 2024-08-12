#include "Alive.h"

Alive::Alive(const bool ally, const int health):
	isAlly(ally),
	hp(health)
{

}

const bool Alive::getIsAlly() const
{
	return isAlly;
}
