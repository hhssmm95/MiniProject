#pragma once
#include "SDLGameObject.h"

class HitBox : public SDLGameObject
{
private:
	void handleInput();
	bool isJumping;
	bool isTop;
	int originY;
public:
	HitBox(const LoaderParams* pParams);
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
};
