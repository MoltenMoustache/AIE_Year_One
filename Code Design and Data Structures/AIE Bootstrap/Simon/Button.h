#include "Renderer2D.h"
#include "Font.h"
#include <Texture.h>

class Button
{
public:
	// Overloaded constructors for buttons w/ text & buttons w/ sprites
	Button(aie::Texture* a_buttonTexture, float x, float y, float width, float height);
	Button(float x, float y, float width, float height);
	Button(const char* buttonText, float x, float y, float width, float height);
	~Button();

	void draw(aie::Renderer2D* renderer, float r, float g, float b);
	bool update();

private:
	// button sprite
	aie::Texture* m_buttonTexture;

	//Font and text for the button.
	aie::Font* m_font;
	char m_buttonText[64];

	//Button's position, width, and height.
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
	
};

