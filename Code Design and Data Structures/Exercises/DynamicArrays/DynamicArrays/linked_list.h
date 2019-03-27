#pragma once
#include <iostream>

template <typename T>
class node {
public:
	node<T>* m_previous;
	node<T>* m_next;

	T m_data;
};

template <typename T>
class linked_list {
public:
	// Sentinel Node
	node<T>* m_start = nullptr;
	node<T>* m_end = nullptr;

	// [DONE]
	linked_list() {
		// allocating memory for sentinel nodes
		m_start = new node<T>();
		m_end = new node<T>();

		// cross link sentinels
		m_start->m_next = m_end;
		m_end->m_previous = m_start;
	}

	// [DONE]
	~linked_list() {
		node<T>* m_current = m_start->m_next;
		while (m_current != m_end) {
			node<T>* next = m_current->m_next;
			delete m_current;
			m_current = nullptr;
			m_current = next;
		}

		delete m_start;
		m_start = nullptr;

		delete m_end;
		m_end = nullptr;
	}

	// [DONE]
	void push_back(const T& a_new_data) {
		node<T>* m_new = new node<T>();
		m_new->m_data = a_new_data;

		m_new->m_next = m_end;
		m_new->m_previous = m_end->m_previous;
		m_end->m_previous->m_next = m_new;
		m_end->m_previous = m_new;
	}

	// [DONE]
	void push_front(const T& a_new_data) {
		node<T>* m_new = new node<T>();
		m_new->m_data = a_new_data;

		m_new->m_previous = m_start;
		m_new->m_next = m_start->m_next;
		m_start->m_next->m_previous = m_new;
		m_start->m_next = m_new;
	}

	// [DONE]
	void insert(const T& a_new_data, const size_t a_index) {
		// count to index
		node<T>* m_current = m_start->m_next;
		size_t counter = 1;

		while (counter < a_index && m_current != m_end)
		{
			m_current = m_current->m_next;
			counter++;
		}

		//create node
		node<T>* m_new_location = new node<T>();
		m_new_location->m_data = a_new_data;

		//link node into list
		m_new_location->m_next = m_current->m_next;
		m_new_location->m_previous = m_current->m_previous;
		m_current->m_next->m_previous = m_new_location;
		m_current->m_previous->m_next = m_new_location;
		m_current = m_new_location;
	}

	// [DONE]
	void remove_by_index(const size_t a_index) {
		// count to index
		node<T>* m_current = m_start->m_next;
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

	// [DONE]
	void remove_by_value(const T a_value) {
		node<T>* m_current = m_start->m_next;

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

	// [DONE]
	node<T>* start() {
		return m_start;
	}

	// [DONE]
	node<T>* end() {
		return m_end;
	}

	// [DONE]
	void pop_back() {
		m_end->m_previous->m_previous->m_next = m_end;
		m_end->m_previous = m_end->m_previous->m_previous;
	}

	// [DONE]
	void pop_front() {
		m_start->m_next->m_next->m_previous = m_start;
		m_start->m_next = m_start->m_next->m_next;
	}

	// [DONE]
	int count() {
		node<T>* m_current = m_start->m_next;
		int counter = 0;

		while (m_current != m_end)
		{
			m_current = m_current->m_next;
			counter++;
		}
		return counter;
	}

	// [DONE]
	T first_value() {
		return m_start->m_next->m_data;
	}

	// [DONE]
	T last_value() {
		return m_end->m_previous->m_data;
	}

	// [DONE]
	bool is_empty() {
		if (m_start->m_next == m_end && m_end->m_previous == m_start) {
			return true;
		}
		else {
			return false;
		}
	}

	// [DONE]
	void clear() {
		node<T>* m_current = m_start->m_next;
		while (m_current != m_end) {
			node<T>* next = m_current->m_next;
			delete m_current;
			m_current = nullptr;
			m_current = next;
		}

		m_start->m_next = m_end;
		m_end->m_previous = m_start;
	}

	// [DONE]
	void display() {
		node<T>* m_current = m_start->m_next;

		std::cout << "Linked List:\t";

		while (m_current != m_end)
		{
			std::cout << m_current->m_data << ", ";
			m_current = m_current->m_next;
		}
		std::cout << std::endl;
	}

};