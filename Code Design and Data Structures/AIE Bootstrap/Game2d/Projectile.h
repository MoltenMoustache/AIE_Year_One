#include "Renderer2D.h"
#include "Font.h"
#include "Application.h"

class Projectile
{
public:
	Projectile(float posX, float posY);
	~Projectile();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

protected:
	aie::Texture* m_shipTexture;
	float positionX = 600;
	float positionY = 400;
	float rotation = 0; //radians

};

