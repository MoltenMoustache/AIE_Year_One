#pragma once
#include <ctime>
#include <iostream>

class Entity
{
public:
	Entity();
	~Entity();

	int attack();
	virtual void takeDamage(int damage);
	bool isAlive();

protected:
	int health;
	int maxHealth;
	int maxDamage;
};

