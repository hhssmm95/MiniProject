#pragma once
#include "Background.h"
#include "InputHandler.h"
#include"TextureManager.h"
#include"Game.h"
#include"PlayState.h"
#include<SDL.h>

Background::Background(const LoaderParams* pParams) 
	: SDLGameObject(pParams)
{
	OriginX = pParams->getX();
	m_velocity.setX(-4);
}
void Background::Draw()
{
	//SDLGameObject::Draw(); // we now use SDLGameObject
	TextureManager::Instance()->Draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, TheGame::Instance()->getRenderer());
}
void Background::Update()
{
	/*m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));*/
	if (m_position.getX() <= (OriginX - 640))
	{
		m_position.setX(OriginX);
		
	}

	if (PlayState::Instance()->getplayTime() >= 30)
		m_velocity.setX(-8);
	SDLGameObject::Update();

}
void Background::Clean()
{
}



