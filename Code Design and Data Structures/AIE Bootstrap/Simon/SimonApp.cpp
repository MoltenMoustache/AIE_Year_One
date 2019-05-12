#include "SimonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include <string>
#include <ctime>
#include <thread>
#include <cstdio>

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

	// Buttons
	m_resetButton = new Button("CLEAR", 75, 465, 120, 50, 42, m_defaultFontDirectory);
	m_playButton = new Button("PLAY", 360, 250, 175, 100, 50, m_defaultFontDirectory);
	m_exitButton = new Button("EXIT", 360, 135, 175, 100, 50, m_defaultFontDirectory);
	m_redButton = new Button(425, 270, 120, 120);
	m_blueButton = new Button(425, 140, 120, 120);
	m_greenButton = new Button(295, 270, 120, 120);
	m_yellowButton = new Button(295, 140, 120, 120);

	// ON Button textures
	m_redON = new aie::Texture("../bin/textures/RedON.png");
	m_blueON = new aie::Texture("../bin/textures/BlueON.png");
	m_greenON = new aie::Texture("../bin/textures/GreenON.png");
	m_yellowON = new aie::Texture("../bin/textures/YellowON.png");

	// OFF Button textures
	m_redOFF = new aie::Texture("../bin/textures/RedOFF.png");
	m_blueOFF = new aie::Texture("../bin/textures/BlueOFF.png");
	m_greenOFF = new aie::Texture("../bin/textures/GreenOFF.png");
	m_yellowOFF = new aie::Texture("../bin/textures/YellowOFF.png");

	// HOVER Button textures
	m_redHover = new aie::Texture("../bin/textures/RedHover.png");
	m_blueHover = new aie::Texture("../bin/textures/BlueHover.png");
	m_greenHover = new aie::Texture("../bin/textures/GreenHover.png");
	m_yellowHover = new aie::Texture("../bin/textures/YellowHover.png");

	// Timers
	m_flashTime = new FunctionTimer(1.5f);
	m_flashCooldown = new FunctionTimer(0.5f);
	m_flashCooldown->m_currTime = 0.0f;

	srand(time(nullptr));

	m_currentState = GameState::MENU;
	m_displayIndex = 0;

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

	delete m_redHover;
	delete m_blueHover;
	delete m_greenHover;
	delete m_yellowHover;
}

void SimonApp::selectColour() {
	// selects a random colour and adds it to the simoncolours stack
	Colour newColour = Colour(rand() % 4);
	simonColours.push(newColour);

	// resets display index to begin flash sequence from the start
	m_displayIndex = 0;

	// sets flash cooldown to 0.15 seconds so the colour is displayed almost instantly
	m_flashCooldown->m_currTime = 0.15f;
	// resets flash timer
	m_flashTime->reset();

	// increments score counter
	m_scoreCounter++;
}

void SimonApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();


	if (m_currentState == GameState::PLAY)
	{
		// go to main menu
		if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		{
			m_currentState = GameState::MENU;
			ResetGame();
		}

		// if they have reached the end of the colour stack
		if (m_index == simonColours.size()) {
			// resets index
			m_index = 0;

			// selects new colour
			selectColour();

			// disables interaction [USELESS?]
			m_canInteract = false;
		}

		if (m_canInteract)
		{
			// if button is pressed
			if (m_redButton->isPressed()) {

				// check if the current colour on the stack is the same as the colour of the button pressed
				if (simonColours[m_index] == Colour::Red) {
					// increments index
					m_index++;
				}
				else {
					ResetGame();
				}
			}

			// if button is pressed
			if (m_blueButton->isPressed()) {

				// check if the current colour on the stack is the same as the colour of the button pressed
				if (simonColours[m_index] == Colour::Blue) {
					// increments index
					m_index++;
				}
				else {
					ResetGame();
				}
			}

			// if button is pressed
			if (m_greenButton->isPressed()) {

				// check if the current colour on the stack is the same as the colour of the button pressed
				if (simonColours[m_index] == Colour::Green) {
					// increments index
					m_index++;
				}
				else {
					ResetGame();
				}
			}

			// if button is pressed
			if (m_yellowButton->isPressed()) {

				// check if the current colour on the stack is the same as the colour of the button pressed
				if (simonColours[m_index] == Colour::Yellow) {
					// increments index
					m_index++;
				}
				else {
					ResetGame();
				}
			}
		}

		// if reset button is pressed,
		if (m_resetButton->isPressed()) {
			ResetGame();
		}

		// updates timers
		m_flashTime->update(deltaTime);
		m_flashCooldown->update(deltaTime);
	}

	if (m_currentState == GameState::MENU)
	{

		if (m_playButton->isPressed())
		{
			m_currentState = GameState::PLAY;
			ResetGame();
		}

		if (m_exitButton->isPressed())
		{
			quit();
		}

	}

}

