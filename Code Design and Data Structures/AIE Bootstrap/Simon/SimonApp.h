#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"
#include "FunctionTimer.h"
#include "Stack.h"

class SimonApp : public aie::Application {
public:

	SimonApp();
	virtual ~SimonApp();

	virtual bool startup();
	virtual void shutdown();

	// button declarations
	Button* m_redButton;
	Button* m_blueButton;
	Button* m_greenButton;
	Button* m_yellowButton;
	Button* m_resetButton;

	Button* m_playButton;
	Button* m_exitButton;

	FunctionTimer* m_flashTime;
	FunctionTimer* m_flashCooldown;

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Font*			m_titleFont;
	char m_defaultFontDirectory[50] = "../bin/font/pricedown.ttf";

	// Lit button textures
	aie::Texture* m_redON;
	aie::Texture* m_blueON;
	aie::Texture* m_greenON;
	aie::Texture* m_yellowON;

	// Button textures
	aie::Texture* m_redOFF;
	aie::Texture* m_blueOFF;
	aie::Texture* m_greenOFF;
	aie::Texture* m_yellowOFF;
	
	// Hovered over button textures
	aie::Texture* m_redHover;
	aie::Texture* m_blueHover;
	aie::Texture* m_greenHover;
	aie::Texture* m_yellowHover;

	void selectColour();
	void ResetGame();

	int m_scoreCounter = -1;
	int m_displayIndex = 0;
	char m_displayScore;

	bool m_canInteract;

	// Main game stack
	Stack<Colour> simonColours;
	int m_index = 0;

	enum GameState {
		MENU,
		PLAY,
	};

	GameState m_currentState;
};