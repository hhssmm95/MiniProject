#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include <SDL.h>

class AnimatedGraphic :public SDLGameObject
{
private:
	int m_animSpeed;
	int m_numFrames;
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed, int numsFrames);
	void Update();
};