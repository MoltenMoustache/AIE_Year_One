#pragma once
#include <iostream>

template <typename T>
class Stack {
public:

	Stack() {
		m_data = new T[m_default_capacity];
		m_capacity = m_default_capacity;
		m_top = 0;
	}

	~Stack() {
		delete m_data;
		m_data = nullptr;
	}

	Stack(const Stack& a_other) {
		m_data = new T(*a_other.m_data);
	}

	Stack& operator=(const Stack& a_other) {

		// If address of copy constructor is the same as this data, exit function.
		// prevents m_array = m_array;
		if (&a_other == this) {
			return *this;
		}

		// Check if preallocated
		if (m_data) { 					// if m_data != nullptr;
			delete[] m_data;
			m_data = nullptr;
		}

		m_top = a_other.m_count;
		m_capacity = a_other.m_capacity;
		m_data = new T[m_capacity];

		// Deep copy
		for (size_t i = 0; i < m_capacity; i++) {
			m_data[i] = a_other.m_data[i];
		}

		return *this;
	}

	T& operator[](const int a_other) {
		return m_data[a_other];
	}


	// returns whether or not the stack is empty
	bool isEmpty() {
		if (m_top == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// returns number of elements in stack
	int size() {
		return m_top;
	}

	// adds an element of type T to the top of the stack
	void push(const T& a_value) {
		if (m_top == m_capacity) {
			grow();
		}

		m_data[m_top] = a_value;
		m_top++;
	}

	// remove an element from the top of the stack
	void pop() {
		if (m_top > 0) {
			m_data[m_top] = nullptr;
			m_top--;
		} else {
			// Non critical error, game does not halt.
			std::cout << "ERROR: .pop() invalid, Stack is empty.\n";
		}
	}

	// clear the stack
	void clear() {
		if (m_top > 0) {
			delete m_data;
			m_data = new T[m_default_capacity];
			m_capacity = m_default_capacity;
			m_top = 0;
		}
		else {
			// Non critical error, game does not halt.
			std::cout << "ERROR: .clear() is invalid, Stack is already empty.\n";
		}
	}

	// returns value of top of stack
	T& top() {
		return m_data[m_top - 1];
	}

private:
	T* m_data;
	int m_capacity = 0;
	const int m_default_capacity = 8;
	int m_top = 0;

	void grow() {
		if (m_top == m_capacity) {
			m_capacity += m_default_capacity;
			T *m_newArray = new T[m_capacity];

			for (size_t i = 0; i < m_top; i++)
			{
				m_newArray[i] = m_data[i];
			}

			delete[] m_data;
			m_data = m_newArray;
			trim();
		}
	}

	void trim() {
		if (m_top < m_capacity) {
			m_capacity = m_top + 1;
			T *m_newArray = new T[m_capacity];

			for (size_t i = 0; i < m_top; i++)
			{
				m_newArray[i] = m_data[i];
			}

			delete[] m_data;
			m_data = m_newArray;
		}
	}
};

enum Colour {
	Red,
	Blue,
	Green,
	Yellow,
};