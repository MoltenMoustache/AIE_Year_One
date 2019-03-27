#pragma once
#include <iostream>

class node {
public:
	node* m_previous;
	node* m_next;

	Colour m_data;
};

class linked_list {
public:
	// Sentinel Node
	node* m_start = nullptr;
	node* m_end = nullptr;

	linked_list() {
		// allocating memory for sentinel nodes
		m_start = new node();
		m_end = new node();

		// cross link sentinels
		m_start->m_next = m_end;
		m_end->m_previous = m_start;
	}

	~linked_list() {
		node* m_current = m_start->m_next;
		while (m_current != m_end) {
			node* next = m_current->m_next;
			delete m_current;
			m_current = nullptr;
			m_current = next;
		}

		delete m_start;
		m_start = nullptr;

		delete m_end;
		m_end = nullptr;
	}


	void push_back(const Colour a_new_data) {
		node* m_new = new node();
		m_new->m_data = a_new_data;

		m_new->m_next = m_end;
		m_new->m_previous = m_end->m_previous;
		m_end->m_previous->m_next = m_new;
		m_end->m_previous = m_new;
	}

	void push_front(const Colour a_new_data) {
		node* m_new = new node();
		m_new->m_data = a_new_data;

		m_new->m_previous = m_start;
		m_new->m_next = m_start->m_next;
		m_start->m_next->m_previous = m_new;
		m_start->m_next = m_new;
	}

	// insert a_new_data at location a_index
	// if a_index is out of bounds
	// data inserted at m_data
	void insert(const Colour a_new_data, const size_t a_index) {
		// count to index
		node* m_current = m_start->m_next;
		size_t counter = 1;

		while (counter < a_index && m_current != m_end)
		{
			m_current = m_current->m_next;
			counter++;
		}

		//create node
		node* m_new_location = new node();
		m_new_location->m_data = a_new_data;

		//link node into list
		m_new_location->m_next = m_current->m_next;
		m_new_location->m_previous = m_current->m_previous;
		m_current->m_next->m_previous = m_new_location;
		m_current->m_previous->m_next = m_new_location;
		m_current = m_new_location;
	}

	void remove_by_index(const size_t a_index) {
		// count to index
		node* m_current = m_start->m_next;
		size_t counter = 1;

		while (counter < a_index && m_current != m_end)
		{
			m_current = m_current->m_next;
			counter++;
		}

		if (m_current != m_end) {

			m_current->m_next->m_previous = m_current->m_previous;
			m_current->m_previous->m_next = m_current->m_next;

			delete m_current;
			m_current = nullptr;
		}
	}

	void remove_by_value(const Colour a_value) {
		node* m_current = m_start->m_next;

		while (m_current != m_end)
		{
			if (m_current->m_data == a_value) {

				m_current->m_next->m_previous = m_current->m_previous;
				m_current->m_previous->m_next = m_current->m_next;
			}

			m_current = m_current->m_next;
		}
		delete m_current;
		m_current = nullptr;

	}

	size_t end_index() {
		node* m_current = m_start->m_next;
		size_t counter = 1;

		while (m_current != m_end)
		{
			m_current = m_current->m_next;
			counter++;
		}

		return --counter;
	}

	size_t start_index() {
		return size_t(1);
	}

	void pop_back() {
		m_end->m_previous->m_previous->m_next = m_end;
		m_end->m_previous = m_end->m_previous->m_previous;
	}

	void pop_front() {
		m_start->m_next->m_next->m_previous = m_start;
		m_start->m_next = m_start->m_next->m_next;
	}

	int count() {
		node* m_current = m_start;
		int counter = 0;

		while (m_current != m_end)
		{
			m_current = m_current->m_next;
			counter++;
		}
		return ++counter;
	}

	Colour first_value() {
		return m_start->m_next->m_data;
	}

	Colour last_value() {
		return m_end->m_previous->m_data;
	}

	bool is_empty() {
		if (m_start->m_next == m_end && m_end->m_previous == m_start) {
			return true;
		}
		else {
			return false;
		}
	}

	void clear() {
		node* m_current = m_start->m_next;
		while (m_current != m_end) {
			node* next = m_current->m_next;
			delete m_current;
			m_current = nullptr;
			m_current = next;
		}

		m_start->m_next = m_end;
		m_end->m_previous = m_start;
	}

	void display() {
		node* m_current = m_start->m_next;

		std::cout << "Linked List:\n";

		while (m_current != m_end)
		{
			std::cout << m_current->m_data << ", ";
			m_current = m_current->m_next;
		}
		std::cout << std::endl;
	}

	bool check_input(const Colour a_input, const int a_count) {

		// count to index
		node* m_current = m_start->m_next;
		Colour m_new_input;

		for (size_t i = 0; i < (a_count+1); i++)
		{
			if (m_current->m_data == a_input) {
				if (m_current->m_next != m_end) {
					m_current->m_next = m_current;
					std::cin << m_new_input;
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					check_input(m_new_input, (a_count + 1));
				}
				else {
					return true;
				}
			}
			else {
				return false;
			}
		}
	}


};