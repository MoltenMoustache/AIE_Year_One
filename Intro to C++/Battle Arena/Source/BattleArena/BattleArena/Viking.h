/*=============================
	 J O S H		M O T E N	
  =============================

	File: Viking.h
	Date Modified: 20/2/2019

	Modifications:
	- Additional comments
  =============================*/



#pragma once
#include <cstring>
#include <iostream>

const int BUFFER_LENGTH = 80;

class Viking
{

public:
	Viking(char a_name[], char a_attackName[], int a_health, int a_attackPower);
	Viking() {};
	const int get_health() const;
	const char* const get_name() const;
	const char* const get_attackName() const;
	const int get_attackPower() const;
	
	void attack(Viking& a_target) const;


	bool isSlain = false;

private:

	int health = 0;
	int attackPower = 0;
	char name[BUFFER_LENGTH];
	char attackName[BUFFER_LENGTH];
	 
};

