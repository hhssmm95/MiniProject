#pragma once
#include "Background.h"
#include "InputHandler.h"
#include"TextureManager.h"
#include"Game.h"
#include<SDL.h>

Background::Background(const LoaderParams* pParams) 
	: SDLGameObject(pParams)
{
	OriginX = pParams->getX();
}
void Background::draw()
{
	//SDLGameObject::draw(); // we now use SDLGameObject
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, TheGame::Instance()->getRenderer());
}
void Background::update()
{
	/*m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));*/
	if (m_position.getX() > (OriginX - 1280))
	{
		m_velocity.setX(-1);
	}
	else
	{
		m_position.setX(OriginX);
	}
	SDLGameObject::update();
	SDL_Delay(10);

}
void Background::clean()
{
}



