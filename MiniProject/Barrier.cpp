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
	if (PlayState::Instance()->getplayTime() >= 30)
		m_velocity.setX(-8);
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