#include "Hitbox.h"

Hitbox::Hitbox(const bool tar, Entity* own, const bool isBo):
	target(tar),
	owner(own),
	isBounded(isBo)
{

}

void Hitbox::hitSolution(Alive* hit)
{
	
}

void Hitbox::movement() { }
