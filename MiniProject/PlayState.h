#pragma once
#include "GameState.h"
#include "SDLGameObject.h"
#include <SDL.h>
#include<SDL_image.h>

class PlayState : public GameState
{
public:
	virtual void Update();
	virtual void Render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	int getplayTime();
	//bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	int getRandomSpawnTime();
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
	int shotCooltime = 0;
	int spawnCooltime = 200;
	int beginTick;
	int playTime;
	int score = 0;
	bool scoreCheck1 = false;
	bool scoreCheck2 = false;
	bool fireOn = false;
	PlayState(){}
	~PlayState(){}
	std::vector<GameObject*> bullets;
	SDL_Texture* text;
	SDL_Rect textRect;
};