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

	FunctionTimer* flashTimer;

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	void selectColour();
	void ResetGame();

	int m_scoreCounter;
};