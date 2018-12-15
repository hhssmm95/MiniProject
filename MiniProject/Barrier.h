#pragma once
#include "SDLGameObject.h"

class Barrier : public SDLGameObject
{

public:
	Barrier(const LoaderParams* pParams);
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
};
