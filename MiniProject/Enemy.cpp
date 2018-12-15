#include "Enemy.h"
#include "InputHandler.h"
#include <SDL.h>
Enemy::Enemy(const LoaderParams* pParams, int numsFrames) : SDLGameObject(pParams), m_numFrames(numsFrames)
{
	//m_velocity.setY(2);
	m_velocity.setX(-5);

}
void Enemy::Draw()
{
	SDLGameObject::Draw(); 
}
void Enemy::Update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	/*if (m_position.getY() < 0) {
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400) {
		m_velocity.setY(-2);
	}*/
	SDLGameObject::Update();

}
void Enemy::Clean()
{
}

void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}
