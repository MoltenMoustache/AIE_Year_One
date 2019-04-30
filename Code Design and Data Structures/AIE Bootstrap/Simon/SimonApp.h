#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"
#include "FunctionTimer.h"

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

	FunctionTimer* m_flashTime;
	FunctionTimer* m_flashCooldown;

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Font*			m_titleFont;
	char m_defaultFontDirectory[50] = "../bin/font/pricedown.ttf";
	aie::Texture* m_redON;
	aie::Texture* m_blueON;
	aie::Texture* m_greenON;
	aie::Texture* m_yellowON;
	aie::Texture* m_redOFF;
	aie::Texture* m_blueOFF;
	aie::Texture* m_greenOFF;
	aie::Texture* m_yellowOFF;

	void selectColour();
	void ResetGame();

	int m_scoreCounter = -1;
	int m_displayIndex = 0;
};