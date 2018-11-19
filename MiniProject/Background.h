#pragma once
#include "SDLGameObject.h"

class Background : public SDLGameObject
{
private:
	float OriginX;
//	void handleInput();
public:
	Background(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	float GetX();
};
