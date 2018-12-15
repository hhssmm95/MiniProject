#pragma once
#include "SDLGameObject.h"

enum button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};


class MenuButton : public SDLGameObject
{
private:
	void(*m_callback)();

	bool m_bReleased;

public:
	MenuButton(const LoaderParams* pParams, void(*callback)());
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
};
