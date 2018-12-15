#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
private:
	int m_numFrames;
public:
	Enemy(const LoaderParams* pParams, int numsFrames);
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
	void handleInput();
};
