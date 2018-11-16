#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include<vector>

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{


public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D*getMousePosition();
	void onMouseMove(SDL_Event);
	void onMouseButtonDown(SDL_Event);
	void onMouseButtonUp(SDL_Event);
	void onKeyDown();
	void onKeyUp();

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
	const Uint8* m_keystates;
	Vector2D* m_mousePosition;
	std::vector<bool> m_mouseButtonStates;
};


typedef InputHandler TheInputHandler;
