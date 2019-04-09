#pragma once
#include "node.h"
/*
	Binary Tree
		Positions of data are relative to both existing data
		and the order data is added to the traa
		Each leaf can only have two children
		Leaf only has one parent
		Value of left child is < current leaf
		Value of right child is > current leaf
		Any value in a binary tree can only exist once
*/

template <typename T>
class binary_tree
{
public:
	binary_tree<T>() {};
	~binary_tree() {};

	node<T>* m_rootNode = nullptr;

	bool insert(const T& a_data) {

		// if this is the first node, create root node (if m_rootNode = nullptr)
		if (!m_rootNode) {
			m_rootNode = new node<T>(a_data);
			return true;
		}

		bool inserted = false;
		node<T>* current_node = m_rootNode;

		while (!inserted) {
			// if data == current node data, return false
			if (a_data == current_node->m_data) {
				return inserted;
			}

			// compare and traverse
			// left node
			else if (a_data < current_node->m_data) {
				if (current_node->m_leftNode) {
					current_node = current_node->m_leftNode;
				}
				else {		// insert at null leaf by creating new node
					current_node->m_leftNode = new node<T>(a_data);
					current_node->m_leftNode->m_parent = current_node;
					inserted = true;
				}
			}
			
			// right node
			else if (a_data > current_node->m_data) {
				if (current_node->m_rightNode) {
					current_node = current_node->m_rightNode;
				}
				else {		// insert at null leaf by creating new node
					current_node->m_rightNode = new node<T>(a_data);
					current_node->m_rightNode->m_parent = current_node;
					inserted = true;
				}
			}
		}
		return false;
	}

	bool find(const T& a_data) {

		// if this is the first node, create root node (if m_rootNode = nullptr)
		if (!m_rootNode) {
			return false;
		}

		bool found = false;
		node<T>* current_node = m_rootNode;
		node<T>* previous_node = nullptr;

		while (!found) {
			// if data == current node data, return false
			if (a_data == current_node->m_data) {
				found = true;
				return found;
			}

			// compare and traverse
			// left node
			else if (a_data < current_node->m_data) {
				if (current_node->m_leftNode) {			// is there a left node?
					previous_node = current_node;
					current_node = current_node->m_leftNode;
				}
				else {		// return found
					return found;
				}
			}

			// right node
			else if (a_data > current_node->m_data) {
				if (current_node->m_rightNode) {		// is there a right node?
					previous_node = current_node;
					current_node = current_node->m_rightNode;
				}
				else {		// return found
					return found;
				}
			}

			// nullptr = 0 which is = to false
			if (!current_node) {
				// we are at valid location, creates new node and constructs it with a_data
				current_node = new node<T>(a_data);
				current_node->m_parent = previous_node;
				found = true;
			}
		}
		return found;
	}

	bool remove(const T& a_data)
	{
		if (!find(a_data))
			return false;

		// Look for location to insert
		bool found = false;
		node<T>* current_node = m_rootNode;

		// Find the data
		while (!found)
		{
			// Compare and traverse
			if (a_data == current_node->m_data)
			{
				// Data already existed
				found = true;
			}
			// Left child check / insert
			else if (a_data < current_node->m_data)
			{
				if (current_node->m_leftNode) // Is there already node?
				{
					current_node = current_node->m_leftNode;
				}
			}

			// Right child check / insert
			else if (a_data > current_node->m_data)
			{
				if (current_node->m_rightNode) // Is there already node?
				{
					current_node = current_node->m_rightNode;
				}
			}
		}

		//If the current node has a right branch, then
		if (current_node->m_rightNode)
		{
			// find the minimum value in the right 
			// branch by iterating down the left branch of the
			// current node’s right child until there are no more left branch nodes
			node<T>* search_node = current_node->m_rightNode;
			while (search_node->m_leftNode)
			{
				search_node = search_node->m_leftNode;
			}
			//copy the value from this minimum node to the current node
			current_node->m_data = search_node->m_data;
			//find the minimum node’s parent node
			//	(the parent of the node you are deleting)
			// search_node->m_parent
			if (search_node == search_node->m_parent->m_leftNode)
			{
				//if you are deleting the parent’s left node
				//	set this left child of the parent to the right 
				//  child of the minimum node
				search_node->m_parent->m_leftNode = search_node->m_rightNode;
				if (search_node->m_rightNode)
					search_node->m_rightNode->m_parent = search_node->m_parent;
				delete search_node;
				search_node = nullptr;
			}
			else if (search_node == search_node->m_parent->m_rightNode)
			{
				//if you are deleting the parent’s right node
				// set the right child of the parent to 
				// the minimum node’s right child
				search_node->m_parent->m_rightNode = search_node->m_rightNode;
				if (search_node->m_rightNode)
					search_node->m_rightNode->m_parent = search_node->m_parent;
				delete search_node;
				search_node = nullptr;
			}
			else
			{
				std::cout << "Massive Error in remove!";
			}

			return true;

		}
		else
		{
			//If we are deleting the root, the root becomes the left child of the current node
			if (current_node == m_rootNode)
			{
				if (m_rootNode->m_leftNode)
				{
					m_rootNode = m_rootNode->m_leftNode;
					m_rootNode->m_parent = nullptr;
				}
				else
				{
					//Last node?
					m_rootNode = nullptr;
				}

			}
			//If the current node has no right branch
			//if we are deleting the parent’s left child,
			//	set the left child of the parent to the left
			// child of the current node
			else if (current_node == current_node->m_parent->m_leftNode)
			{
				if (current_node->m_leftNode) {
					current_node->m_parent->m_leftNode = current_node->m_leftNode;
					current_node->m_leftNode->m_parent = current_node->m_parent;
				}
			}
			//If we are deleting the parent’s right child, set the right child of the parent to the left
			//child of the current node
			else if (current_node == current_node->m_parent->m_rightNode)
			{
				current_node->m_parent->m_rightNode = current_node->m_leftNode;
				current_node->m_leftNode->m_parent = current_node->m_parent;
			}
			delete current_node;
			current_node = nullptr;
			return true;
		}

	}

	void draw(aie::Renderer2D* renderer, node<T>* selected)
	{
		draw(renderer, m_rootNode, 640, 680, 640, selected);
	}

	void draw(aie::Renderer2D* renderer, node<T>* pNode, int x, int y, int horizontalSpacing, node<T>* selected)
	{
		horizontalSpacing /= 2;
		if (pNode) {
			if (pNode->m_leftNode) {
				renderer->setRenderColour(1, 1, 1);
				renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
				draw(renderer, pNode->m_leftNode, x - horizontalSpacing, y - 80, horizontalSpacing, selected);
			}
			if (pNode->m_rightNode) {
				renderer->setRenderColour(1, 1, 1);
				renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
				draw(renderer, pNode->m_rightNode, x + horizontalSpacing, y - 80, horizontalSpacing, selected);
			}
			pNode->draw(renderer, x, y, (selected == pNode));
		}
	}
};