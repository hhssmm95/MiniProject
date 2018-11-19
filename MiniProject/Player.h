#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
	void handleInput();
	bool isJumping;
	bool isTop;
	int originY;
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};
