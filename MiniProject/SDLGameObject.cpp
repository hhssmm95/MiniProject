#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams),
m_position(pParams->getX(), pParams->getY()),
m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 0;
}

void SDLGameObject::Draw()
{
	TextureManager::Instance()->drawFrame(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer());
}

void SDLGameObject::staticDraw()
{
	TextureManager::Instance()->Draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height,TheGame::Instance()->getRenderer());
}

void SDLGameObject::Update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;

}

void SDLGameObject::Clean()
{
}
Vector2D SDLGameObject::getPosition()
{
	return m_position;
}
Vector2D SDLGameObject::getVelocity()
{
	return m_velocity;
}
void SDLGameObject::setVelocity_X(int x)
{
	m_velocity.setX(x);
}
void SDLGameObject::setVelocity_Y(int y)
{
	m_velocity.setY(y);
}

int SDLGameObject::getWidth()
{
	return m_width;
}

int SDLGameObject::getHeight()
{
	return m_height;
}
