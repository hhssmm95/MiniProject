#pragma once
#include <string>
#include <vector>
#include"GameObject.h"

class GameState
{
protected:
	std::vector<GameObject*> m_gameObjects;
public:
	virtual void Update();
	virtual void Render();
	virtual bool onEnter() = 0;
	virtual bool onExit();
	virtual std::string getStateID() const = 0;
};
