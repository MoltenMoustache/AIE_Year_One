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

	// [DONE]
	T& operator[](const int a_index) {
		return m_data[a_index];
	}

	// DONE
	void push_back(T a_new_data) {
		if (m_count == m_capacity) {
			grow();
		}
		m_data[m_count] = a_new_data;
		m_count++;
	}

	// DONE
	void pop() {
		m_count--;
	}
	
	// [DONE]
	void push_front(T a_new_data) {

		if (m_count == m_capacity || (m_count + 1) == m_capacity) {
			grow();
		}

		for (size_t i = m_count; i > 0; i--)
		{
			m_data[i + 1] = m_data[i];
		}
		m_data[1] = m_data[0];
		m_data[0] = a_new_data;
		m_count++;
	}
	
	// [DONE]
	void push_at_index(const T& a_new_value, size_t a_index) {
		if (m_count == m_capacity) {
			grow();
		}

		for (size_t i = m_count - 1; i >= a_index; i--)
		{
			m_data[i + 1] = m_data[i];
		}
		m_data[a_index] = a_new_value;
		m_count++;
	}

	// [NEEDS WORK]
	void push_at_index(const T* a_new_value, size_t a_element_count, size_t a_index) {
		while (m_count + a_element_count >= m_capacity) {
			grow();
		}

		for (size_t i = m_count - 1; i >= a_index; i--)
		{
			m_data[i + a_element_count] = m_data[i];
		}

		size_t j = 0;
		for (size_t i = a_index; i < a_index + a_element_count; i++, j++)
		{
			m_data[a_index] = a_new_value[j];
		}
		m_count+= a_element_count;
	}

	// [NEEDS WORK]
	void push_at_index(const dynamic_array<T>& a_data, size_t a_index) {
		push_at_index(a_data.m_data, a_data.m_count, a_index);
	}

	// [DONE]
	void remove_at_index(size_t a_index, size_t a_count = 1) {
		for (size_t i = a_index; i + a_count < m_count; i++)
		{
			m_data[i] = m_data[i + a_count];
		}
		m_count += a_count;
	}

	// [DONE]
	void clear() {
		m_count = 0;
	}

	// [DONE]
	void display() {

		std::cout << "Dynamic Array:\t";

		for (size_t i = 0; i < m_count; i++)
		{
			std::cout << m_data[i] << ", ";
		}
		std::cout << std::endl;
	}

	// [NOT DONE]
	// Quick sort?
	void sort(int a_lowIndex, int a_highIndex)
	{
		if (a_lowIndex < a_highIndex)
		{
			int pi = partition(a_lowIndex, a_highIndex);
			sort(a_lowIndex, pi - 1);
			sort(pi + 1, a_highIndex);
		}
	}

private:
	T *m_data = nullptr;
	int m_capacity = 0;
	int m_count = 0;
	const int m_default_capacity = 8;
	

	// [DONE]
	void grow() {
		if (m_count == m_capacity) {
			m_capacity += m_default_capacity;
			T *m_newArray = new T[m_capacity];

			for (size_t i = 0; i < m_count; i++)
			{
				m_newArray[i] = m_data[i];
			}

			delete[] m_data;
			m_data = m_newArray;
			trim();
		}

	}

	// [DONE]
	void trim() {
		if (m_count < m_capacity) {
			m_capacity = m_count;
			T *m_newArray = new T[m_capacity];

			for (size_t i = 0; i < m_count; i++)
			{
				m_newArray[i] = m_data[i];
			}

			delete[] m_data;
			m_data = m_newArray;
		}
	}

	// [DONE]
	void swap(T *a, T *b) {										//function for swapping vikings in array, used for bubble sort
		T temp = *a;
		*a = *b;
		*b = temp;
	}

	T partition(int a_lowIndex, int a_highIndex)
	{
		T pivot = m_data[a_highIndex];
		int index = (a_lowIndex - 1);

		for (int j = a_lowIndex; j <= a_highIndex; j++)
		{
			if (m_data[j] <= pivot)
			{
				index++;
				swap(m_data[index], m_data[j]);
			}
		}
		swap(m_data[index + 1], m_data[a_highIndex]);
		return (index + 1);
	}

};