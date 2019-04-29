#include "Projectile.h"
#include "Input.h"
#include "Texture.h"


Projectile::Projectile(float posX, float posY)
{
	positionX = posX;
	positionY = posY;
	m_shipTexture = new aie::Texture("../bin/textures/ship.png");
}


Projectile::~Projectile()
{
}

void Projectile::update(float deltaTime) {
	positionY += 500.0f * deltaTime;
	rotation = 0;
}

void Projectile::draw(aie::Renderer2D*	m_2dRenderer) {

	//position and draw the ship
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->drawSprite(m_shipTexture, positionX, positionY, 0, 0, rotation, 1);
}
