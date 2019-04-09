#pragma once

#include "Application.h"
#include "Renderer2D.h"

class SimonApp : public aie::Application {
public:

	SimonApp();
	virtual ~SimonApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	virtual void selectColour();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};