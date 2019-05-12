#include <iostream>
#include "dynamic_array.h"
#include "linked_list.h"
#include "stack.h"
#include "Queue.h"
#include <ctime>


int main() {
	srand(time(nullptr));


	//// *** DYNAMIC ARRAY ***
	std::cout << "Dynamic Array:\n";
	dynamic_array<int> intArray;

	// Pushes 10 random numbers between 1 & 50, then displays the current iteration of the array.
	for (size_t i = 0; i < 10; i++)
	{
		intArray.push_back(rand() % 50);
	}
	intArray.display();
	// sorts array and displays it again
	intArray.quickSort();
	std::cout << "Sorted Array: ";
	intArray.display();

	// Pushes the value '999' to intArray[4]
	intArray.push_at_index(999, 4);
	// Removes the value from intArray[4]
	intArray.remove_at_index(4);
	intArray.display();

	intArray.clear();
	/*for (size_t i = 0; i < 10; i++)
	{
		intArray.push_front(rand() % 50);
	}*/
	//intArray.push_at_index(999, 1);
	intArray.push_back(54);
	intArray.push_front(1500);
	intArray.push_front(1500);
	intArray.push_front(1500);

	int newArray[5] = { 5, 6, 7, 8, 9 };

	intArray.push_at_index(newArray, 5, 2);
	intArray.display();

	intArray.clear();
	intArray.concadenate(newArray, 5);
	intArray.concadenate(newArray, 5);
	intArray.display();


	/*
	[X] Dynamic Array
	[X] Linked List
	[X] Binary Tree
	[X] Search algorithm
	[X] Sort algorithm
	[X] 100 Word Document about sort algorithms
	[X] Hash function
	[X] Inter process communication
	[ ] TDD for Simeon Says
	[X] Game contains at least one button
	[X] Error checking
	[X] Version control
	[ ] Playtest (Simeon Says)
	[ ] Playtest (Other Games)
	*/

	system("pause");

	return 0;
}