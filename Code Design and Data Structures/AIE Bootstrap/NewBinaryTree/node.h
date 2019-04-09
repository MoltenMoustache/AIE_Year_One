#pragma once
#include "Renderer2D.h"
#include <iostream>

template<typename T>
class node {
public:
	static aie::Font* g_systemFont;
	// construction of node with valid data
	node(const T& a_data) : m_data(a_data) {};

	~node() {};

	// Data member for this node
	T m_data;
	
	// Graph linage
	node<T>* m_parent = nullptr;
	node<T>* m_leftNode = nullptr;
	node<T>* m_rightNode = nullptr;

	void draw(aie::Renderer2D* renderer, int x, int y, bool selected)
	{
		static char buffer[10];
		sprintf(buffer, "%d", m_data);
		renderer->setRenderColour(0.25, 0.5, 1);
		renderer->drawCircle(x, y, 30);
		if (selected == true)
			renderer->setRenderColour(0.25, 0.5, 1);
		else
			renderer->setRenderColour(0, 0, 0);
		renderer->drawCircle(x, y, 28);
		renderer->setRenderColour(1, 1, 1);
		renderer->drawText(g_systemFont, buffer, x - 12, y - 10);
	}
};

aie::Font* node<int>::g_systemFont = nullptr;