#pragma once
#include "SDLGameObject.h"

class Background : public SDLGameObject
{
private:
	float OriginX;
//	void handleInput();
public:
	Background(const LoaderParams* pParams);
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
	float GetX();
};
