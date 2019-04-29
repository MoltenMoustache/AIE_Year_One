#include "SimonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include "Stack.h"
#include <string>
#include <ctime>
#include <thread>

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
	m_redButton = new Button("Red", 355, 250, 120, 120);
	m_blueButton = new Button("Blue", 355, 120, 120, 120);
	m_greenButton = new Button("Green", 225, 250, 120, 120);
	m_yellowButton = new Button("Yellow", 225, 120, 120, 120);

	m_resetButton = new Button("Restart", 75, 465, 120, 50);

	flashTimer = new FunctionTimer(1.5f);

	srand(time(nullptr));
	selectColour();
	return true;
}

void SimonApp::shutdown() {

	delete m_redButton;
	delete m_blueButton;
	delete m_greenButton;
	delete m_yellowButton;
	delete m_resetButton;

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

	// red button is pressed,
	// check if button pressed was the same colour as the current indexed colour
	// if so, add colour to input stack and increment index
	// if no, reset game
	if (m_redButton->update()) {
		if (simonColours[index] == Colour::Red) {
			Colour red = Colour::Red;
			inputColours.push(red);
			index++;
		}
		else {
			ResetGame();
		}
	}

	if (m_blueButton->update()) {
		if (simonColours[index] == Colour::Blue) {
			Colour blue = Colour::Blue;
			inputColours.push(blue);
			index++;
		}
		else {
			ResetGame();
		}
	}

	if (m_greenButton->update()) {
		if (simonColours[index] == Colour::Green) {
			Colour green = Colour::Green;
			inputColours.push(green);
			index++;
		}
		else {
			ResetGame();
		}
	}

	if (m_yellowButton->update()) {
		if (simonColours[index] == Colour::Yellow) {
			Colour yellow = Colour::Yellow;
			inputColours.push(yellow);
			index++;
		}
		else {
			ResetGame();
		}
	}

	// if reset button is pressed,
	if (m_resetButton->update()) {
		// clear both stacks and reset index to 0
		ResetGame();
	}

	if (flashTimer->m_currTime > 0) {
		flashTimer->update(deltaTime);
	}
}

void SimonApp::ResetGame() {
	simonColours.clear();
	inputColours.clear();
	index = 0;
}

void SimonApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// char arrays for storing colour names
	// REMOVE with implementation of third party textures
	char redArray[] = "RED";
	char bluArray[] = "BLUE";
	char greArray[] = "GREEN";
	char yelArray[] = "YELLOW";

	// button GUI's
	m_blueButton->draw(m_2dRenderer, 0.0f, 0.0f, 1.0f);
	m_greenButton->draw(m_2dRenderer, 0.0f, 1.0f, 0.0f);
	m_yellowButton->draw(m_2dRenderer, 1.0f, 1.0f, 0.0f);

	m_resetButton->draw(m_2dRenderer, 1.0f, 1.0f, 0.0f);
	
	float yPos = 30;

	for (size_t i = 0; i < simonColours.size(); i++)
	{
		if (simonColours[i] == Colour::Red){
			
		}
	}

	int counter = 5;
	_sleep(1000);
	while (counter >= 1)
	{
		_sleep(1000);
		counter--;
	}

	for (size_t i = 0; i < simonColours.size(); i++)
	{
		if (!simonColours.isEmpty())
		{
			// gets current colour in stack and display the text
			switch (simonColours[i]) {
			case Colour::Red:
				/*m_2dRenderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);
				m_2dRenderer->drawText(m_font, redArray, 20, yPos);
				m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);*/

				m_redButton->draw(m_2dRenderer, 1.0f, 0.0f, 0.0f);
				_sleep(2);
				m_redButton->draw(m_2dRenderer, 1.0f, 1.0f, 1.0f);
				break;
			case Colour::Blue:
				m_2dRenderer->setRenderColour(0.0f, 0.0f, 1.0f, 1.0f);
				m_2dRenderer->drawText(m_font, bluArray, 20, yPos);
				m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
				break;
			case Colour::Green:
				m_2dRenderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
				m_2dRenderer->drawText(m_font, greArray, 20, yPos);
				m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
				break;
			case Colour::Yellow:
				m_2dRenderer->setRenderColour(1.0f, 1.0f, 0.0f, 1.0f);
				m_2dRenderer->drawText(m_font, yelArray, 20, yPos);
				m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
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