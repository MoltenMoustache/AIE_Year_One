#include <iostream>
#include "HashFunction.h"


int main()
{
	const int BUFFER_SIZE = 10;

	HashFunction hashFunction;

	unsigned char name_josh[BUFFER_SIZE] = "Josh";
	unsigned char name_paige[BUFFER_SIZE] = "Paige";

	// Simple Hash (adding unsigned char values to an unsigned integer)
	std::cout << "Simple Hash:\n";
	// Passes in the name "Josh" and returns a value
	std::cout << hashFunction.BasicHash(name_josh, BUFFER_SIZE) << std::endl;
	// Passes in the name "Paige" and returns a value
	std::cout << hashFunction.BasicHash(name_paige, BUFFER_SIZE) << std::endl;
	// Once more, passes in the name "Josh" and returns the same value as before.
	std::cout << hashFunction.BasicHash(name_josh, BUFFER_SIZE) << std::endl;

	// Brian Kernighan and Dennis Ritchie Hash, (adds unsigned char values to a hash sum that is multiplied by a pattern of numbers)
	std::cout << "\nBKDR Hash:\n";
	// Passes in the name "Josh" and returns a value
	std::cout << hashFunction.BKDRHash(name_josh, BUFFER_SIZE) << std::endl;
	// Passes in the name "Paige" and returns a value
	std::cout << hashFunction.BKDRHash(name_paige, BUFFER_SIZE) << std::endl;
	// Once more, passes in the name "Josh" and returns the same value as before.
	std::cout << hashFunction.BKDRHash(name_josh, BUFFER_SIZE) << std::endl;

	std::cout << "\nELF Hash:\n";
	// Passes in the name "Josh" and returns a value
	std::cout << hashFunction.ELFHash(name_josh, BUFFER_SIZE) << std::endl;
	// Passes in the name "Paige" and returns a value
	std::cout << hashFunction.ELFHash(name_paige, BUFFER_SIZE) << std::endl;
	// Once more, passes in the name "Josh" and returns the same value as before.
	std::cout << hashFunction.ELFHash(name_josh, BUFFER_SIZE) << std::endl;
	

	system("pause");

}