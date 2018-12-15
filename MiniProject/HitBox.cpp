#include "HitBox.h"
#include "InputHandler.h"
#include<SDL.h>

HitBox::HitBox(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	isJumping = false;
	isTop = false;
	originY = pParams->getY();
}
void HitBox::Draw()
{
	SDLGameObject::Draw();
}

void HitBox::Update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));

	if (isJumping)
	{

		if (!isTop && m_position.getY() > originY - 100)
		{
			m_velocity.setY(-5);
			//player_dRect.y -= 2;
		}
		else if (!isTop && m_position.getY() <= originY - 100)
		{
			isTop = true;
		}

		if (isTop && m_position.getY() < originY)
		{
			m_velocity.setY(5);
			//player_dRect.y += 3;
		}
		else if (isTop&& m_position.getY() == originY)
		{
			isJumping = false;
			isTop = false;
		}
	}
	SDLGameObject::Update();

}

void HitBox::Clean()
{
}

void HitBox::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		isJumping = true;
	}

}
