#pragma once
#include <iostream>

template <typename T>
class Queue {
public:

	// Sentinel Node
	node<T>* m_start = nullptr;
	node<T>* m_end = nullptr;

	Queue() {
		// allocating memory for sentinel nodes
		m_start = new node<T>();
		m_end = new node<T>();

		// cross link sentinels
		m_start->m_next = m_end;
		m_end->m_previous = m_start;
	}

	~Queue() {

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

	bool isEmpty() {
		if (m_start->m_next == m_end && m_end->m_previous == m_start) {
			return true;
		}
		else {
			return false;
		}
	}

	int size() {
		node<T>* m_current = m_start->m_next;
		int counter = 0;

		while (m_current != m_end)
		{
			m_current = m_current->m_next;
			counter++;
		}
		return counter;
	}

	void push_back(const T& a_value) {
		node<T>* m_new = new node<T>();
		m_new->m_data = a_value;

		m_new->m_next = m_end;
		m_new->m_previous = m_end->m_previous;
		m_end->m_previous->m_next = m_new;
		m_end->m_previous = m_new;
	}

	void pop_front() {
		m_start->m_next->m_next->m_previous = m_start;
		m_start->m_next = m_start->m_next->m_next;
	}

	T& front() {
		return m_start->m_next->m_data;
	}

	void display() {
		node<T>* m_current = m_start->m_next;

		std::cout << "Queue:\t";

		while (m_current != m_end)
		{
			std::cout << m_current->m_data << ", ";
			m_current = m_current->m_next;
		}
		std::cout << std::endl;
	}

};