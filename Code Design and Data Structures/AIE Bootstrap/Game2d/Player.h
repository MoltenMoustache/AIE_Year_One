#include "Renderer2D.h"

class Player
{
public:
	Player();

	~Player();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);


protected:
	aie::Texture* m_shipTexture;
	float positionX = 600;
	float positionY = 400;
	float rotation = 0; //radians
	float PI = 3.14159;
	int ammunition = 10;
};

