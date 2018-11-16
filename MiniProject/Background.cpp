#include "Background.h"
#include "InputHandler.h"
#include<SDL.h>

Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Background::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Background::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();

}
void Background::clean()
{
}


