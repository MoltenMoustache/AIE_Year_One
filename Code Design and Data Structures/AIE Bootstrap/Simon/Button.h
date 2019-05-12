#include "Renderer2D.h"
#include "Font.h"
#include <Texture.h>

class Button
{
public:
	// 2x Overloaded constructors
	// 1. Constructor for textless button
	// 2. Coloured button with text
	Button(float x, float y, float width, float height);
	Button(const char* buttonText, float x, float y, float width, float height, int a_fontSize, char* a_fontDirectory);
	~Button();

	// 3x Overloaded ->draw() functions
	// 1. Default button coloured button with no text or texture
	// 2. Textured button
	// 3. Coloured button with text
	void draw(aie::Renderer2D* renderer, float r, float g, float b);
	void draw(aie::Renderer2D* renderer, aie::Texture* a_buttonTexture);
	void draw(aie::Renderer2D* renderer, float r, float g, float b, int a_stringLength);
	void draw(aie::Renderer2D* renderer, float r, float g, float b, int a_stringLength, float text_r, float text_g, float text_b);
	bool isPressed();
	bool isHovered();

private:
	//Font and text for the button.
	aie::Font* m_font;
	int m_fontSize;
	char m_buttonText[64];

	//Button's position, width, and height.
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
	
};

