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
	m_font = new aie::Font("../bin/font/pricedown.ttf", 32);
	m_titleFont = new aie::Font("../bin/font/pricedown.ttf", 90);

	m_resetButton = new Button("CLEAR", 75, 465, 120, 50, 42, m_defaultFontDirectory);

	m_redON = new aie::Texture("../bin/textures/RedON.png");
	m_blueON = new aie::Texture("../bin/textures/BlueON.png");
	m_greenON = new aie::Texture("../bin/textures/GreenON.png");
	m_yellowON = new aie::Texture("../bin/textures/YellowON.png");
	
	m_redOFF = new aie::Texture("../bin/textures/RedOFF.png");
	m_blueOFF = new aie::Texture("../bin/textures/BlueOFF.png");
	m_greenOFF = new aie::Texture("../bin/textures/GreenOFF.png");
	m_yellowOFF = new aie::Texture("../bin/textures/YellowOFF.png");

	m_redButton = new Button(m_redON, m_redOFF, 355, 250, 120, 120);
	m_blueButton = new Button(m_blueON, m_blueOFF, 355, 120, 120, 120);
	m_greenButton = new Button(m_greenON, m_greenOFF, 225, 250, 120, 120);
	m_yellowButton = new Button(m_yellowON, m_yellowOFF, 225, 120, 120, 120);

	m_flashTime = new FunctionTimer(1.5f);
	m_flashCooldown = new FunctionTimer(0.5f);
	m_flashCooldown->m_currTime = 0.0f;

	srand(time(nullptr));
	selectColour();
	return true;
}

void SimonApp::shutdown() {

	// BUTTON DE-ALLOCATION
	delete m_redButton;
	delete m_blueButton;
	delete m_greenButton;
	delete m_yellowButton;
	delete m_resetButton;

	// TIMER DE-ALLOCATION
	delete m_flashTime;
	delete m_flashCooldown;

	// FONT DE-ALLOCATION
	delete m_font;
	delete m_titleFont;

	delete m_2dRenderer;

	// TEXTURE DE-ALLOCATION
	delete m_redON;
	delete m_blueON;
	delete m_greenON;
	delete m_yellowON;

	delete m_redOFF;
	delete m_blueOFF;
	delete m_greenOFF;
	delete m_yellowOFF;
}

void SimonApp::selectColour() {
	Colour newColour = Colour(rand() % 4);
	simonColours.push(newColour);
	inputColours.clear();
	m_displayIndex = 0;
	m_flashCooldown->m_currTime = 0.0f;
	m_flashTime->reset();
	m_scoreCounter++;
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
	if (m_redButton->isPressed()) {
		if (simonColours[index] == Colour::Red) {
			Colour red = Colour::Red;
			inputColours.push(red);
			index++;
		}
		else {
			ResetGame();
		}
	}

	if (m_blueButton->isPressed()) {
		if (simonColours[index] == Colour::Blue) {
			Colour blue = Colour::Blue;
			inputColours.push(blue);
			index++;
		}
		else {
			ResetGame();
		}
	}

	if (m_greenButton->isPressed()) {
		if (simonColours[index] == Colour::Green) {
			Colour green = Colour::Green;
			inputColours.push(green);
			index++;
		}
		else {
			ResetGame();
		}
	}

	if (m_yellowButton->isPressed()) {
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
	if (m_resetButton->isPressed()) {
		// clear both stacks and reset index to 0
		ResetGame();
	}

	m_flashTime->update(deltaTime);

	m_flashCooldown->update(deltaTime);
}

void SimonApp::ResetGame() {
	simonColours.clear();
	inputColours.clear();
	index = 0;
	m_flashTime->reset();
	m_flashCooldown->m_currTime = 0.0f;
	m_scoreCounter = -1;
}

void SimonApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// button GUI's
	m_resetButton->draw(m_2dRenderer, 1.0f, 1.0f, 1.0f, 5);

	m_redButton->draw(m_2dRenderer, false);
	m_blueButton->draw(m_2dRenderer, false);
	m_greenButton->draw(m_2dRenderer, false);
	m_yellowButton->draw(m_2dRenderer, false);

	if (m_flashCooldown->m_currTime <= 0 && m_displayIndex < simonColours.size()) {

		switch (simonColours[m_displayIndex])
		{
		case Colour::Red:

			m_redButton->draw(m_2dRenderer, true);

			m_blueButton->draw(m_2dRenderer, false);
			m_greenButton->draw(m_2dRenderer, false);
			m_yellowButton->draw(m_2dRenderer, false);

			break;
		case Colour::Blue:

			m_blueButton->draw(m_2dRenderer, true);

			m_redButton->draw(m_2dRenderer, false);
			m_greenButton->draw(m_2dRenderer, false);
			m_yellowButton->draw(m_2dRenderer, false);
			break;
		case Colour::Green:

			m_greenButton->draw(m_2dRenderer, true);

			m_redButton->draw(m_2dRenderer, false);
			m_blueButton->draw(m_2dRenderer, false);
			m_yellowButton->draw(m_2dRenderer, false);
			break;
		case Colour::Yellow:

			m_yellowButton->draw(m_2dRenderer, true);

			m_redButton->draw(m_2dRenderer, false);
			m_blueButton->draw(m_2dRenderer, false);
			m_greenButton->draw(m_2dRenderer, false);
			break;
		}
	}

	if (m_flashTime->m_currTime <= 0)
	{
		if (m_displayIndex < simonColours.size())
		{
			m_displayIndex++;
			m_flashCooldown->reset();
		}
		else
		{
			m_displayIndex = 100;
		}
		m_flashTime->reset();
	}

	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 5, 5);
	m_2dRenderer->drawText(m_titleFont, "SIMEON", 250, 425);


	// FIX SCORE COUNTER DRAWTEXT()

	/*char m_displayCounter[3];
	itoa(m_scoreCounter, m_displayCounter, 3);

	if (m_scoreCounter >= 0) {
		m_2dRenderer->drawText(m_font, m_displayCounter, 5, 50);
	}*/

	// done drawing sprites
	m_2dRenderer->end();
}