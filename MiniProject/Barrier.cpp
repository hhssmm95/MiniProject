#include "Barrier.h"
#include"TextureManager.h"
#include"Game.h"
#include"PlayState.h"
Barrier::Barrier(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(-4);
}

void Barrier::Update()
{
	if (PlayState::Instance()->getplayTime() >= 30 && PlayState::Instance()->getplayTime() < 60)
		m_velocity.setX(-8);
	else if (PlayState::Instance()->getplayTime() >= 60)
		m_velocity.setX(-12);
	SDLGameObject::Update();
}

void Barrier::Draw()
{
	TextureManager::Instance()->Draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height,TheGame::Instance()->getRenderer());
}

void Barrier::Clean()
{
	SDLGameObject::Clean();
}
int Barrier::getWidth()
{
	return SDLGameObject::getWidth();
}
int Barrier::getX()
{
	return SDLGameObject::getX();
}