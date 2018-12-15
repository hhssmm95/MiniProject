#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed, int numsFrames) 
	: SDLGameObject(pParams), m_animSpeed(animSpeed), m_numFrames(numsFrames)
{
}

void AnimatedGraphic::Update()
{
	m_currentFrame = int(((SDL_GetTicks() /
		(1000 / m_animSpeed)) % m_numFrames));
}
