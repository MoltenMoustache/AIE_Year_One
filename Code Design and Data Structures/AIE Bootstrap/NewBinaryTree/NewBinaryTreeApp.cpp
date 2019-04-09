#include "NewBinaryTreeApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>

NewBinaryTreeApp::NewBinaryTreeApp() {
	m_binaryTree.insert(54);
	m_binaryTree.insert(17);
	m_binaryTree.insert(98);
	m_binaryTree.insert(105);
	m_binaryTree.insert(75);
	m_binaryTree.insert(9);
}

NewBinaryTreeApp::~NewBinaryTreeApp() {

}

bool NewBinaryTreeApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	node<int>::g_systemFont = new aie::Font("../bin/font/consolas.ttf", 25);

	return true;
}

void NewBinaryTreeApp::shutdown() {

	delete node<int>::g_systemFont;
	delete m_font;
	delete m_2dRenderer;
}

void NewBinaryTreeApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);
	if (ImGui::Button("Insert", ImVec2(50, 0)))
	{
		m_binaryTree.insert(value);
	}
	if (ImGui::Button("Remove", ImVec2(50, 0)))
	{
		m_binaryTree.remove(value);
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void NewBinaryTreeApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_binaryTree.draw(m_2dRenderer, m_selectedNode);
	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}