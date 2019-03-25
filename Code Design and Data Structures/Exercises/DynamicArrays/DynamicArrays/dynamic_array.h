#pragma once
#include <iostream>

//template <typename T>
class dynamic_array
{
public:
	dynamic_array() {
		m_data = new int[m_default_capacity];
		m_capacity = m_default_capacity;
		m_count = 0;
	}

	dynamic_array(int &a_value) {
		m_data[m_count] = a_value;
	}

	~dynamic_array() {
		delete m_data;
		m_data = nullptr;
	}

	dynamic_array(const dynamic_array& other) {
		m_data = new int(*other.m_data);
	}

	dynamic_array& operator=(const dynamic_array& other) {
		*m_data = *other.m_data;
		return *this;
	}

	// adds new array element to end of array
	void Push(int a_new_data) {
		m_data[m_count] = a_new_data;
		m_count++;
		std::cout << *m_data << std::endl;
	}

	// removes last array element
	void Pop() {
		m_count--;
	}

private:
	int *m_data = nullptr;
	int m_capacity = 0;
	int m_count = 0;
	const int m_default_capacity = 8;
};

