#pragma once
template<typename T>
class node {
public:
	// construction of node with valid data
	node(const T& a_data) : m_data(a_data) {};

	~node() {};

	// Data member for this node
	T m_data;
	
	// Graph linage
	node<T>* m_parent = nullptr;
	node<T>* m_leftNode = nullptr;
	node<T>* m_rightNode = nullptr;
};