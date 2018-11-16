#include<SDL.h>
#include"Player.h"
#include<vector>
class Game
{
private:
	static Game* s_pInstance;

	int m_currentFrame;

	Player* player;

	std::vector<GameObject*> m_gameObjects;
	Game() {}
	~Game() {}
	SDL_Window* window;
	SDL_Renderer* renderer;
	/*
	SDL_Rect player_sRect;
	SDL_Rect player_dRect;
	SDL_Rect bg1_sRect;
	SDL_Rect bg1_dRect;
	SDL_Rect bg2_sRect;
	SDL_Rect bg2_dRect;
	SDL_Texture* playerTexture;
	SDL_Texture* bgTexture1;
	SDL_Texture* bgTexture2;*/
	bool isRunning;
	


public:
	SDL_Renderer * getRenderer() const { return renderer; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	void quit();
	bool isJumping = false;
	bool isTop = false;
	int tempY;

	bool Init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void Render();
	void Update();
	void HandleEvents();
	void Clean();
	bool Running() {
		return isRunning;
	}

};