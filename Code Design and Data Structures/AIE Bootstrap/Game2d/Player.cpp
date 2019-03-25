#include "Player.h"
#include "Input.h"
#include "Texture.h"


Player::Player()
{
	m_shipTexture = new aie::Texture("../bin/textures/ship.png");
}


Player::~Player()
{
}

void Player::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_UP)) {
		positionY += 500.0f * deltaTime;
		rotation = 0;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN)) {
		positionY -= 500.0f * deltaTime;
		rotation = PI;
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT)) {
		positionX -= 500.0f * deltaTime;
		rotation = PI / 2;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT)) {
		positionX += 500.0f * deltaTime;
		rotation = -PI / 2;
	}

	if (input->isKeyDown(aie::INPUT_KEY_F)) {
		ammunition--;
		if (ammunition == 0) {

		}
	}


}

void Player::draw(aie::Renderer2D*	m_2dRenderer) {

	//position and draw the ship
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->drawSprite(m_shipTexture, positionX, positionY, 0, 0, rotation, 1);
}
