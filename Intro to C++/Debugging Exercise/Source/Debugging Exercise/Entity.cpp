#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

bool Entity::isAlive()
{
	if (health <= 0) {
		return false;
	}
	else {
		return true;
	};
}

void Entity::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}

int Entity::attack()
{
	int damage = (rand() % maxDamage + 1);
	return damage;
}
