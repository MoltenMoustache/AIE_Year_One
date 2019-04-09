#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "binary_tree.h"

class NewBinaryTreeApp : public aie::Application {
public:

	NewBinaryTreeApp();
	virtual ~NewBinaryTreeApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	binary_tree<int>	m_binaryTree;
	node<int>*			m_selectedNode;
};