#include "AttackHitbox.h"

AttackHitbox::AttackHitbox(const bool tar, Alive* own, Entity* boundTo, sf::Vector2f rel, const int dur, sf::Vector2f _size) :
	Hitbox(tar, own, boundTo, rel, dur, _size),
	knockback(-1),
	launchDirection(),
	damage(-1),
	hitList()
{
	hitList.clear();
}

void AttackHitbox::setKnockback(const int knock)
{
	knockback = knock;
}

void AttackHitbox::setLaunchDirection(sf::Vector2f launch)
{
	launchDirection = launch;
}

void AttackHitbox::setDamage(const int dmg)
{
	damage = dmg;
}

void AttackHitbox::hitSolution(Alive* hit)
{

}