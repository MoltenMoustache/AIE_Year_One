#include "Player.h"
#include "Input.h"
#include "Texture.h"


Player::Player()
{
	m_shipTexture = new aie::Texture("../bin/textures/ship.png");
	g_systemFont = new aie::Font("../bin/font/consolas.ttf", 32);
	ammunition = maxAmmunition;
	bullet = new Projectile(positionX, positionY);
}


Player::~Player()
{
	delete g_systemFont;
}

void Player::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_W)) {
		positionY += 500.0f * deltaTime;
		rotation = 0;
	}

	if (input->isKeyDown(aie::INPUT_KEY_S)) {
		positionY -= 500.0f * deltaTime;
		rotation = PI;
	}

	if (input->isKeyDown(aie::INPUT_KEY_A)) {
		positionX -= 500.0f * deltaTime;
		rotation = PI / 2;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D)) {
		positionX += 500.0f * deltaTime;
		rotation = -PI / 2;
	}

	if (input->isKeyDown(aie::INPUT_KEY_F)) {
		if (ammunition > 0) {
			ammunition--;
			bullet = new Projectile(positionX, positionY);
		}
	}

	if (input->isKeyDown(aie::INPUT_KEY_R)) {
		ammunition = maxAmmunition;
	}


}

void Player::draw(aie::Renderer2D*	m_2dRenderer) {

	//position and draw the ship
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->drawSprite(m_shipTexture, positionX, positionY, 0, 0, rotation, 1);
	std::string str = std::to_string(ammunition);
	char *cstr = &str[0u];
	m_2dRenderer->drawText(g_systemFont, cstr, 100, 100);
}
