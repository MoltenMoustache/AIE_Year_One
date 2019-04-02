#include <iostream>
#include "dynamic_array.h"
#include "linked_list.h"
#include "stack.h"
#include "Queue.h"
#include <ctime>


int main() {
	srand(time(nullptr));

	//// *** LINKED LISTS ***
	//std::cout << "\n*** LINKED LIST ***\n";
	//linked_list<int> int_list;

	//for (size_t i = 0; i < 11; i++)
	//{
	//	int_list.push_back(i);					// inserts i at end of list
	//}
	//int_list.display();							// displays the list to console
	//int_list.pop_back();						// deletes last element of list
	//int_list.pop_front();						// deletes first element of list
	//int_list.display();
	//int_list.remove_by_index(5);				// deletes element at Xth index
	//int_list.remove_by_value(2);				// deletes all elements of value X within list
	//int_list.display();
	//std::cout << "Number of elements in list: " << int_list.count() << std::endl;			// list.count() returns number of elements in list
	//
	//int_list.clear();
	//int_list.push_front(19);					// inserts value into start of list
	//int_list.push_front(72);
	//int_list.display();
	//std::cout << "First value in list: " << int_list.first_value() << "\n";							// list.first_value() returns the value of the first element
	//std::cout << "Last value in list: " << int_list.last_value() << "\n";							// list.first_value() returns the value of the first element

	//if (int_list.is_empty()) {					// list.is_empty() returns a boolean depending on whether or not the list is empty
	//	std::cout << "List is empty!\n";
	//}
	//else {
	//	std::cout << "List isn't empty!\n";
	//}

	//int_list.clear();
	//if (int_list.is_empty()) {
	//	std::cout << "List is empty!\n";
	//}
	//else {
	//	std::cout << "List isn't empty!\n";
	//}

	//std::cout << "Start node*: " << int_list.start() << "\n";							// list.start() returns the m_start node
	//std::cout << "End node*: " << int_list.end() << "\n";							// list.end() returns the m_end node

	//// *** DYNAMIC ARRAY ***
	//std::cout << "\n*** DYNAMIC ARRAY ***\n";
	//dynamic_array<int> int_array;

	//for (size_t i = 0; i < 11; i++)
	//{
	//	int_array.push_back(i);					// inserts i at end of array
	//}

	//// insert_at_index(array, array size, index)
	//// insert_at_index(dynamic array, array size, index)

	//int_array.remove_at_index(3);				// delete array element at index X
	//int_array.pop();							// delete last element of array
	//int_array.push_back(12);
	//int_array.push_front(14);					// insert at front of array
	//int_array.push_at_index(18, 5);				// push the value 18 to index 5
	//int_array.display();						// displays the array to console
	//int_array.clear();							// clears the array
	//int_array.push_front(17);
	//int_array.push_back(7);
	//int_array.display();

	stack<int> int_stack;
	for (size_t i = 0; i < 10; i++)
	{
		int_stack.push(i+3);
	}

	std::cout << "Size of Stack: " << int_stack.size() << "\n";

	if (int_stack.isEmpty()) {
		std::cout << "Stack is empty!\n";
	}
	else {
		std::cout << "Stack is not empty!\n";
	}

	std::cout << "Top of Stack: " << int_stack.top() << "\n";
	int_stack.display();

	std::cout << "\n================================\n\n";

	Queue<int> int_queue;
	for (size_t i = 0; i < 11; i++)
	{
		int_queue.push_back(i + 3);
	}
	std::cout << "Size of Queue: " << int_queue.size() << "\n";
	if (int_queue.isEmpty()) {
		std::cout << "Queue is empty!\n";
	}
	else {
		std::cout << "Queue is not empty!\n";
	}
	std::cout << "Front of Queue: " <<int_queue.front() << "\n";
	int_queue.display();
	system("pause");

	return 0;
}