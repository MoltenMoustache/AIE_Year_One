#include "Button.h"
#include <string.h>
#include <Input.h>


Button::Button(float x, float y, float width, float height)
{
	//Store the button's position, width, and height.
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;
}

Button::Button(const char* buttonText, float x, float y, float width, float height)
{
	//Store the text that will appear on the button.
	strcpy_s(m_buttonText, 64, buttonText);

	//Load a font to use to display the text.
	m_font = new aie::Font("./font/consolas.ttf", 24);

	//Store the button's position, width, and height.
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;
}

Button::Button(aie::Texture* a_buttonTexture, float x, float y, float width, float height)
{
	//Store the button's position, width, and height.
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;

	m_buttonTexture = a_buttonTexture;
}


Button::~Button()
{
	delete m_font;
}

void Button::draw(aie::Renderer2D* renderer, float r, float g, float b) {
	//Draw a coloured box for the button background.
	renderer->setRenderColour(r, g, b, 1.0f);

	// if the button has a button sprite, draw it
	// else, default to flat colour box
	/*if (m_buttonTexture != nullptr) {
		renderer->drawSprite(m_buttonTexture, m_posX, m_posY, m_width, m_height, 0, 1);
	}
	else {*/
		renderer->drawBox(m_posX, m_posY, m_width, m_height);
	/*}
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
*/
	if (m_buttonText != "") {
		////Calculating the centred text position is a bit fiddly.
		//float textWidth = m_font->getStringWidth(m_buttonText);
		//float textHeight = m_font->getStringHeight(m_buttonText);
		//float centredPosX = m_posX - (textWidth * 0.5f) + 2;
		//float centredPosY = m_posY - (textHeight * 0.5f) + 5;

		//Draw text on the button.
		//renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);
	}
}

bool Button::update() {
	aie::Input* input = aie::Input::getInstance();
	//Get mouse position
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	//Calculate the 4 sides of the button
	float left = m_posX - (m_width * 0.5f);
	float right = m_posX + (m_width * 0.5f);
	float bottom = m_posY - (m_height * 0.5f);
	float top = m_posY + (m_height * 0.5f);
	//Check if the mouse is inside the box made by the 4 sides.
	if (mouseX > left && mouseX < right &&
		mouseY > bottom && mouseY < top)
	{
		//Return whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	return false;
}
