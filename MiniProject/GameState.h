#pragma once
#include <string>
#include <vector>
#include"GameObject.h"
#include"SDLGameObject.h"

class GameState
{
protected:
	std::vector<GameObject*> m_gameObjects;
	std::vector<SDLGameObject*> m_SDLObjects;
	int resetCount = 0;
public:
	virtual void Update();
	virtual void Render();
	virtual bool onEnter() = 0;
	virtual bool onExit();
	virtual std::string getStateID() const = 0;
};
