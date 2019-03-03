/*=============================
	 J O S H		M O T E N
  =============================

	File: Viking.cpp
	Date Modified: 20/2/2019

	Modifications:
	- If health is in the negatives, set it to 0 for display purposes.
	- If the Viking is on 1 hit point, it displays "hit point!" as opposed to "hit points!"
  =============================*/



#include "Viking.h"



Viking::Viking(char a_name[], char a_attackName[], int a_health, int a_attackPower)
{
	health = a_health;
	attackPower = a_attackPower;
	strcpy(name, a_name);
	strcpy(attackName, a_attackName);
}

const int Viking::get_health() const{
	return health;
}

const int Viking::get_attackPower() const {
	return attackPower;
}

const char* const Viking::get_name() const {
	return name;
}

const char* const Viking::get_attackName() const {
	return attackName;
}

void Viking::attack(Viking& a_target) const {
	int damage = rand() % attackPower+1;

	a_target.health -= damage;
	std::cout << a_target.name << " has been hit by " << name << " using " << attackName << " for " << damage << " damage!\n";

	if (a_target.health <= 0) {
		a_target.health = 0;
		std::cout << a_target.name << " has " << a_target.get_health() << " remaining hit points!\n\n";

		std::cout << "!!!\t" << a_target.name << " has been slain!\t!!!\n\n";
		a_target.isSlain = true;
	}
	else if (a_target.health > 1){
		std::cout << a_target.name << " has " << a_target.get_health() << " remaining hit points!\n\n";
	}
	else if (a_target.health == 1) {
		std::cout << a_target.name << " has " << a_target.get_health() << " remaining hit point!\n\n";
	}
}