void SimonApp::ResetGame() {
	// clears colour stack
	simonColours.clear();

	// resets index
	m_index = 0;

	// resets flash timer
	m_flashTime->reset();
	// sets flash cooldown to 0.15 seconds so the colour is displayed almost instantly
	m_flashCooldown->m_currTime = 0.15f;

	// resets score counter
	m_scoreCounter = -1;
}

void SimonApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Simple State Machine, 
	// If Game has started
	if (m_currentState == GameState::PLAY) {

		// button GUI's
		m_resetButton->draw(m_2dRenderer, 1.0f, 1.0f, 1.0f, 5);

		// sets all buttons default to OFF texture
		m_redButton->draw(m_2dRenderer, m_redOFF);
		m_blueButton->draw(m_2dRenderer, m_blueOFF);
		m_greenButton->draw(m_2dRenderer, m_greenOFF);
		m_yellowButton->draw(m_2dRenderer, m_yellowOFF);

		// if the last button flashed 0.5 seconds ago and the index is within the range of the colour stack
		if (m_flashCooldown->m_currTime <= 0 && m_displayIndex < simonColours.size()) {

			// disable interaction
			m_canInteract = false;

			// checks enum of indexed colour in stack
			switch (simonColours[m_displayIndex])
			{
			case Colour::Red:
				// changes the button texture to the ON texture
				m_redButton->draw(m_2dRenderer, m_redON);
				break;
			case Colour::Blue:
				// changes the button texture to the ON texture
				m_blueButton->draw(m_2dRenderer, m_blueON);
				break;
			case Colour::Green:
				// changes the button texture to the ON texture
				m_greenButton->draw(m_2dRenderer, m_greenON);
				break;
			case Colour::Yellow:
				// changes the button texture to the ON texture
				m_yellowButton->draw(m_2dRenderer, m_yellowON);
				break;
			default:
				// Error checking
				std::cout << "ERROR: Colour out of range.\n";
				system("pause");
				break;
			}

		}

		// if the flash timer is over (button has flashed for 1.5 seconds)
		if (m_flashTime->m_currTime <= 0)
		{
			// if this is the last colour in the sequence, enable interaction
			if (m_displayIndex > simonColours.size() - 2)
				m_canInteract = true;

			// if there are still colours in the sequence
			if (m_displayIndex < simonColours.size())
			{
				// increment display index
				m_displayIndex++;
				// reset the flash timer
				m_flashCooldown->reset();
			}
			// ELSE
			else
			{
				// set display index to ridiculous number (higher than simonColours.size().
				m_displayIndex = 100;
			}
			// reset flash timer
			m_flashTime->reset();
		}

		// if interaction is allowed
		if (m_canInteract) {

			// if a button is hovered over
			if (m_redButton->isHovered()) {
				// change button texture to the Hover texture
				m_redButton->draw(m_2dRenderer, m_redHover);
			}

			// if a button is hovered over
			if (m_blueButton->isHovered()) {
				// change button texture to the Hover texture
				m_blueButton->draw(m_2dRenderer, m_blueHover);
			}

			// if a button is hovered over
			if (m_greenButton->isHovered()) {
				// change button texture to the Hover texture
				m_greenButton->draw(m_2dRenderer, m_greenHover);
			}

			// if a button is hovered over
			if (m_yellowButton->isHovered()) {
				// change button texture to the Hover texture
				m_yellowButton->draw(m_2dRenderer, m_yellowHover);
			}
		}

		m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
		m_2dRenderer->drawText(m_font, "Press ESC to go to Main Menu.", 5, 5);

		// Score counter
		char displayPtr[80] = { 0 };
		std::sprintf(displayPtr, "%d", m_scoreCounter);

		m_2dRenderer->drawText(m_font, displayPtr, 353, 197);
	}

	// If the game is in the menu
	if (m_currentState == GameState::MENU) {
		m_playButton->draw(m_2dRenderer, 1.0f, 0.0f, 0.0f, 4, 1.0f, 1.0f, 1.0f);
		m_exitButton->draw(m_2dRenderer, 0.0f, 1.0f, 0.0f, 4, 1.0f, 1.0f, 1.0f);

		if (m_playButton->isHovered()) {
			m_playButton->draw(m_2dRenderer, 0.75f, 0.1f, 0.1f, 4, 1.0f, 1.0f, 1.0f);
		}

		if (m_exitButton->isHovered()) {
			m_exitButton->draw(m_2dRenderer, 0.1f, 0.75f, 0.1f, 4, 1.0f, 1.0f, 1.0f);
		}
	}


	// TITLE
	m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	m_2dRenderer->drawText(m_titleFont, "SIMEON", 245, 425);


	m_2dRenderer->end();
}