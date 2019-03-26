#include <iostream>
#include "dynamic_array.h"
#include "linked_list.h"
#include <ctime>


int main() {
	srand(time(nullptr));

	// LINKED LISTS
	linked_list<int> my_list;

	for (int i = 0; i < 6; i++)
	{
		my_list.push_back(i+1);
	}

	for (int i = 0; i < 9; i++)
	{
		my_list.push_front(i+1);
	}

	my_list.display();
	std::cout << "\n=====================================\n\n";
	std::cout << std::endl << std::endl;
	my_list.remove_by_value(size_t(1));
	my_list.display();
	std::cout << my_list.end_index() << std::endl;
	//std::cout << "\n=====================================\n\n";
	////my_list.pop_front();
	////my_list.insert(54, 3);
	////my_list.display();

	//std::cout << "\nThere are " << my_list.count() << " number of elements in this list!\n";
	//std::cout << "\nFirst value of list is; " << my_list.first_value() << " and the second value is; " << my_list.last_value() << std::endl;

	//my_list.pop_back();
	//my_list.display();
	//my_list.clear();
	//my_list.display();

	if (my_list.is_empty()) {
		std::cout << "\nList empty!\n";
	}
	else {
		std::cout << "\nList not empty!\n";
	}




	// DYNAM ARRAYS
	dynamic_array<size_t> dynamArray;

	dynamArray.push_back(10);
	dynamArray.push_back(5);
	dynamArray.push_back(23);

	dynamArray.pop();
	dynamArray.pop();

	dynamArray.push_back(100);

	dynamic_array<size_t> dynamArray_2;
	dynamArray_2 = dynamArray;

	for (size_t i = 0; i < 10; i++)
	{
		dynamArray_2.push_back(rand() % 100);
	}

	size_t d = dynamArray_2[7];
	dynamArray_2.push_front(d);

	return 0;
}