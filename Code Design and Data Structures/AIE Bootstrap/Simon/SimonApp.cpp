#include "SimonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include "Stack.h"
#include <string>
#include <ctime>

Stack<Colour> simonColours;
Stack<Colour> inputColours;
int index = 0;

SimonApp::SimonApp() {

}

SimonApp::~SimonApp() {

}

bool SimonApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	srand(time(nullptr));
	selectColour();
	return true;
}

void SimonApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void SimonApp::selectColour() {
		Colour newColour = Colour(rand() % 4);
		simonColours.push(newColour);
		inputColours.clear();
}

void SimonApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// RED
	if (ImGui::Button("Red", ImVec2(40, 0))) {
		if (simonColours[index] == Colour::Red) {
			Colour red = Colour::Red;
			inputColours.push(red);
			index++;
		}
		else {
			// ~~ ADD IN CLEAR() FUNCTIONS TO STACK ~~		[DONE]
			inputColours.clear();
			simonColours.clear();
			quit();
		}
	}

	// BLUE
	if (ImGui::Button("Blue", ImVec2(50, 0))) {
		if (simonColours[index] == Colour::Blue) {
			Colour blue = Colour::Blue;
			inputColours.push(blue);
			index++;
		}
		else {
			// ~~ ADD IN CLEAR() FUNCTIONS TO STACK ~~		[DONE]
			inputColours.clear();
			simonColours.clear();
			quit();
		}
	}

	// GREEN
	if (ImGui::Button("Green", ImVec2(40, 0))) {
		if (simonColours[index] == Colour::Green) {
			Colour green = Colour::Green;
			inputColours.push(green);
			index++;
		}
		else {
			// ~~ ADD IN CLEAR() FUNCTIONS TO STACK ~~		[DONE]
			inputColours.clear();
			simonColours.clear();
			quit();
		}
	}

	// YELLOW
	if (ImGui::Button("Yellow", ImVec2(40, 0))) {
		if (simonColours[index] == Colour::Yellow) {
			Colour yellow = Colour::Yellow;
			inputColours.push(yellow);
			index++;
		}
		else {
			// ~~ ADD IN CLEAR() FUNCTIONS TO STACK ~~		[DONE]
			inputColours.clear();
			simonColours.clear();
			quit();
		}
	}

	// if index == simonColours.size()
	// clear input
	// reset index
	// selectColour()
	if (index == simonColours.size()) {
		inputColours.clear();
		index = 0;
		selectColour();
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void SimonApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	char redArray[] = "RED";
	char bluArray[] = "BLUE";
	char greArray[] = "GREEN";
	char yelArray[] = "YELLOW";

		float yPos = 30;
	for (size_t i = 0; i < simonColours.size(); i++)
	{
		if (!simonColours.isEmpty())
		{
			switch (simonColours[i]) {
			case Colour::Red:
				m_2dRenderer->drawText(m_font, redArray, 20, yPos);
				break;
			case Colour::Blue:
				m_2dRenderer->drawText(m_font, bluArray, 20, yPos);
				break;
			case Colour::Green:
				m_2dRenderer->drawText(m_font, greArray, 20, yPos);
				break;
			case Colour::Yellow:
				m_2dRenderer->drawText(m_font, yelArray, 20, yPos);
				break;
			}
		}
		yPos += 30;
	}
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}