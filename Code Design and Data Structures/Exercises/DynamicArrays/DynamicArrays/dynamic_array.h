#pragma once
#include <iostream>

template <typename T>
class dynamic_array
{
public:

	dynamic_array() {
		m_data = new T[m_default_capacity];
		m_capacity = m_default_capacity;
		m_count = 0;
	}

	dynamic_array(T &a_value) {
		m_data[m_count] = a_value;
	}

	~dynamic_array() {
		//delete m_data;
		m_data = nullptr;
	}

	dynamic_array(const dynamic_array& other) {
		m_data = new T(*other.m_data);
	}

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

	T& operator[](const int a_index) {
		return m_data[a_index];
	}

	void push_back(T a_new_data) {
		if (m_count == m_capacity) {
			grow();
		}
		m_data[m_count] = a_new_data;
		m_count++;
	}

	void pop() {
		m_count--;
	}

	void push_front(T a_new_data) {

		if (m_count == m_capacity)
		{
			grow();
		}

		if (m_count > 0) {
			for (size_t i = 0; i < m_count; i++)
			{
				// this is stupid and looking at it makes me mad
				// but it won't work any other way so here it is.
				m_data[m_count - i] = m_data[(m_count - 1) - i];
			}

			m_data[0] = a_new_data;
		}
		else {
			m_data[m_count] = a_new_data;
		}
		m_count++;

	}

	void push_at_index(const T& a_new_value, size_t a_index) {
		if (m_count == m_capacity) {
			grow();
		}

		if (m_count > 0) {
			for (size_t i = m_count - 1; i >= a_index; i--)
			{
				m_data[i + 1] = m_data[i];
			}
			m_data[a_index] = a_new_value;
			m_count++;
		}
		else {
			m_data[m_count] = a_new_value;
			m_count++;
		}
	}

	void push_at_index(const T* a_new_value, size_t a_element_count, size_t a_index) {
		a_index--;

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
			m_data[i] = a_new_value[j];
		}
		m_count += a_element_count;
	}

	void push_at_index(const dynamic_array<T>& a_data, size_t a_index) {
		push_at_index(a_data.m_data, a_data.m_count, a_index);
	}

	void remove_at_index(size_t a_index, size_t a_count = 1) {
		for (size_t i = a_index; i + a_count < m_count; i++)
		{
			m_data[i] = m_data[i + a_count];
		}
		m_count -= a_count;
	}

	void concadenate(const T* a_newValue, size_t a_elementCount) {

		for (size_t i = 0; i < a_elementCount; i++)
		{
			push_back(a_newValue[i]);
		}
	}

	void clear() {
		m_count = 0;
	}

	void display() {

		for (size_t i = 0; i < m_count; i++)
		{
			std::cout << m_data[i] << ", ";
		}
		std::cout << std::endl;
	}

	bool find(T& a_targetValue) {

		// Linear search, gradually progresses through array from start to finish
		for (size_t i = 0; i < m_count; i++)
		{
			// if the currently indexed value is the target
			if (m_data[i] == a_targetValue) {

				// return the search as true!
				return true;
			}
		}

		// if it reaches this point, the target was not found.
		// Return false.
		return false;
	}

	// Bubble Sort, done for the heck of it.
	void bubbleSort()
	{
		bool swapped;
		for (size_t i = 1; i < m_count; i++)
		{
			swapped = false;
			for (size_t j = 0; j < m_count - i; i++)
			{
				if (m_data[j] > m_data[j + 1])
				{
					swap(&m_data[i], &m_data[j]);
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break 
			if (!swapped)
				break;
		}
	}

	// Overloaded sort function, takes no parameters.
	void quickSort() {

		// Sets default values of upper and lower bounds
		int a_lowRange = 0;
		int a_highRange = m_count - 1;

		// if lower range value is lower than the upper range
		if (a_lowRange < a_highRange) {

			// call partition function between lower and upper range values
			int pi = partition(a_lowRange, a_highRange);

			// recursive functions (calls overloaded private function of quickSort with upper and lower range variables)
			quickSort(a_lowRange, pi - 1);
			quickSort(pi + 1, a_highRange);
		}
	}

	void insertSort() {
		T key = 0;
		for (size_t i = 1; i < m_count; i++)
		{
			key = m_data[i];
			int j = i - 1;

			while ((j >= 0) && (m_data[j] > key)) {
				m_data[j + 1] = m_data[j];
				j--;
			}
			m_data[j + 1] = key;
		}
	}


private:
	T *m_data = nullptr;
	int m_capacity = 0;
	int m_count = 0;
	const int m_default_capacity = 8;


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

	void trim() {
		if (m_count < m_capacity) {
			m_capacity = m_count + 1;
			T *m_newArray = new T[m_capacity];

			for (size_t i = 0; i < m_count; i++)
			{
				m_newArray[i] = m_data[i];
			}

			delete[] m_data;
			m_data = m_newArray;
		}
	}

	// Overloaded quickSort function (with low and high range parameters)
	void quickSort(int a_lowRange, int a_highRange) {

		if (a_lowRange < a_highRange) {

			int pi = partition(a_lowRange, a_highRange);

			quickSort(a_lowRange, pi - 1);
			quickSort(pi + 1, a_highRange);
		}
	}

	// Partition function (private as only used in other functions)
	int partition(int a_lowRange, int a_highRange) {
		T pivot = m_data[a_highRange];
		int i = (a_lowRange - 1);

		for (size_t j = a_lowRange; j <= a_highRange - 1; j++)
		{
			if (m_data[j] <= pivot) {
				i++;
				swap(&m_data[i], &m_data[j]);
			}
		}
		swap(&m_data[i + 1], &m_data[a_highRange]);
		return (i + 1);
	}

	template <class T>
	void swap(T* a, T* b)
	{
		T temp = *a;
		*a = *b;
		*b = temp;
	}
};