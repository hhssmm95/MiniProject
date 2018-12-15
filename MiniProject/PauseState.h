#pragma once
#include"GameState.h"

class PauseState : public GameState
{
public:
	virtual void Update();
	virtual void Render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
	//std::vector<GameObject*> m_gameObjects;
};
