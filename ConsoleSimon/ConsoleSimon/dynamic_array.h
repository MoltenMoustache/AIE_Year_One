#pragma once
#include <iostream>

template <typename T>
class dynamic_array
{
public:
	// DONE
	dynamic_array() {
		m_data = new T[m_default_capacity];
		m_capacity = m_default_capacity;
		m_count = 0;
	}

	// DONE
	dynamic_array(T &a_value) {
		m_data[m_count] = a_value;
	}

	// DONE
	~dynamic_array() {
		delete m_data;
		m_data = nullptr;
	}

	// DONE
	dynamic_array(const dynamic_array& other) {
		m_data = new T(*other.m_data);
	}

	// DONE
	dynamic_array& operator=(const dynamic_array& a_other) {

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

		m_count = a_other.m_count;
		m_capacity = a_other.m_capacity;
		m_data = new T[m_capacity];

		// Deep copy
		for (size_t i = 0; i < m_capacity; i++) {
			m_data[i] = a_other.m_data[i];
		}

		return *this;
	}

	T operator[](const int a_index) {
		return m_data[a_index];
	}

	// DONE
	// adds new array element to end of array
	void push_back(T a_new_data) {
		if (m_count == m_capacity) {
			m_capacity += m_default_capacity;
			T *m_newArray = new T[m_capacity];
			
			for (size_t i = 0; i < m_count; i++)
			{
				m_newArray[i] = m_data[i];
			}

			delete[] m_data;
			m_data = m_newArray;

		}
		m_data[m_count] = a_new_data;
		m_count++;
		std::cout << *m_data << std::endl;
	}

	// DONE
	// removes last array element
	void pop() {
		m_count--;
	}

	void push_front(T a_new_data) {

		if (m_count == m_capacity || (m_count + 1) == m_capacity) {
			m_capacity += m_default_capacity;
			T *m_newArray = new T[m_capacity];

			for (size_t i = 0; i < m_count; i++)
			{
				m_newArray[i] = m_data[i];
			}
			delete[] m_data;
			m_data = m_newArray;
		}

		for (size_t i = m_count; i > 0; i--)
		{
			m_data[i + 1] = m_data[i];
		}
		m_data[1] = m_data[0];
		m_data[0] = a_new_data;
	}

private:
	T *m_data = nullptr;
	int m_capacity = 0;
	int m_count = 0;
	const int m_default_capacity = 8;
};

