#include "Renderer2D.h"
#include "Font.h"
#include "Application.h"
#include "Projectile.h"

class Player
{
public:
	aie::Font* g_systemFont;

	Player();

	~Player();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

	int ammunition;
	Projectile* bullet;

protected:
	aie::Texture* m_shipTexture;
	float positionX = 600;
	float positionY = 400;
	float rotation = 0; //radians
	float PI = 3.14159;
	int maxAmmunition = 10;
};

