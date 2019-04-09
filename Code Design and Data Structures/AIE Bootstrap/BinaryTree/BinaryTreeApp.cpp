#include "BinaryTreeApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "binary_tree.h"
#include "node.h"
#include <imgui.h>

binary_tree<int> m_binaryTree;
node<int>* m_selectedNode;

BinaryTreeApp::BinaryTreeApp() {

}

BinaryTreeApp::~BinaryTreeApp() {

}

aie::Font* g_systemFont = nullptr;

bool BinaryTreeApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	g_systemFont = m_font;
	return true;

}

void BinaryTreeApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void BinaryTreeApp::update(float deltaTime) {

	aie::Input* input = aie::Input::getInstance();
	static int value = 0;
	ImGui::InputInt("Value", &value);
	if (ImGui::Button("Insert", ImVec2(50, 0)))
	{
		m_binaryTree.insert(value);
		m_selectedNode = m_binaryTree.find(value);
	}
	if (ImGui::Button("Remove", ImVec2(50, 0)))
	{
		m_binaryTree.remove(value);
	}
	if (ImGui::Button("Find", ImVec2(50, 0)))
	{
		m_selectedNode = m_binaryTree.find(value);
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

}

void BinaryTreeApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_binaryTree.draw(m_2dRenderer, m_selectedNode);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}