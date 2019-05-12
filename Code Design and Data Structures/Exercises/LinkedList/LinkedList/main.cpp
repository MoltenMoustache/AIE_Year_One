#include <iostream>
#include "linked_list.h"

int main() {
	linked_list<int> intList;

	intList.push_back(99);
	intList.push_back(99);
	intList.push_back(99);

	for (size_t i = 0; i < 10; i++)
	{
		intList.push_front(i);
	}
	intList.display();

	intList.insert(500, 3);
	intList.remove_by_index(5);
	intList.remove_by_value(500);
	intList.display();

	intList.pop_back();
	intList.pop_front();
	intList.display();
	std::cout << intList.count() << std::endl;
	std::cout << intList.first_value() << std::endl;
	std::cout << intList.last_value() << std::endl;

	if (intList.is_empty()) {
		std::cout << "List is empty!\n";
	}
	else {
		std::cout << "List is not empty!\n";
	}
	
	intList.clear();
	
	if (intList.is_empty()) {
		std::cout << "List is empty!\n";
	}
	else {
		std::cout << "List is not empty!\n";
	}

	system("pause");
}