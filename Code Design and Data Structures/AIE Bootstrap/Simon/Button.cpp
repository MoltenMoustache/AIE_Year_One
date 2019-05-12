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

	// initialize as null pointer
	m_buttonText[0] = '\0';
	m_font = nullptr;
}

Button::Button(const char* buttonText, float x, float y, float width, float height, int a_fontSize, char* a_fontDirectory)
{
	//Store the text that will appear on the button.
	strcpy_s(m_buttonText, 64, buttonText);

	//Load a font to use to display the text.
	m_fontSize = a_fontSize;
	m_font = new aie::Font(a_fontDirectory, m_fontSize);

	//Store the button's position, width, and height.
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;
}


Button::~Button()
{
	if(m_font != nullptr)
		delete m_font;

}

// overload function to pass in string length
// as well as another overloaded function for textured button
void Button::draw(aie::Renderer2D* renderer, float r, float g, float b)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(r, g, b, 1.0f);
	// Draw Button box	
	renderer->drawBox(m_posX, m_posY, m_width, m_height);

	renderer->setRenderColour(0.0f, 0.0f, 0.0f, 1.0f);
}

void Button::draw(aie::Renderer2D* renderer, float r, float g, float b, int a_stringLength)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(r, g, b, 1.0f);

	// if the button has a button sprite, draw it
	// else, default to flat colour box
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(0.0f, 0.0f, 0.0f, 1.0f);

	// if text is not null
	if (m_buttonText[0] != '\0')
	{
		//Calculating the centred text position is a bit fiddly.
		// text Width is calculated by the the length of the string, divided by 2
		// minus 0.25 and then finally multiplied by the font size
		float textWidth = ((a_stringLength / 2.0f) - 0.25f) * m_fontSize;

		// text Height is the font size.
		float textHeight = m_fontSize - 1.0f;

		float centredPosX = m_posX - (textWidth * 0.5f) + 4;
		float centredPosY = m_posY - (textHeight * 0.5f) + 10;

		//Draw text on the button.
		renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);
	}
}

void Button::draw(aie::Renderer2D* renderer, float r, float g, float b, int a_stringLength, float text_r, float text_g, float text_b)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(r, g, b, 1.0f);

	// if the button has a button sprite, draw it
	// else, default to flat colour box
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(0.0f, 0.0f, 0.0f, 1.0f);

	// if text is not null
	if (m_buttonText[0] != '\0')
	{
		//Calculating the centred text position is a bit fiddly.
		// text Width is calculated by the the length of the string, divided by 2
		// minus 0.25 and then finally multiplied by the font size
		float textWidth = ((a_stringLength / 2.0f) - 0.25f) * m_fontSize;

		// text Height is the font size.
		float textHeight = m_fontSize - 1.0f;

		float centredPosX = m_posX - (textWidth * 0.5f) + 4;
		float centredPosY = m_posY - (textHeight * 0.5f) + 10;

		//Draw text on the button.
		renderer->setRenderColour(text_r, text_g, text_b);
		renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);
		renderer->setRenderColour(1.0f, 1.0f, 1.0f);
	}
}

void Button::draw(aie::Renderer2D* renderer, aie::Texture* a_buttonTexture)
{
	// Set the render colour to White
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	// draw the button sprite
	renderer->drawSprite(a_buttonTexture, m_posX, m_posY, m_width, m_height, 0, 1);
}

// Mouse and Button collision
bool Button::isPressed()
{
	aie::Input* input = aie::Input::getInstance();

	//Get mouse position X and Y
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	//Calculate the 4 sides of the button
	float top = m_posY + (m_height * 0.5f);
	float bottom = m_posY - (m_height * 0.5f);
	float left = m_posX - (m_width * 0.5f);
	float right = m_posX + (m_width * 0.5f);
	//Check if the mouse is inside the box made by the 4 sides.
	if (mouseX > left && mouseX < right &&		// if the mouse is in between the left and right sides of the button
		mouseY > bottom && mouseY < top)		// if the mouse is also between the top and bottom of the button
	{
		//Return whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	return false;
}

bool Button::isHovered()
{
	aie::Input* input = aie::Input::getInstance();

	//Get mouse position X and Y
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	//Calculate the 4 sides of the button
	float top = m_posY + (m_height * 0.5f);
	float bottom = m_posY - (m_height * 0.5f);
	float left = m_posX - (m_width * 0.5f);
	float right = m_posX + (m_width * 0.5f);
	//Check if the mouse is inside the box made by the 4 sides.
	if (mouseX > left && mouseX < right &&		// if the mouse is in between the left and right sides of the button
		mouseY > bottom && mouseY < top &&
		!input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))		// if the mouse is also between the top and bottom of the button
	{
		//Return whether the mouse is within the position
		return true;
	}
	return false;
}
